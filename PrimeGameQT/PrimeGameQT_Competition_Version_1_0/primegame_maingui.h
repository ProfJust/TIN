#ifndef PRIMEGAME_MAINGUI_H
#define PRIMEGAME_MAINGUI_H

//#include "stdafx.h"
#include <QMainWindow>
#include <string>
#include "windows.h"
#include <iostream>
#include <sstream>


using namespace std;

namespace Ui {
	class PrimeGame_MainGUI;
}

class PrimeGame_MainGUI : public QMainWindow
{
	Q_OBJECT
		
public:

	
	explicit PrimeGame_MainGUI(QWidget *parent = nullptr);
	void PrimeGame_MainGUI::initListe();
	bool start;
	int player1; // Index des Spieler 1 im Vector
	int player2; // Index des Spieler 2 im Vector
	int paarungen[1000];
	void PrimeGame_MainGUI::initializeVersus();
	int PrimeGame_MainGUI::countPoints(int owner);
	void PrimeGame_MainGUI::showScore();
	void PrimeGame_MainGUI::writeInTextField(QString text);
	int PrimeGame_MainGUI::auswahlFktGamer1();
	int PrimeGame_MainGUI::auswahlFktGamer2();
	int PrimeGame_MainGUI::chooseNr(int owner, int player_in_array);
	bool PrimeGame_MainGUI::gameOver();
	void PrimeGame_MainGUI::setFactors(int aktNr, int owner);
	void PrimeGame_MainGUI::setPointsPlayer1();
	void PrimeGame_MainGUI::setPointsPlayer2();
	void PrimeGame_MainGUI::writeInWinnerLabel(QString text);
	int PrimeGame_MainGUI::getBoardSize();
	void PrimeGame_MainGUI::setPlayer1(int i);
	void PrimeGame_MainGUI::setPlayer2(int i);
	void PrimeGame_MainGUI::resetGuiBoard();
	int PrimeGame_MainGUI::getAnzahlSpieler();
	QString PrimeGame_MainGUI::getNameInVector(int position);
	void PrimeGame_MainGUI::sortPlayersbyPoints();
	void PrimeGame_MainGUI::sortPlayersbyVictoryPoints();
	void PrimeGame_MainGUI::add_points_to_player(int points, int index_in_vector);
	void PrimeGame_MainGUI::add_siegpunkte_to_player(int points, int index_in_vector);
	void PrimeGame_MainGUI::add_gespielte_spiele_to_player(int index_in_vector);
	void PrimeGame_MainGUI::setLabel_for_Player1(int index_in_vector);
	void PrimeGame_MainGUI::setLabel_for_Player2(int index_in_vector);
	int PrimeGame_MainGUI::get_points_from_player(int index_in_vector);
	int PrimeGame_MainGUI::get_siegpunkte_from_player(int index_in_vector);
	int PrimeGame_MainGUI::get_gespielte_spiele_from_player(int index_in_vector);
	bool PrimeGame_MainGUI::get_disq_Status_from_player(int index_in_vector); 


	~PrimeGame_MainGUI();
	
	
	private slots:
	void startButtonEvent();
	void exitButtonEvent();
	

private:
	Ui::PrimeGame_MainGUI *ui;



};

#endif // PRIMEGAME_MAINGUI_H
