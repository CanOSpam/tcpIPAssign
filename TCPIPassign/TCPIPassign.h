#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TCPIPassign.h"

class TCPIPassign : public QMainWindow
{
	Q_OBJECT

public:
	TCPIPassign(QWidget *parent = Q_NULLPTR);

private:
	Ui::TCPIPassignClass ui;
};
