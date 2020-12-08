#include <string>
#include <primegame_maingui.h>
#include <Player.h>

class MyPlayer4 : public Player
{

public:
	MyPlayer4::MyPlayer4(string inputname, PrimeGame_MainGUI * application);
	MyPlayer4::~MyPlayer4();
	MyPlayer4::MyPlayer4();
	bool MyPlayer4::ist_primzahl(int zahl);
	virtual int auswahl(int board[]);


};