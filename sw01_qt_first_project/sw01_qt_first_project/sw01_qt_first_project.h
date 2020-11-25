#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_sw01_qt_first_project.h"


//-------------- Definition der Klasse -----------
//--- Ein Button ----
#include <QPushButton> //Qt5 => nicht mehr <qpushbutton.h>

class sw01_qt_first_project : public QMainWindow
{
	Q_OBJECT

public:
	sw01_qt_first_project(QWidget *parent = Q_NULLPTR);

private:
	Ui::sw01_qt_first_projectClass ui;
	QPushButton *myButton;

private slots:
	void myButtonSlotFkt();

};
