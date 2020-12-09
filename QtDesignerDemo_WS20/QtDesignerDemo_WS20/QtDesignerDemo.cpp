#include "QtDesignerDemo.h"

QtDesignerDemo::QtDesignerDemo(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void QtDesignerDemo::slotPlus() {
   qDebug("Plus");

}

void QtDesignerDemo::slotMinus() {
    qDebug("Minus");

}