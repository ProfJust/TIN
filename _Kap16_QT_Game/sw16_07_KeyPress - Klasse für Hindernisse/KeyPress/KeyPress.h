//--- KeyPress.h ---
#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_KeyPress.h"
#include <QLabel>
#include <QKeyEvent>
#include <QPainter>   
#include <QTimer> 
//--Fenstergröße ---
#define WINDOW_SIZE_X 1000
#define WINDOW_SIZE_Y 1000
#define BALL_SIZE 20
#define SCHLAEGER_BREITE WINDOW_SIZE_X/8
#define SCHLAEGER_HOEHE 20
#define X_SPEED WINDOW_SIZE_X/20  //Schlägergeschwindigkeit
#define HIND_SPALTEN 8  //Anzahl der Hindernisse nebeneinander



enum state { sichtbar, unsichtbar };

class clHindernis {
public:
	//--- Konstruktor ---
	clHindernis(int _x, int _y, int _w, int _h) {
		x = _x;
		y = _y;
		w = _w;
		h = _h;
		st = sichtbar;
	}
	int x;
	int y;
	int w;
	int h;
	state st;
};



class KeyPress : public QMainWindow
{
	Q_OBJECT

public:
	KeyPress(QWidget *parent = Q_NULLPTR);

private:
	Ui::KeyPressClass ui;
	QLabel *myLabel;
public:
	void keyPressEvent(QKeyEvent *);
	void paintEvent(QPaintEvent *);  
	
	int pos_x = 250;  //Position Schläger 
	int ball_x = 250; //Position Ball
	int ball_y = 400;
	int speed_x =  2; //Geschw. Ball
	int speed_y = -2;

	
	clHindernis * hi[HIND_SPALTEN];

	QTimer *myTimer; //(2)
public slots:
	void myTimerSlot(); //(3)
	
};
