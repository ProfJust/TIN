#pragma once

#include <QtWidgets/QMainWindow>
#include "ui__FirstDraw.h"
#include <QPainter>
#include <QStaticText>
#include <QFont>
#include <QTimer>
#include <QDebug>

class _FirstDraw : public QMainWindow
{
	Q_OBJECT

public:
	_FirstDraw(QWidget *parent = Q_NULLPTR);
	QPainter p;  //Instanz von Painter erstellen
	void _FirstDraw::paintEvent(QPaintEvent *e);
	void _FirstDraw::zeichne();
	int pos_x = 0, pos_y = 0;

	QTimer *timer; // Pointer/Handle für den Timer

public slots:
	void MyTimerSlot(); //vom Timer aufgerufene Funktion

private:
	Ui::_FirstDrawClass ui;
};
