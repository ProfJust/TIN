#include <Player.h>
#include <MyPlayer1.h>
#include <string>
#include <primegame_maingui.h>


MyPlayer1::MyPlayer1(string inputname, PrimeGame_MainGUI * application)
{
	temp = application;
	this->name = inputname;
	this->boardsize = temp->getBoardSize();
	this->gesamtpunktzahl = 1;
	this->gespielte_spiele = 1;
	this->punkte_siege = 1;
	
}
	
MyPlayer1::MyPlayer1()
{
	this->gesamtpunktzahl = 1;
	this->gespielte_spiele = 1;
	this->punkte_siege = 1;
}

int MyPlayer1::auswahl(int board[])
{
	int auswahl = 0;
	
	auswahl = rand() % 150 + 1;  //Auswahl per Zufall
	
	return auswahl;
}


MyPlayer1::~MyPlayer1()
{
}
