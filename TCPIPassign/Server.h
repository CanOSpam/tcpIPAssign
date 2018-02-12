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

private:
	Ui::Server *ui;
	QString fileName;
	QUdpSocket *udpSocket;
	bool udpSocketExists;
	bool filePicked;

	void pickAFile();
	void initUdpSocket();
	void readPendingDatagrams();
	void startListening();
	void stopListening();
};