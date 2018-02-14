/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: Server.cpp - A window that manages receiving data over TCP and UDP
--
-- PROGRAM: TCPIPassign
--
-- FUNCTIONS:
-- void pickAFile (void)
-- void initUdpSocket (void)
-- void readPendingDatagrams (void)
-- void startListening (void)
-- void startListening (void)
-- void stopListening (void)
-- void parseTcp (void)
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
-- The program wait for either a TCP or UDP connection and receive data from that connection. TCP and UDP are handled
-- seperately, but all data is written to a file specified by the user.
----------------------------------------------------------------------------------------------------------------------*/
#include "Server.h"

Server::Server(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Server)
{
	ui->setupUi(this);

	tcpSocket = new QTcpSocket(this);

	udpSocketExists = false;
	filePicked = false;

	connect(ui->pickFileButton, &QPushButton::clicked, this, &Server::pickAFile);
	connect(ui->startButton, &QPushButton::clicked, this, &Server::startListening);
	connect(ui->stopButton, &QPushButton::clicked, this, &Server::stopListening);
	connect(tcpSocket, &QIODevice::readyRead, this, &Server::parseTcp);
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
-- Call this function to use the QFileDialog static function to get a file location to save data to. If the file
-- already exists, it is cleared of data.
----------------------------------------------------------------------------------------------------------------------*/
void Server::pickAFile()
{
	fileName = QFileDialog::getSaveFileName(this, tr("Save Where?"),
		"",
		tr("Text data (*.txt)"));
	filePicked = true;

	std::ofstream clearer;
	clearer.open(fileName.toStdString(), std::ofstream::out | std::ofstream::trunc);
	clearer.close();

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
-- Call this function to create a new QUdpSocket. This function will also bind the socket, and open the previously
-- specified save file.
----------------------------------------------------------------------------------------------------------------------*/
void Server::initUdpSocket()
{
	udpSocket = new QUdpSocket(this);
	udpSocket->bind(QHostAddress::Any, ui->portEdit->text().toInt());

	inputFile.open(fileName.toStdString(), std::ios_base::app);
}


/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: readPendingDatagrams
--
-- DATE: February 13, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void readPendingDatagrams (void)
--
-- RETURNS: void.
--
-- NOTES:
-- This function reads incoming UDP datagrams on the UDP connection and saves them to a file.
----------------------------------------------------------------------------------------------------------------------*/
void Server::readPendingDatagrams()
{
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
	
}


/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: startListening
--
-- DATE: February 13, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void startListening (void)
--
-- RETURNS: void.
--
-- NOTES:
-- This function enables UDP listening by connecting the signal to the readPendingDatagrams function. If the combobox
-- is set to select TCP, this function connects to the TCP server, triggering the TCP server to transmit data.
----------------------------------------------------------------------------------------------------------------------*/
void Server::startListening()
{
	if (filePicked)
	{
		//Enable UDP listening
		if (!udpSocketExists && ui->tcpUdpComboBox->currentText() == "UDP")
		{
			initUdpSocket();

			connect(udpSocket, &QUdpSocket::readyRead,
				this, &Server::readPendingDatagrams);

			udpSocketExists = true;
			this->setWindowTitle("Server - Listening - UDP");
		}
		//Enable TCP listening
		else if (ui->tcpUdpComboBox->currentText() == "TCP")
		{
			
			tcpSocket->connectToHost(ui->ipEdit->text(), ui->portEdit->text().toInt());
			
			qDebug() << "connected to host";
			qDebug() << tcpSocket->isOpen();
		}
	}
	else
	{
		this->setWindowTitle("Server - Listening - TCP");
	}
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: stopListening
--
-- DATE: February 13, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void stopListening (void)
--
-- RETURNS: void.
--
-- NOTES:
-- This function closes a started UDP listener. This is not required for TCP as the connection is automatically closed
-- when no new data is received.
----------------------------------------------------------------------------------------------------------------------*/
void Server::stopListening()
{
	if (udpSocketExists)
	{
		disconnect(udpSocket, &QUdpSocket::readyRead,
			this, &Server::readPendingDatagrams);

		delete udpSocket;
		udpSocketExists = false;
	}
	if (inputFile.is_open())
	{
		inputFile.close();
	}
	
	this->setWindowTitle("Server");
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: parseTcp
--
-- DATE: February 13, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void parseTcp (void)
--
-- RETURNS: void.
--
-- NOTES:
-- This function reads a tcp stream and writes that data to file.
----------------------------------------------------------------------------------------------------------------------*/
void Server::parseTcp()
{
	inputFile.open(fileName.toStdString(), std::ios_base::app);
	if (inputFile.is_open())
	{
		inputFile << tcpSocket->readAll().toStdString();
	}
	inputFile.close();
}