#include "Server.h"

//The server receives data

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


void Server::initUdpSocket()
{
	udpSocket = new QUdpSocket(this);
	udpSocket->bind(QHostAddress::Any, ui->portEdit->text().toInt());

	inputFile.open(fileName.toStdString(), std::ios_base::app);
}



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
			
			tcpSocket->connectToHost(QHostAddress::Any, ui->portEdit->text().toInt());
			
			qDebug() << "connected to host";
			qDebug() << tcpSocket->isOpen();
		}
	}
	else
	{
		this->setWindowTitle("Server - Listening - TCP");
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
	}
	if (inputFile.is_open())
	{
		inputFile.close();
	}
	
	this->setWindowTitle("Server");
}

void Server::parseTcp()
{
	qDebug() << "------";
	qDebug() << tcpSocket->readAll();
	qDebug() << "------";
}
