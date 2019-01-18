//---------- QTSnake.h ----------
#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtSnake.h"
#include <QPainter>
#include <QPushButton>
#include <QStaticText>
#include <QFont>
#include <QTimer>
#include <QLabel>
#include <QKeyEvent>
#include <Windows.h>
#include <QSound>

#define WINDOWSIZE_X 800
#define WINDOWSIZE_Y 800
#define START_X 120
#define START_Y 120
#define SN_EL_SIZE 40  //Größe Element der Schlange 800/20 = 40 
#define TIMER_INTERVALL 300

enum Dir { LEFT, RIGHT, UP, DOWN };
enum GameOverTyp { UNTEN, OBEN, RECHTS, LINKS, SELBST };

class SnakeGlied {
public:
	//--- Konstruktoren ---
	SnakeGlied() {} //default
	SnakeGlied(int _x, int _y) { //mit Position
		x = _x;
		y = _y;
		//schon hier anlegen..
		pNext = new SnakeGlied; 
	}
	//--- Atrribute ---
	int x;
	int y;
	SnakeGlied *pNext;
};
class Snake {
public:
	//--- Konstruktor ---
	Snake(int x, int y, Dir d) {
		pKopf = new SnakeGlied(x, y);
		dir = d;
	}
	SnakeGlied * pKopf;
	Dir dir;
};
class Futter {	
public:
	Futter() {
		// Raster SN_EL_SIZE einhalten
		x = 280;//rand() % (WINDOWSIZE_X / SN_EL_SIZE) * SN_EL_SIZE;
		y = 120; //rand() % (WINDOWSIZE_Y / SN_EL_SIZE) * SN_EL_SIZE;
	}
	int x;
	int y;
};
class QtSnake : public QMainWindow
{
	Q_OBJECT
private:
	Ui::QtSnakeClass ui;

public:
	QtSnake(QWidget *parent = Q_NULLPTR);
	QLabel* label;
	QLabel* labelPos;
	QPushButton* btn;
	QPainter* p;
	QTimer* timer;

	Snake* snake;
	Futter* pille;

	void paintEvent(QPaintEvent *e);
	void keyPressEvent(QKeyEvent *event);
	void GamePlay();
	void GameOverCheck();
	void GameOver(GameOverTyp);

public slots:
	void myTimerSlot();
	void myBtnSlot();

};
