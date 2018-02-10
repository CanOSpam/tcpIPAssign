#include "Server.h"

//The server receives data

Server::Server(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Server)
{
	ui->setupUi(this);


	udpSocketExists = false;

	connect(ui->pickFileButton, &QPushButton::clicked, this, &Server::pickAFile);
	connect(ui->startButton, &QPushButton::clicked, this, &Server::startListening);
	connect(ui->stopButton, &QPushButton::clicked, this, &Server::stopListening);
}




void Server::pickAFile()
{
	fileName = QFileDialog::getSaveFileName(this, tr("Save Where?"),
		"",
		tr("Text data (*.txt)"));

}


void Server::initSocket()
{
	udpSocket = new QUdpSocket(this);
	udpSocket->bind(QHostAddress(ui->ipEdit->text()), ui->portEdit->text().toInt());

	udpSocket->writeDatagram("test", 5, QHostAddress(ui->ipEdit->text()), ui->portEdit->text().toInt());
}



void Server::readPendingDatagrams()
{
	while (udpSocket->hasPendingDatagrams()) {
		char temp[5];
		udpSocket->readDatagram(temp, 5);

		QMessageBox msgBox;
		msgBox.setText(temp);
		msgBox.setWindowTitle("Sending Done");
		msgBox.exec();
	}
}

void Server::startListening()
{
	if (!udpSocketExists)
	{
		initSocket();

		connect(udpSocket, &QUdpSocket::readyRead,
			this, &Server::readPendingDatagrams);

		udpSocketExists = true;
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
}