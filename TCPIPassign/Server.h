#pragma once

#include <QWidget>
#include <QFileDialog>
#include <QtNetwork>
#include <QDebug>

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

	void pickAFile();
	void initSocket();
	void readPendingDatagrams();
	void startListening();
	void stopListening();
};