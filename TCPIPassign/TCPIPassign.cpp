#include "TCPIPassign.h"

TCPIPassign::TCPIPassign(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.startServerButton, &QPushButton::clicked, this, &TCPIPassign::startExternal);
}


void TCPIPassign::startExternal()
{
	if (ui.hostSelectCombo->currentText() == "Client")
	{
		clientWindow = new Client();
		clientWindow->show();
	}
	else
	{
		serverWindow = new Server();
		serverWindow->show();
	}
}
