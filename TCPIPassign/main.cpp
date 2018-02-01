#include "TCPIPassign.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TCPIPassign w;
	w.show();
	return a.exec();
}
