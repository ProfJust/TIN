#include "myTicTacToe_V4.h"

myTicTacToe_V4::myTicTacToe_V4(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this); 

	//---- Spielfeld aufbauen ---- 
	this->setFixedSize(480, 480); //Größe des MainWindow setzten
	for (int reihe = 0; reihe < N; reihe++) {
		for (int spalte = 0; spalte < N; spalte++) {
			buttonArray[reihe][spalte] = new MyButton(reihe, spalte, this); //Instanzierung			
		// set size and location of the button
			buttonArray[reihe][spalte]->resize(BUTTON_BREITE, BUTTON_HOEHE); //Größe setzen
			buttonArray[reihe][spalte]->move(BUTTON_BREITE*spalte, BUTTON_HOEHE*reihe); //platzieren
		// set color 
			buttonArray[reihe][spalte]->setAutoFillBackground(true); //Farbe konfigurieren
			buttonArray[reihe][spalte]->setStyleSheet("background-color: rgb(0, 200, 200)"); //Blau
		 // Signale verbinden
			connect(buttonArray[reihe][spalte], SIGNAL(clicked()), this, SLOT(playSlot()));
		}
	}

	// Konfiguratiion der Textausgabe zum Spielstand
	SpielzugLabel = new QLabel(this);
	SpielzugLabel->setText(" O beginnt");
	SpielzugLabel->setGeometry(10, 360, 160, 20); //x,y,w,h
	// Größe der Schriftart auf dem Label setzen
	QFont labelFont;
	labelFont.setPixelSize(14);
	SpielzugLabel->setFont(labelFont);

}

//buttonArray[reihe][spalte]->setGeometry((QRect(QPoint(BUTTON_BREITE * reihe, BUTTON_HOEHE * spalte), 
//	QSize(BUTTON_BREITE, BUTTON_HOEHE))));  //x,y,w,h


void myTicTacToe_V4::playSlot()
{
	static bool spielerXistDranBit = false;
	static bool spielZuEndeBit = false;
	// Wer hat des Event erzeugt?
	QObject* obj = sender();
	//Returns the meta-method index of the signal that called the currently executing slot,
	//which is a member of the class returned by sender(). 
	//If called outside of a slot activated by a signal, -1 is returned.

	//Casten des QObjects in ein QPushButton
	QPushButton* button = qobject_cast<QPushButton*>(sender());

	//Casten auf MyButton
	MyButton* clkBtn = static_cast<MyButton*>(button);

	// --- Toggeln des angeklickten Buttons ---
	if (!spielZuEndeBit) {
		if (spielerXistDranBit) {
			if (buttonArray[clkBtn->btnReihe][clkBtn->btnSpalte]->owner == noOwner) {
				buttonArray[clkBtn->btnReihe][clkBtn->btnSpalte]->setText("X");
				buttonArray[clkBtn->btnReihe][clkBtn->btnSpalte]->owner = X;
				spielerXistDranBit = false;
				SpielzugLabel->setText(" O am Zug");
			}
		}
		else {
			if (buttonArray[clkBtn->btnReihe][clkBtn->btnSpalte]->owner == noOwner) {
				buttonArray[clkBtn->btnReihe][clkBtn->btnSpalte]->setText("O");
				buttonArray[clkBtn->btnReihe][clkBtn->btnSpalte]->owner = O;
				spielerXistDranBit = true;
				SpielzugLabel->setText(" X am Zug");
			}
		}
		spielZuEndeBit = check_gameOver();
	}
	else {
		SpielzugLabel->setText(" .. wird beendet");
		//Sleep(1000);
		exit(0);
	}	
}
bool myTicTacToe_V4::check_gameOver()
{
	//Wagerechte Dreier checken
	if ((buttonArray[0][0]->owner == X && buttonArray[0][1]->owner == X && buttonArray[0][2]->owner == X) ||
		(buttonArray[1][0]->owner == X && buttonArray[1][1]->owner == X && buttonArray[1][2]->owner == X) ||
		(buttonArray[2][0]->owner == X && buttonArray[2][1]->owner == X && buttonArray[2][2]->owner == X) ||
		//Senkrechte Dreier checken
		(buttonArray[0][0]->owner == X && buttonArray[1][0]->owner == X && buttonArray[2][0]->owner == X) ||
		(buttonArray[0][1]->owner == X && buttonArray[1][1]->owner == X && buttonArray[2][1]->owner == X) ||
		(buttonArray[0][2]->owner == X && buttonArray[1][2]->owner == X && buttonArray[2][2]->owner == X) ||
		//..muss noch um diadonale erweitert werden
		(buttonArray[0][2]->owner == X && buttonArray[1][1]->owner == X && buttonArray[2][0]->owner == X) ||
		(buttonArray[0][0]->owner == X && buttonArray[1][1]->owner == X && buttonArray[2][2]->owner == X)) {
		
		SpielzugLabel->setText("X hat gewonnen");
		SpielzugLabel->repaint();
		return true;
	}
	//Wagerechte Dreier checken
	if ((buttonArray[0][0]->owner == O && buttonArray[0][1]->owner == O && buttonArray[0][2]->owner == O) ||
		(buttonArray[1][0]->owner == O && buttonArray[1][1]->owner == O && buttonArray[1][2]->owner == O) ||
		(buttonArray[2][0]->owner == O && buttonArray[2][1]->owner == O && buttonArray[2][2]->owner == O) ||
		//Senkrechte Dreier checken
		(buttonArray[0][0]->owner == O && buttonArray[1][0]->owner == O && buttonArray[2][0]->owner == O) ||
		(buttonArray[0][1]->owner == O && buttonArray[1][1]->owner == O && buttonArray[2][1]->owner == O) ||
		(buttonArray[0][2]->owner == O && buttonArray[1][2]->owner == O && buttonArray[2][2]->owner == O) ||
		//..muss noch um diadonale erweitert werden
		(buttonArray[0][2]->owner == O && buttonArray[1][1]->owner == O && buttonArray[2][0]->owner == O) ||
		(buttonArray[0][0]->owner == O && buttonArray[1][1]->owner == O && buttonArray[2][2]->owner == O)) {
		
		SpielzugLabel->setText("O hat gewonnen");
		SpielzugLabel->repaint();
		return true;
	}
	return false;
}

