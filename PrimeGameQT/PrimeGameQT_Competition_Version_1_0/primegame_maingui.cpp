#include "primegame_maingui.h"
#include "ui_primegame_maingui.h"

#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream> //Zahl in String umwandeln
#include <string>
#include <QPushButton>
#include <qtextcursor.h>
#include <qgroupbox.h>
#include <QVBoxLayout>
#include <qscrollarea.h>
#include <Player.h>

//Einbinden der Spieler
#include <MyPlayer2.h>
#include <MyPlayer3.h>
#include <MyPlayer4.h>
#include "PlayerStudi.h"  //WEITERER SPIELER - ERGÄNZUNG #1

/* *******************************************************************************************************************************

Prime Game Competition in QT
Version 1.5

Fachbereich Maschinenbau Bocholt
Technische Informatik
Prof. Dr. Olaf Just

@author: M.Sc. Michael Engelmann

05.11.2018

**********************************************************************************************************************************

*/

using namespace std;

//----------- Globals ----------------------------------
int auswahl = 0;  //Zahl die aus der Liste gewählt wurde

				  //Datei zum Loggen 
ofstream logfile("Logfile.txt");


#define NMAX 150   //Liste der Zahlen im Spiel von [1..NMAX-1]
#define NMB_COLOR 3  //Anzahl der verschiedenen Farben zur Zuweisung des Element zum Spieler
#define SLEEP 0   // Pause in ms nach Spielzug


//NrItem NrList[NMAX];  //Instanzierung der Liste
QPushButton *numberButtons[NMAX + 1];
int board[NMAX + 1];


//Vector der Spieler
vector<Player *> players;

// ANZAHL DER SPIELER MUSS MANUELL ANGEPASST WERDEN *************************************
int anzahl_Spieler = 4;  //WEITERER SPIELER - ERGÄNZUNG #2

bool gameoverOutput = true;

PrimeGame_MainGUI::PrimeGame_MainGUI(QWidget *parent) :
	QMainWindow(parent), ui(new Ui::PrimeGame_MainGUI)
{

	ui->setupUi(this);
	connect(ui->StartButton, SIGNAL(clicked()), this, SLOT(startButtonEvent()));
	connect(ui->ExitButton, SIGNAL(clicked()), this, SLOT(exitButtonEvent()));
	initListe();  //Liste erstellen, alles auf noOwner setzen
	initializeVersus(); //Paarungen festlegen, 99 ist Ende der Liste



						// HIER DIE NEUEN SPIELER EINBINDEN UND OBEN DIE ANZAHL DER SPIELER ANPASSEN ***************************************

						//Spielerobjekte initialisieren

	players.push_back(new MyPlayer2("Biggest", this));
	players.push_back(new MyPlayer3("Smallest", this));
	players.push_back(new MyPlayer4("BigPrime", this)); 
	//WEITERER SPIELER - ERGÄNZUNG #3
	players.push_back(new PlayerStudi(this));

	players[0]->disqualified = false;
	players[1]->disqualified = false;
	players[2]->disqualified = false;
	//WEITERER SPIELER - ERGÄNZUNG #4
	players[3]->disqualified = false;

	//******************************************************************************************************************


	// Einfaerben der Labels für Spieler1->gruen und Spieler2->rot
	QPalette palette = ui->label_2->palette();
	palette.setColor(ui->label_2->foregroundRole(), Qt::darkGreen);
	ui->label_2->setPalette(palette);

	palette = ui->label_3->palette();
	palette.setColor(ui->label_3->foregroundRole(), Qt::red);

	ui->label_3->setPalette(palette);

	QWidget *widget[NMAX + 1];
	QGridLayout *grid = new QGridLayout;
	//Zellenabstand
	grid->setSpacing(1);


	//Rowcounter zum Verteilen der Buttons auf verschiedene Reihen im Grid
	int rowcounter = 0;
	int columncounter = 0;

	//Initialisierung der NumberButtons
	for (int i = 1; i <= NMAX; i++)
	{

		widget[i] = new QWidget(this);
		numberButtons[i] = new QPushButton(widget[i]);
		numberButtons[i]->setMaximumWidth(70);


		// Integer-Zahl in String casten, danach in Char-Array umkopieren
		std::string s = std::to_string(i);
		char myStr[4];
		strcpy(myStr, s.c_str());

		numberButtons[i]->setText(myStr);
		grid->addWidget(widget[i], rowcounter, columncounter, 1, 2);


		// 11 Buttons pro Reihe
		if (i % 13 == 0)
		{
			rowcounter += 1;
			columncounter = 0;
		}
		else
			columncounter++;

	}


	ui->groupBox->setLayout(grid);

	start = false;
	showScore();


}

void PrimeGame_MainGUI::writeInTextField(QString text)
{
	QTextCursor cursor(ui->textField_Auswahl->textCursor());
	QTextCharFormat format;
	format.setForeground(QBrush(QColor("black")));
	cursor.setCharFormat(format);
	cursor.insertText(text);
}

void PrimeGame_MainGUI::writeInWinnerLabel(QString text)
{

	ui->label_Win->setText(text);
}

void PrimeGame_MainGUI::startButtonEvent()
{
	start = true;

}

void PrimeGame_MainGUI::exitButtonEvent()
{
	exit(0);
}

int PrimeGame_MainGUI::getBoardSize()
{
	return NMAX;
}

void PrimeGame_MainGUI::setPlayer1(int i)
{
	player1 = i;
}

void PrimeGame_MainGUI::setPlayer2(int i)
{
	player2 = i;
}





//------ Initialisierungsroutine -------
void PrimeGame_MainGUI::initListe() {

	// Der Index im Feld entspricht der Zahl
	// Beim Inhalt gilt: 0 = frei, 1 = gehört Spieler1, 2 =gehört Spieler2
	for (int i = 0; i <= NMAX; i++)
	{
		board[i] = 0;
	}
}
//-------------------------------------------------------------



void PrimeGame_MainGUI::initializeVersus()
{
	int x = 0; //Startindex

	for (int i = 0; i < (anzahl_Spieler); i++)
	{
		for (int j = i + 1; j < (anzahl_Spieler); j++)
		{
			paarungen[x] = i;
			paarungen[x + 1] = j;
			x += 2;
		}
	}

	// 2.Runde; mit vertauschter Reihenfolge --> Der andere Spieler beginnt
	int anz_paarungen = x;
	for (int i = 0; i < anz_paarungen; i += 2)
	{
		paarungen[x] = paarungen[i + 1];
		paarungen[x + 1] = paarungen[i];
		x += 2;

	}
	paarungen[x] = 99; // 99 steht für Ende der Paarungen


}

// 1 = Spieler1, 2 = Spieler2
int PrimeGame_MainGUI::countPoints(int owner)
{
	int points = 0;
	for (int i = 1; i <= NMAX; i++)
	{
		if (board[i] == owner)
			points += i;
	}
	return points;
}


// Anzeigen der aktuellen Punktzahl in der GUI
void PrimeGame_MainGUI::setPointsPlayer1()
{
	ui->textfield_points_Player1->setText(QString::fromStdString(std::to_string(countPoints(1))));
}

void PrimeGame_MainGUI::setPointsPlayer2()
{
	ui->textfield_points_Player2->setText(QString::fromStdString(std::to_string(countPoints(2))));
}



//--- zeigt den aktuellen Spielstand auf der Konsole
void PrimeGame_MainGUI::showScore() {


	// Setzen der aktuellen Spielerpunkte
	setPointsPlayer1();
	setPointsPlayer2();


	for (int i = 1; i <= NMAX; i++)
	{

		if (board[i] == 1)
		{
			QColor col = QColor(Qt::darkGreen);
			QString qss = QString("background-color: %1").arg(col.name());
			numberButtons[i]->setStyleSheet(qss);

		}
		else if (board[i] == 2)
		{
			QColor col = QColor(Qt::red);
			QString qss = QString("background-color: %1").arg(col.name());
			numberButtons[i]->setStyleSheet(qss);

		}

	}
}
//-------------------------------------------------------------

void PrimeGame_MainGUI::resetGuiBoard()
{
	for (int i = 1; i <= NMAX; i++)
	{
		QColor col = QColor(Qt::gray);
		QString qss = QString("background-color: %1").arg(col.name());
		numberButtons[i]->setStyleSheet(qss);

	}
}

int PrimeGame_MainGUI::getAnzahlSpieler()
{
	return anzahl_Spieler;
}

QString PrimeGame_MainGUI::getNameInVector(int position)
{
	return QString::fromStdString(players[position]->getName());
}

void PrimeGame_MainGUI::sortPlayersbyPoints()
{
	for (int i = 0; i < anzahl_Spieler; i++)
	{
		//BubbleSort zum Sortieren des Vektors nach Gesamtpunktzahl
		for (int j = 0; j < anzahl_Spieler - 1; j++)
		{
			if (players[j]->gesamtpunktzahl < players[j + 1]->gesamtpunktzahl)
			{
				Player* temp = players[j];
				players[j] = players[j + 1];
				players[j + 1] = temp;
			}

		}
	}
}

void PrimeGame_MainGUI::sortPlayersbyVictoryPoints()
{
	for (int i = 0; i < anzahl_Spieler; i++)
	{
		//BubbleSort zum Sortieren des Vektors nach Siegpunkten
		for (int j = 0; j < anzahl_Spieler - 1; j++)
		{
			if (players[j]->punkte_siege < players[j + 1]->punkte_siege)
			{
				Player* temp = players[j];
				players[j] = players[j + 1];
				players[j + 1] = temp;
			}

		}
	}
}




void PrimeGame_MainGUI::add_points_to_player(int points, int index_in_vector)
{
	players[index_in_vector]->add_points_to_gesamtpunktzahl(points);
}

void PrimeGame_MainGUI::add_siegpunkte_to_player(int points, int index_in_vector)
{
	players[index_in_vector]->add_punkte_siege(points);
}

void PrimeGame_MainGUI::add_gespielte_spiele_to_player(int index_in_vector)
{
	players[index_in_vector]->add_gespielte_spiele();
}

void PrimeGame_MainGUI::setLabel_for_Player1(int index_in_vector)
{
	ui->label_2->setText(QString::fromStdString(players[index_in_vector]->getName()));
}

void PrimeGame_MainGUI::setLabel_for_Player2(int index_in_vector)
{
	ui->label_3->setText(QString::fromStdString(players[index_in_vector]->getName()));
}



int PrimeGame_MainGUI::get_points_from_player(int index_in_vector)
{
	return players[index_in_vector]->gesamtpunktzahl;
}

int PrimeGame_MainGUI::get_siegpunkte_from_player(int index_in_vector)
{
	return players[index_in_vector]->punkte_siege;
}

int PrimeGame_MainGUI::get_gespielte_spiele_from_player(int index_in_vector)
{
	return players[index_in_vector]->gespielte_spiele;
}

bool PrimeGame_MainGUI::get_disq_Status_from_player(int index_in_vector)
{
	return players[index_in_vector]->disqualified;
}


int PrimeGame_MainGUI::auswahlFktGamer1()
{

	//Prüfung ob schon GameOver

	if (!gameOver())
	{
		int auswahl = players.at(player1)->auswahl(board);

		QTextCursor cursor(ui->textField_Auswahl->textCursor());
		QTextCharFormat format;
		format.setForeground(QBrush(QColor("green")));
		cursor.setCharFormat(format);
		// Integer-Zahl in String casten, danach in Char-Array umkopieren
		std::string s = std::to_string(auswahl);
		char myStr[5];
		strcpy(myStr, s.c_str());

		// Loggen in Datei
		logfile << players[player1]->getName() << " nimmt die Zahl: " << myStr << endl;
		return auswahl;
	}
	else
	{
		// 0 steht für GameOver
		return 0;
	}

}
//-------------------------------------------------------------

int PrimeGame_MainGUI::auswahlFktGamer2() {

	if (!gameOver())
	{
		int auswahl = players[player2]->auswahl(board);
		QTextCursor cursor(ui->textField_Auswahl->textCursor());
		QTextCharFormat format;
		format.setForeground(QBrush(QColor("red")));
		cursor.setCharFormat(format);
		// Integer-Zahl in String casten, danach in Char-Array umkopieren
		std::string s = std::to_string(auswahl);
		char myStr[5];
		strcpy(myStr, s.c_str());

		// Loggen in Datei
		logfile << players[player2]->getName() << " nimmt die Zahl: " << myStr << endl;
		return auswahl;
	}
	else
	{
		return 0;
	}
}


int PrimeGame_MainGUI::chooseNr(int owner, int player_in_array) {

	int chooseNr = 0;

	if (owner == 1) {
		chooseNr = auswahlFktGamer1();
	}
	else {
		chooseNr = auswahlFktGamer2();
	}

	if ((board[chooseNr] != 0) && !gameOver())
		//Disqualifiziert
		players[player_in_array]->disqualified = true;


	if ((board[chooseNr] == 0) && !gameOver())
		board[chooseNr] = owner;



	return chooseNr;
}
//-------------------------------------------------------------
//-----  Noch freie Zahlen verfügbar ?? ---
bool PrimeGame_MainGUI::gameOver() {
	for (int i = 1; i <= NMAX; i++)
	{
		if (board[i] == 0)
			return false;
	}


	return true;
}

//-------------------------------------------------------------
//---- setze alle Teiler von aktNr auf gegnerischen owner -----
void PrimeGame_MainGUI::setFactors(int aktNr, int owner) {
	int test = 0;

	for (int i = aktNr / 2; i > 0; i--) {
		test = aktNr % i;
		if (test == 0) { //Teiler gefunden
			if (owner == 1 && board[i] == 0)
			{
				board[i] = 2;
				logfile << players[player2]->getName() << " bekommt die Zahl " << i << endl;
			}
			if (owner == 2 && board[i] == 0)
			{
				board[i] = 1;
				logfile << players[player1]->getName() << " bekommt die Zahl " << i << endl;
			}

		}
	}
}



PrimeGame_MainGUI::~PrimeGame_MainGUI()
{
	logfile.close();
	delete ui;
}
