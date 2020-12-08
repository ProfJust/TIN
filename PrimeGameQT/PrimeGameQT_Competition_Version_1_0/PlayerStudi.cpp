#include <Player.h>
#include <PlayerStudi.h>
#include <string>
#include <primegame_maingui.h>

//---- öffentlicher Spielername ------
#define MATR_NR "2018xxxxx"

//--------------------------------------------------------
// FÜr das Abtestat bitte eintragen ===>>>
// Funktion erstellt von Vorname Name, Matr.Nr. 201812345 
//--------------------------------------------------------
int PlayerStudi::auswahl(int board[])
{
	int auswahl = 0;
	// Wählt immer die noch größte vorhandene Zahl
	for (int i = 150; i > 0; i--)	{
		if (board[i] == 0) {//Noch verfügbar?
			return i;
		}
	}
	return 0;
}


PlayerStudi::PlayerStudi(PrimeGame_MainGUI * application)
{
	temp = application;
	this->name = MATR_NR;
	this->boardsize = temp->getBoardSize();
	this->gesamtpunktzahl = 0;
	this->gespielte_spiele = 0;
	this->punkte_siege = 0;
}

PlayerStudi::PlayerStudi()
{
	this->gesamtpunktzahl = 0;
	this->gespielte_spiele = 0;
	this->punkte_siege = 0;
}

PlayerStudi::~PlayerStudi()
{
}
