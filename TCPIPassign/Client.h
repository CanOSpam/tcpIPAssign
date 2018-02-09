#pragma once

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QUdpSocket>

#include "ui_Client.h"

class Client : public QWidget
{
	Q_OBJECT

public:
	explicit Client(QWidget *parent = 0);

private:
	Ui::Client *ui;
	QString fileName;
	QUdpSocket *udpSocket;


	void pickAFile();
};