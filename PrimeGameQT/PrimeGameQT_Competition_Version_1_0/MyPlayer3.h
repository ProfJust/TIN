#include <string>
#include <primegame_maingui.h>
#include <Player.h>

class MyPlayer3 : public Player
{

public:
	MyPlayer3::MyPlayer3(string inputname, PrimeGame_MainGUI * application);
	MyPlayer3::~MyPlayer3();
	MyPlayer3::MyPlayer3();
	virtual int auswahl(int board[]);

	
};