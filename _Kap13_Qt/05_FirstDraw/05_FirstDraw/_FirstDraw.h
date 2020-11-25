#pragma once

#include <QtWidgets/QMainWindow>
#include "ui__FirstDraw.h"
#include <QPainter>
#include <QStaticText>
#include <QFont>

class _FirstDraw : public QMainWindow
{
	Q_OBJECT

public:
	_FirstDraw(QWidget *parent = Q_NULLPTR);
	QPainter* p;  //Instanz von Painter erstellen
	void _FirstDraw::paintEvent(QPaintEvent *e);
	void _FirstDraw::zeichne();
	
private:
	Ui::_FirstDrawClass ui;
};
