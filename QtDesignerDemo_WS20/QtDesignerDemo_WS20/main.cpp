#include "QtDesignerDemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtDesignerDemo w;
    w.show();
    return a.exec();
}
