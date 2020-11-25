#include "myTicTacToe_V4.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	myTicTacToe_V4 w;
	w.show();
	return a.exec();
}
