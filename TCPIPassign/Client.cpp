/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: Client.cpp - A window that manages sending data over TCP and UDP
--
-- PROGRAM: TCPIPassign
--
-- FUNCTIONS:
-- void pickAFile (void)
-- void initUdpSocket (void)
-- void sendFile (void)
-- int fileSize (char* filename)
-- void connected (void)
--
-- DATE: February 13, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- NOTES:
-- The program initializes a UDP or TCP server. If a UDP server, it waits for the user to click send data, then
-- send the data to the waiting receiver. If a TCP server is started, the server waits for a connection, then sends
-- the data to the receiver.
----------------------------------------------------------------------------------------------------------------------*/

#include "Client.h"

Client::Client(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Client)
{
	ui->setupUi(this);

	filePicked = false;

	connect(ui->pickFileButton, &QPushButton::clicked, this, &Client::pickAFile);
	connect(ui->sendButton, &QPushButton::clicked, this, &Client::sendFile);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: pickAFile
--
-- DATE: February 13, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void pickAFile (void)
--
-- RETURNS: void.
--
-- NOTES:
-- Call this function to use the QFileDialog static function to get a file location to write data from.
----------------------------------------------------------------------------------------------------------------------*/
void Client::pickAFile()
{
	fileName = QFileDialog::getOpenFileName(this, tr("Open"),
		"",
		tr("Text data (*.txt)"));
	filePicked = true;
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: initUdpSocket
--
-- DATE: February 13, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void initUdpSocket (void)
--
-- RETURNS: void.
--
-- NOTES:
-- Call this function to create a new QUdpSocket. This function will also bind the socket.
----------------------------------------------------------------------------------------------------------------------*/
void Client::initUdpSocket()
{
	udpSocket = new QUdpSocket(this);
	udpSocket->bind(QHostAddress::Any, ui->portEdit->text().toInt());
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: sendFile
--
-- DATE: February 13, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void sendFile (void)
--
-- RETURNS: void.
--
-- NOTES:
-- sendFile is the meat of the sender program. it first ensures that a sending file has been chosen, then opens either TCP
-- or UDP mode. In both modes a timer runs as data is tranferred. In UDP mode a progress bar is also displayed showing the
-- file transfer progress. UDP mode sends data dumbly when it is commanded to by the user, while TCP mode waits for an inbound
-- connection and transfers data to any newly connected receiver.
----------------------------------------------------------------------------------------------------------------------*/
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

			std::clock_t c_start = std::clock();
			auto t_start = std::chrono::high_resolution_clock::now();


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

			std::clock_t c_end = std::clock();
			auto t_end = std::chrono::high_resolution_clock::now();


			double tempTime = std::chrono::duration<double, std::milli>(t_end - t_start).count();
			QString tempStr("sent, took: " + QString::number(tempTime) + " ms");
			this->setWindowTitle(tempStr);

			ui->sendProgress->setValue(100);
			inputFile.close();
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

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: fileSize
--
-- DATE: February 13, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Spyros
--
-- PROGRAMMER: Spyros, tmanthey, Tim Bruecker
--
-- INTERFACE: int fileSize (const char* filename)
--
-- PARAMS: filename - A file to measure the size of.
--
-- RETURNS: filesize - Size of the file in bytes.
--
-- NOTES:
-- Call this function to measure the size of a file in bytes. 
-- Code from: https://stackoverflow.com/questions/5840148/how-can-i-get-a-files-size-in-c
----------------------------------------------------------------------------------------------------------------------*/
int Client::filesize(const char* filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}



/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: connected
--
-- DATE: February 13, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void connected (void)
--
-- RETURNS: void.
--
-- NOTES:
-- This function is called by a signal whenever a new TCP connection is established. The function sends all the data
-- to the receiver, and times the amount of time it took to put the data on the stream.
----------------------------------------------------------------------------------------------------------------------*/
void Client::connected()
{
	// need to grab the socket
	QTcpSocket *clientConnection = server->nextPendingConnection();

	float bufferSize = ui->bytesPerPacketEdit->text().toInt();
	std::ifstream inputFile;
	inputFile.open(fileName.toStdString());

	std::clock_t c_start = std::clock();
	auto t_start = std::chrono::high_resolution_clock::now();
	
	while (inputFile.good())
	{
		char * sendBuffer = new char[bufferSize];
		memset(sendBuffer, '\0', bufferSize);
		inputFile.read(sendBuffer, bufferSize - 1);

		for (int i = 0; i < ui->numPacketsEdit->text().toInt(); i++)
		{
			clientConnection->write(sendBuffer);
		}
		delete sendBuffer;
	}

	std::clock_t c_end = std::clock();
	auto t_end = std::chrono::high_resolution_clock::now();


	double tempTime = std::chrono::duration<double, std::milli>(t_end - t_start).count();
	QString tempStr("sent, took: " + QString::number(tempTime) + " ms");
	this->setWindowTitle(tempStr);

	clientConnection->disconnectFromHost();
	inputFile.close();
}