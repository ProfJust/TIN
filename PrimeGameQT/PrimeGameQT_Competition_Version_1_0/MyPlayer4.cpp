#include <Player.h>
#include <MyPlayer4.h>
#include <string>
#include <primegame_maingui.h>


MyPlayer4::MyPlayer4(string inputname, PrimeGame_MainGUI * application)
{
	temp = application;
	this->name = inputname;
	this->boardsize = temp->getBoardSize();
	this->gesamtpunktzahl = 0;
	this->gespielte_spiele = 0;
	this->punkte_siege = 0;
}

MyPlayer4::MyPlayer4()
{

}

bool MyPlayer4::ist_primzahl(int zahl)
{
	bool ist_primzahl = true;
	for (int testteiler = 2; testteiler < zahl; testteiler++)
	{
		if (zahl % testteiler == 0)
		{
			ist_primzahl = false;
			//break;
		}
	}

	return ist_primzahl;
}

int MyPlayer4::auswahl(int board[])
{
	int auswahl = 0;

	// Wählt die höchste Primzahl; ansonsten die noch größte vorhandene Zahl im Feld
	for (int i = 150; i >= 1; i--)
	{
		if (ist_primzahl(i) && board[i] == 0)
		{
			return i;
		}
	}

	for (int i = 150; i >= 1; i--)
	{
		if (board[i] == 0)
		{
			return i;
		}
	}

	return 10;
}


MyPlayer4::~MyPlayer4()
{
}
