#include "Client.h"

//The Client sends data

/*
//TEMPORARY INCLUDES FOR PROGRESS BAR TESTING
#include <thread>
#include <chrono>

//USE THIS FOR PROGRESS BAR
for (int i = 0; i <= 100; i++)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	ui->sendProgress->setValue(i);

	if (i == 50)
	{
		//THIS PAUSES THE PROGRESS (halts thread until msgbox closed)
		QMessageBox msgBox;
		msgBox.setText("Click OK to continue.");
		msgBox.setWindowTitle("Sending Done");
		msgBox.exec();
	}
}
*/
Client::Client(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Client)
{
	ui->setupUi(this);

	connect(ui->pickFileButton, &QPushButton::clicked, this, &Client::pickAFile);
}

void Client::pickAFile()
{
	

	fileName = QFileDialog::getOpenFileName(this, tr("Open"),
		"",
		tr("Text data (*.txt)"));
}