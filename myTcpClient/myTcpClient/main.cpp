#include "myTcpClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	myTcpClient w;
	w.show();
	return a.exec();
}
