//PlayerStudi.h
#pragma once
#include <string>
#include <primegame_maingui.h>
#include <Player.h>



class PlayerStudi: public Player
{

public:
	PlayerStudi::PlayerStudi(PrimeGame_MainGUI * application);
	PlayerStudi::~PlayerStudi();
	PlayerStudi::PlayerStudi();
	virtual int auswahl(int board[]);
}; 
