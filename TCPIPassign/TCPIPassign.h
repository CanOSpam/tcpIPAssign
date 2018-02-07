#pragma once

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QComboBox>

#include "Server.h"
#include "Client.h"
#include "ui_TCPIPassign.h"


#include <QDebug>

class TCPIPassign : public QMainWindow
{
	Q_OBJECT

public:
	TCPIPassign(QWidget *parent = Q_NULLPTR);

private:
	Ui::TCPIPassignClass ui;
	void startExternal();
	Client *clientWindow;
	Server *serverWindow;
};
