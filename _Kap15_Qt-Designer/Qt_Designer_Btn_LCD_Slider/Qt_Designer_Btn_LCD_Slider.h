#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_Designer_Btn_LCD_Slider.h"

class Qt_Designer_Btn_LCD_Slider : public QMainWindow
{
	Q_OBJECT

public:
	Qt_Designer_Btn_LCD_Slider(QWidget *parent = Q_NULLPTR);

private slots:
	//--- Deklaration der Slots ----
	void myMinusSlot();
	void myPlusSlot();

private:
	Ui::Qt_Designer_Btn_LCD_SliderClass ui;
};
