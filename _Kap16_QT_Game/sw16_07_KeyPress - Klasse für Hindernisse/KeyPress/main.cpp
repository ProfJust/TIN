#include "KeyPress.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KeyPress w;
	w.show();
	return a.exec();
}
