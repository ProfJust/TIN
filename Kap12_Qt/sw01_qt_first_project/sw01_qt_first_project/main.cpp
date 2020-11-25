#include "sw01_qt_first_project.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	sw01_qt_first_project w;
	w.show();
	return a.exec();
}
