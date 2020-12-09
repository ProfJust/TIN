#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtDesignerDemo.h"
#include <QDebug>

class QtDesignerDemo : public QMainWindow
{
    Q_OBJECT

public:
    QtDesignerDemo(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtDesignerDemoClass ui;

private slots:
    void slotPlus();
    void slotMinus();

};
