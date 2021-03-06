#pragma once

#include <QWidget>
#include <QFileDialog>
#include <QtNetwork>
#include <QDebug>

#include <fstream>
#include <thread> 

#include <QMessageBox>

#include "ui_Server.h"

class Server : public QWidget
{
	Q_OBJECT

public:
	explicit Server(QWidget *parent = 0);

public slots:
	void readPendingDatagrams();
	void startListening();
	void stopListening();
	void parseTcp();

private:
	Ui::Server *ui;
	QString fileName;
	QUdpSocket *udpSocket;
	bool udpSocketExists;
	bool filePicked;
	QTcpSocket *tcpSocket;
	std::ofstream inputFile;

	void pickAFile();
	void initUdpSocket();
};