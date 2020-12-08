#pragma once
#include <string>
#include "primegame_maingui.h"


class Player
{
	
	public:
		Player(PrimeGame_MainGUI* application);
		Player(string name, PrimeGame_MainGUI* application);
		~Player();
		virtual int auswahl(int board[])=0;
		string getName();
		int gesamtpunktzahl;
		int punkte_siege;
		int gespielte_spiele;
		void add_points_to_gesamtpunktzahl(int punkte);
		void add_punkte_siege(int punkte);
		void add_gespielte_spiele();
		Player::Player();
		int boardsize;
		string name;
		bool disqualified;
		PrimeGame_MainGUI* temp;
		
				

};