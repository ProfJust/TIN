#pragma once
#include <QtWidgets/QMainWindow>
#include <QObject>
#include "ui_sw02_qt_LCD_Slider.h"
//---- DIE WIDGETS ----------
//--- Ein Label -----
#include <QLabel> 
//--- Ein Button ----
#include <QPushButton>
//--- Ein Schieber ---
#include <QSlider>
#include "mySliderClass.h"
//---- eine LCD-Anzeige ---
#include <QLCDNumber>
//---- Eine Pixmap für ein Bild --
#include <QPixmap>

//---- Deklaration der Klasse ------
class sw02_qt_LCD_Slider : public QMainWindow
{
	Q_OBJECT

public:
	sw02_qt_LCD_Slider(QWidget *parent = Q_NULLPTR);

private:
	Ui::sw02_qt_LCD_SliderClass ui;
};
