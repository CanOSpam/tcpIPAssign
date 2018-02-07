#pragma once

#include <QWidget>
#include <QFileDialog>

#include "ui_Server.h"

class Server : public QWidget
{
	Q_OBJECT

public:
	explicit Server(QWidget *parent = 0);

private:
	Ui::Server *ui;
	QString fileName;


	void pickAFile();
};