#include <string>
#include <primegame_maingui.h>
#include <Player.h>

class MyPlayer2 : public Player
{

public:
	MyPlayer2::MyPlayer2(string inputname, PrimeGame_MainGUI * application);
	MyPlayer2::~MyPlayer2();
	MyPlayer2::MyPlayer2();
	virtual int auswahl(int board[]);
	



};