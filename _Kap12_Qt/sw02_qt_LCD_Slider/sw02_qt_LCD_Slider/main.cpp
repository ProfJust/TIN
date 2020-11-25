#include "sw02_qt_LCD_Slider.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	sw02_qt_LCD_Slider w;
	w.show();
	return a.exec();
}
