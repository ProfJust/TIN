#include "QtSnake.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtSnake w;
	w.show();
	return a.exec();
}
