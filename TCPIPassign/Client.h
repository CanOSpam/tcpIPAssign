#pragma once

#include <QWidget>
#include <QFileDialog>
#include <QtNetwork>

#include <fstream>

#include <QMessageBox>

#include "ui_Client.h"

class Client : public QWidget
{
	Q_OBJECT

public:
	explicit Client(QWidget *parent = 0);

public slots:
	void connected();

private:
	Ui::Client *ui;
	QString fileName;
	QUdpSocket *udpSocket;
	QTcpServer *server;
	bool filePicked;


	void pickAFile();
	void initUdpSocket();
	void sendFile();
	int filesize(const char * filename);
};