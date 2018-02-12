#include "Server.h"

//The server receives data

Server::Server(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Server)
{
	ui->setupUi(this);


	udpSocketExists = false;
	filePicked = false;

	connect(ui->pickFileButton, &QPushButton::clicked, this, &Server::pickAFile);
	connect(ui->startButton, &QPushButton::clicked, this, &Server::startListening);
	connect(ui->stopButton, &QPushButton::clicked, this, &Server::stopListening);
}




void Server::pickAFile()
{
	fileName = QFileDialog::getSaveFileName(this, tr("Save Where?"),
		"",
		tr("Text data (*.txt)"));
	filePicked = true;
}


void Server::initUdpSocket()
{
	udpSocket = new QUdpSocket(this);
	udpSocket->bind(QHostAddress::Any, ui->portEdit->text().toInt());
}



void Server::readPendingDatagrams()
{
	
	std::ofstream inputFile;
	inputFile.open(fileName.toStdString(), std::ios_base::app);

	if (inputFile.is_open())
	{
		while (udpSocket->hasPendingDatagrams()) {
			int incomingSize = udpSocket->pendingDatagramSize();
			char* inputBuffer = new char[incomingSize];

			udpSocket->readDatagram(inputBuffer,incomingSize);

			//WRITE TO FILE
			inputFile << inputBuffer;

			delete inputBuffer;
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.setText("Error opening file.");
		msgBox.setWindowTitle("FILE ERROR");
		msgBox.exec();
	}
	inputFile.close();
}

void Server::startListening()
{
	if (filePicked)
	{
		if (!udpSocketExists)
		{
			initUdpSocket();




			connect(udpSocket, &QUdpSocket::readyRead,
				this, &Server::readPendingDatagrams);

			udpSocketExists = true;
		}
		this->setWindowTitle("Server - Listening");
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

void Server::stopListening()
{
	if (udpSocketExists)
	{
		disconnect(udpSocket, &QUdpSocket::readyRead,
			this, &Server::readPendingDatagrams);

		delete udpSocket;
		udpSocketExists = false;

		this->setWindowTitle("Server");
	}
}