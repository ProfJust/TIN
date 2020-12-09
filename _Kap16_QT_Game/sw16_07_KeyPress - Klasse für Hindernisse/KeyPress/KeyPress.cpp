//--- KeyPress.cpp ---
#include "KeyPress.h"
#include <Windows.h>

//---- Konstruktor ----------------------
KeyPress::KeyPress(QWidget *parent) 
	: QMainWindow(parent)
{	
	ui.setupUi(this);

	this->setFixedSize(WINDOW_SIZE_X, WINDOW_SIZE_Y); //Größe des MainWindow setzten

	 //---Label----
	myLabel = new QLabel(this);
	myLabel->setGeometry(10, 160, 160, 20); //x,y,w,h
	
	// Größe der Schriftart auf dem Label setzen
	QFont labelFont;
	labelFont.setPixelSize(14);
	myLabel->setFont(labelFont);

	//Timer 
	myTimer = new QTimer(this); //(4)
	connect(myTimer, SIGNAL(timeout()), this, SLOT(myTimerSlot()), Qt::UniqueConnection); //(5)
	myTimer->setInterval(10); //(6)
	myTimer->start(); //(7)

	//--- Hindernis -- (x,y,w,h)
	for (int sp = 0; sp < HIND_SPALTEN; sp++) {
		hi[sp] = new clHindernis(sp * WINDOW_SIZE_X / HIND_SPALTEN,
			                     100,
			                     WINDOW_SIZE_X / HIND_SPALTEN - 10,
			                     20);
	}
}

void KeyPress::myTimerSlot() {
	//-- neue Position des Balles --
	ball_x += speed_x;
	ball_y += speed_y;
	//-- Abprallen an Wänden prüfen --
	if (ball_x <= 0 || ball_x >= WINDOW_SIZE_X-BALL_SIZE/2) speed_x = -speed_x;
	if (ball_y <= 0  /*unten frei*/ ) speed_y = -speed_y;

	//-- Abprallen an Schläger prüfen -- 
	if (	ball_y >= (WINDOW_SIZE_Y - BALL_SIZE - SCHLAEGER_HOEHE)
		&& (ball_x < pos_x + SCHLAEGER_BREITE/2)  //rechts
		&& (ball_x > pos_x - SCHLAEGER_BREITE/2)) //links
	{
		speed_y = -speed_y;
		ball_y = WINDOW_SIZE_Y - BALL_SIZE  - SCHLAEGER_HOEHE;
	}

	//-- Ball unten rausgeflogen ---
	if (ball_y > WINDOW_SIZE_Y) {
		myLabel->setText("Game Over");
		repaint();
		Sleep(2000);
		exit(0);
	}
	//-- Hindernisse auf treffer prüfen --  
	for (int sp = 0; sp < HIND_SPALTEN; sp++) {
		if (hi[sp]->st == sichtbar &&
			(ball_x >= hi[sp]->x   &&   ball_x <= (hi[sp]->x + hi[sp]->w)) &&
			(ball_y <= (hi[sp]->y + hi[sp]->h) && ball_y >= hi[sp]->y))
		{
			myLabel->setText("Getroffen");
			hi[sp]->st = unsichtbar;
			//von oben oder unten getroffen
			speed_y = -(speed_y + 1);//incl. Speed erhöhen	
		}
	}

	repaint(); //Löst Paint-Event aus
	
}


//-----------------------------------------------------
// Was soll passieren wenn die Taste gedrückt wird?
void KeyPress::keyPressEvent(QKeyEvent *event)
{
	//--- Pfeil-Tasten ---
	if (event->key() == Qt::Key_Right)	{
		myLabel->setText("Pfeil Rechts");
		//verändert Schlägerposition
		pos_x += X_SPEED; 
	}
	if (event->key() == Qt::Key_Left)	{
		myLabel->setText("Pfeil Links");
		//verändert Schlägerposition
		pos_x -= X_SPEED;
	}
	//repaint(); //Löst Paint-Event aus => macht jetzt der Timer
}


void KeyPress::paintEvent(QPaintEvent *e) {
	QPainter p(this); 
	//--- Schläger ---
	p.setPen(Qt::black);
	p.setBrush(Qt::black);
	p.drawRect(pos_x, WINDOW_SIZE_Y- SCHLAEGER_HOEHE, SCHLAEGER_BREITE, SCHLAEGER_HOEHE);  //x,y,w,h

	//-- Ball zeichen ---
	p.setBrush(Qt::red);
	p.drawEllipse(ball_x, ball_y, BALL_SIZE, BALL_SIZE);

	//--- Hindernisse zeichnen ---
	for (int sp = 0; sp < HIND_SPALTEN; sp++) {
		if (hi[sp]->st == sichtbar) {
			p.setBrush(Qt::blue);
			p.drawRect(hi[sp]->x, hi[sp]->y, hi[sp]->w, hi[sp]->h); 
		}
	}
}