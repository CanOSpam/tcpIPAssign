#include "Server.h"

//The server receives data

Server::Server(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Server)
{
	ui->setupUi(this);

	connect(ui->pickFileButton, &QPushButton::clicked, this, &Server::pickAFile);
}


void Server::pickAFile()
{
	fileName = QFileDialog::getSaveFileName(this, tr("Save Where?"),
		"",
		tr("Text data (*.txt)"));
}