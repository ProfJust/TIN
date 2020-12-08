#include "MyTimer.h"
#include "primegame_maingui.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PrimeGame_MainGUI w;
	MyTimer timer;
	timer.getApplication(&w);
	w.show();
	return a.exec();
}
