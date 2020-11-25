#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_myTicTacToe_V4.h"
#include <QLabel> //---- Ein LAbel --
//#include <QPushButton>  //--- Ein Button ----
#include "MyButton.h"  //Eigene Erweiterung von QPushButton

#define N 3 // Größe der Felder (Buttons)
#define BUTTON_BREITE 160
#define BUTTON_HOEHE 120

class myTicTacToe_V4 : public QMainWindow
{
	Q_OBJECT

public:
	myTicTacToe_V4(QWidget *parent = Q_NULLPTR);

private:
	Ui::myTicTacToe_V4Class ui;
	MyButton *buttonArray[N][N]; // Array für die Widgets
	QLabel *SpielzugLabel;
	
private slots:
	void playSlot();       //Spielzug ausführen
	bool check_gameOver(); //Prüfe ob wer gewonnen hat	
};
