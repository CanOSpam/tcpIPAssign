/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: TCPIPassign.cpp - A window that can start senders and receivers
--
-- PROGRAM: TCPIPassign
--
-- FUNCTIONS:
-- void startExternal (void)
--
-- DATE: February 13, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- NOTES:
-- The program wait for either a TCP or UDP connection and receive data from that connection. TCP and UDP are handled
-- seperately, but all data is written to a file specified by the user.
----------------------------------------------------------------------------------------------------------------------*/

#include "TCPIPassign.h"

TCPIPassign::TCPIPassign(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.startServerButton, &QPushButton::clicked, this, &TCPIPassign::startExternal);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: startExternal
--
-- DATE: February 13, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker
--
-- PROGRAMMER: Tim Bruecker
--
-- INTERFACE: void statExternal (void)
--
-- RETURNS: void.
--
-- NOTES:
-- Depending on the selection, this will either start a listener (Server.cpp) or a sender (Client.cpp).
----------------------------------------------------------------------------------------------------------------------*/
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
