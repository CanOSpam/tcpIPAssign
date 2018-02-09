#include "Server.h"

//The server receives data

Server::Server(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Server)
{
	ui->setupUi(this);

	connect(ui->pickFileButton, &QPushButton::clicked, this, &Server::pickAFile);
	initSocket();
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
	udpSocket->bind(QHostAddress::LocalHost, 7755);

	connect(udpSocket, &QUdpSocket::readyRead,
		this,&Server::readPendingDatagrams);


	udpSocket->write("test");
}

void Server::readPendingDatagrams()
{
	while (udpSocket->hasPendingDatagrams()) {
		QByteArray temp = udpSocket->readAll();
		qDebug() << temp;
	}
}