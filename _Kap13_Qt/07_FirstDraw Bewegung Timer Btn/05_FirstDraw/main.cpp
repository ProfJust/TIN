#include "_FirstMove.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	_FirstDraw w;
	w.show();
	return a.exec();
}
