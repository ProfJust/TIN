#include "RoboSpeech.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RoboSpeech w;
    w.show();
    return a.exec();
}
