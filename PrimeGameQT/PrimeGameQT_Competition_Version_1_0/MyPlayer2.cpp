#include <Player.h>
#include <MyPlayer2.h>
#include <string>
#include <primegame_maingui.h>


MyPlayer2::MyPlayer2(string inputname, PrimeGame_MainGUI * application)
{
	temp = application;
	this->name = inputname;
	this->boardsize = temp->getBoardSize();
	this->gesamtpunktzahl = 0;
	this->gespielte_spiele = 0;
	this->punkte_siege = 0;
}

MyPlayer2::MyPlayer2()
{
	this->gesamtpunktzahl = 0;
	this->gespielte_spiele = 0;
	this->punkte_siege = 0;
}

int MyPlayer2::auswahl(int board[])
{
	int auswahl = 0;

	// Wählt immer die noch größte vorhandene Zahl
	for (int i = 150; i > 0; i--)
	{
		if (board[i] == 0)
		{
			return i;
		}
	}

	return 0;
}




MyPlayer2::~MyPlayer2()
{
}
