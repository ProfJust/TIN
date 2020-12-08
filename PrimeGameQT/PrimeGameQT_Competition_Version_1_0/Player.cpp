#include "Player.h"
#include "primegame_maingui.h"
#include <string>



Player::Player(PrimeGame_MainGUI * application)
{
	temp = application;
	this->disqualified = false;
}

Player::Player(string inputname, PrimeGame_MainGUI * application)
{
	temp = application;
	this->name = inputname;
	this->disqualified = false;
	
}

Player::~Player()
{

}

int Player::auswahl(int board[])
{
	return 3;
}


void Player::add_points_to_gesamtpunktzahl(int punkte)
{
	this->gesamtpunktzahl += punkte;
}

void Player::add_punkte_siege(int punkte)
{
	this->punkte_siege += punkte;
}

void Player::add_gespielte_spiele()
{
	this->gespielte_spiele += 1;
}

Player::Player()
{

}



string Player::getName()
{
	return name;
}

