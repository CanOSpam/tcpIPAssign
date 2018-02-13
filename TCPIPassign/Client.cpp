#include "Client.h"


#include <QDebug>
//The Client sends data

/*
//TEMPORARY INCLUDES FOR PROGRESS BAR TESTING
#include <thread>
#include <chrono>

//USE THIS FOR PROGRESS BAR
for (int i = 0; i <= 100; i++)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	ui->sendProgress->setValue(i);

	if (i == 50)
	{
		//THIS PAUSES THE PROGRESS (halts thread until msgbox closed)
		QMessageBox msgBox;
		msgBox.setText("Click OK to continue.");
		msgBox.setWindowTitle("Sending Done");
		msgBox.exec();
	}
}
*/
Client::Client(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Client)
{
	ui->setupUi(this);

	filePicked = false;

	connect(ui->pickFileButton, &QPushButton::clicked, this, &Client::pickAFile);
	connect(ui->sendButton, &QPushButton::clicked, this, &Client::sendFile);
}

void Client::pickAFile()
{
	fileName = QFileDialog::getOpenFileName(this, tr("Open"),
		"",
		tr("Text data (*.txt)"));
	filePicked = true;
}

void Client::initUdpSocket()
{
	udpSocket = new QUdpSocket(this);
	udpSocket->bind(QHostAddress::Any, ui->portEdit->text().toInt());
}

void Client::sendFile()
{
	if (filePicked)
	{
		if (ui->tcpUdpComboBox->currentText() == "UDP")
		{
			initUdpSocket();
			ui->sendProgress->setValue(0);

			std::ifstream inputFile;
			inputFile.open(fileName.toStdString());
			float bufferSize = ui->bytesPerPacketEdit->text().toInt();
			float fileSize = filesize(fileName.toStdString().c_str());
			fileSize *= ui->numPacketsEdit->text().toInt();

			int dataSent = 0;


			while (inputFile.good())
			{
				char * sendBuffer = new char[bufferSize];
				memset(sendBuffer, '\0', bufferSize);
				inputFile.read(sendBuffer, bufferSize - 1);

				for (int i = 0; i < ui->numPacketsEdit->text().toInt(); i++)
				{
					udpSocket->writeDatagram(sendBuffer, bufferSize, QHostAddress(ui->ipEdit->text()), ui->portEdit->text().toInt());
					dataSent += bufferSize - 1;
					ui->sendProgress->setValue((dataSent / fileSize) * 100);
				}

				delete sendBuffer;
			}

			ui->sendProgress->setValue(100);
			delete udpSocket;
		}
		else if(ui->tcpUdpComboBox->currentText() == "TCP")
		{
			server = new QTcpServer(this);
			ui->bytesPerPacketEdit->setDisabled(true);
			ui->numPacketsEdit->setDisabled(true);
			ui->ipEdit->setDisabled(true);
			ui->portEdit->setDisabled(true);
			ui->pickFileButton->setDisabled(true);
			ui->sendButton->setDisabled(true);
			ui->sendProgress->setDisabled(true);
			this->setWindowTitle("multi-client TCP Serving mode");

			connect(server, &QTcpServer::newConnection, this, &Client::connected);

			if (!server->listen(QHostAddress::Any, ui->portEdit->text().toInt()))
			{
				QMessageBox msgBox;
				msgBox.setIcon(QMessageBox::Warning);
				msgBox.setText(server->errorString());
				msgBox.setWindowTitle("Warning");
				msgBox.exec();
			}
			else
			{
				QMessageBox msgBox;
				msgBox.setIcon(QMessageBox::Information);
				msgBox.setText("Multi-client TCP serving mode started");
				msgBox.setWindowTitle("Server Notification");
				msgBox.exec();
			}
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setText("Pick a file to save to first.");
		msgBox.setWindowTitle("Warning");
		msgBox.exec();
	}
	
}

//From https://stackoverflow.com/questions/5840148/how-can-i-get-a-files-size-in-c
//Author: Spyros, Editor: tmanthey
int Client::filesize(const char* filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}

void Client::connected()
{
	// need to grab the socket
	QTcpSocket *socket = server->nextPendingConnection();

	socket->write("Hello client\r\n");
	socket->flush();

	socket->waitForBytesWritten(3000);

	socket->close();
}