#include <Player.h>
#include <MyPlayer3.h>
#include <string>
#include <primegame_maingui.h>


MyPlayer3::MyPlayer3(string inputname, PrimeGame_MainGUI * application)
{
	temp = application;
	this->name = inputname;
	this->boardsize = temp->getBoardSize();
	this->gesamtpunktzahl = 0;
	this->gespielte_spiele = 0;
	this->punkte_siege = 0;
}

MyPlayer3::MyPlayer3()
{

}

int MyPlayer3::auswahl(int board[])
{
	int auswahl = 0;

	// Wählt immer die noch kleinste vorhandene Zahl
	for (int i = 1; i <= 150; i++)
	{
		if (board[i] == 0)
		{
			return i;
		}
	}
	
	return 10;
}


MyPlayer3::~MyPlayer3()
{
}
