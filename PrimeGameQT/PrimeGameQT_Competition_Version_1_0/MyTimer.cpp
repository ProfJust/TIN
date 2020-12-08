#include "mytimer.h"
#include "primegame_maingui.h"
#include <QDebug>
#include <qtextcursor.h>
#include <qstring.h>
#include <fstream>


#define SLEEP 0 // Pause in ms nach Spielzug

PrimeGame_MainGUI* temp;
int x = 0; // Startindex für Liste der Paarungen
bool next_game;
bool summary;

//Datei zum Loggen 
ofstream logging("summary.txt");

MyTimer::MyTimer()
{
	// create a timer
	timer = new QTimer(this);

	connect(timer, SIGNAL(timeout()), this, SLOT(MyTimerSlot()), Qt::UniqueConnection);
	gameoverOutput = false; // Flag, damit Die Gameover-Ausgabe nur einmal erfolgt
	summary = false; // Flag, damit die Endergebnisse nur einmal angezeigt werden
	timer->setInterval(1);
	timer->start();
	
	
}

void MyTimer::getApplication(PrimeGame_MainGUI* application)
{
	temp = application;
	temp->setPlayer1(x);
	temp->setPlayer2(x + 1);
	

}


void MyTimer::MyTimerSlot()
{
		temp->setLabel_for_Player1(temp->paarungen[x]);
		temp->setLabel_for_Player2(temp->paarungen[x+1]);
				
		if (temp->start && !temp->gameOver() && !temp->get_disq_Status_from_player(temp->paarungen[x]) && !temp->get_disq_Status_from_player(temp->paarungen[x+1]))
		{
			//---- Spieler 1 -----

			temp->setFactors(temp->chooseNr(1, temp->paarungen[x]), 1);
			temp->showScore();

			//---- Spieler 2 -----
			temp->setFactors(temp->chooseNr(2, temp->paarungen[x+1]), 2);
			temp->showScore();

		}

		// Wenn GameOver oder einer der Spieler disqualifiziert wurde
		if ((temp->gameOver() && (gameoverOutput == false))|| (temp->get_disq_Status_from_player(temp->paarungen[x+1])&& !temp->get_disq_Status_from_player(temp->paarungen[x]))
				|| (temp->get_disq_Status_from_player(temp->paarungen[x]) && !temp->get_disq_Status_from_player(temp->paarungen[x+1])))
		{


			// Wenn GameOver
			if ((temp->countPoints(1) > temp->countPoints(2)) && !temp->get_disq_Status_from_player(temp->paarungen[x]) && !temp->get_disq_Status_from_player(temp->paarungen[x + 1]))
			{
				temp->writeInTextField("Es spielte ");
				temp->writeInTextField(temp->getNameInVector(temp->paarungen[x]));
				temp->writeInTextField(" gegen ");
				temp->writeInTextField(temp->getNameInVector(temp->paarungen[x+1]));
				temp->writeInTextField(" --> ");
				temp->writeInTextField(temp->getNameInVector(temp->paarungen[x]));
				temp->writeInTextField(" hat gewonnen mit ");
				
				temp->writeInTextField(QString::number(temp->countPoints(1)));
				temp->writeInTextField(" : ");
				temp->writeInTextField(QString::number(temp->countPoints(2)));
				temp->writeInTextField(" \n");;
				
				
				temp->add_gespielte_spiele_to_player(temp->paarungen[x]);
				temp->add_gespielte_spiele_to_player(temp->paarungen[x+1]);

				temp->add_points_to_player(temp->countPoints(1), temp->paarungen[x]);
				temp->add_points_to_player(temp->countPoints(2), temp->paarungen[x+1]);

				temp->add_siegpunkte_to_player(3, temp->paarungen[x]);
				
				
			}
			else
			{
				if (!temp->get_disq_Status_from_player(temp->paarungen[x]) && !temp->get_disq_Status_from_player(temp->paarungen[x + 1]))
				{
					if ((temp->countPoints(1) < temp->countPoints(2)))
					{
						temp->writeInTextField("Es spielte ");
						temp->writeInTextField(temp->getNameInVector(temp->paarungen[x]));
						temp->writeInTextField(" gegen ");
						temp->writeInTextField(temp->getNameInVector(temp->paarungen[x + 1]));
						temp->writeInTextField(" --> ");
						temp->writeInTextField(temp->getNameInVector(temp->paarungen[x + 1]));
						temp->writeInTextField(" hat gewonnen mit ");
						temp->writeInTextField(QString::number(temp->countPoints(2)));
						temp->writeInTextField(" : ");
						temp->writeInTextField(QString::number(temp->countPoints(1)));
						temp->writeInTextField(" \n");

						// Statistiken aktualisieren: Punkte, Siegpunkte, gespielte Spiele
						temp->add_gespielte_spiele_to_player(temp->paarungen[x]);
						temp->add_gespielte_spiele_to_player(temp->paarungen[x + 1]);

						temp->add_points_to_player(temp->countPoints(1), temp->paarungen[x]);
						temp->add_points_to_player(temp->countPoints(2), temp->paarungen[x + 1]);

						temp->add_siegpunkte_to_player(3, temp->paarungen[x + 1]);
					}
					else
					{
						temp->writeInTextField("Es spielte ");
						temp->writeInTextField(temp->getNameInVector(temp->paarungen[x]));
						temp->writeInTextField(" gegen ");
						temp->writeInTextField(temp->getNameInVector(temp->paarungen[x + 1]));
						temp->writeInTextField(" --> ");
						temp->writeInTextField(temp->getNameInVector(temp->paarungen[x + 1]));
						temp->writeInTextField(" Das Spiel endete unentschieden ");
						temp->writeInTextField(QString::number(temp->countPoints(2)));
						temp->writeInTextField(" : ");
						temp->writeInTextField(QString::number(temp->countPoints(1)));
						temp->writeInTextField(" \n");

						// Statistiken aktualisieren: Punkte, Siegpunkte, gespielte Spiele
						temp->add_gespielte_spiele_to_player(temp->paarungen[x]);
						temp->add_gespielte_spiele_to_player(temp->paarungen[x + 1]);

						temp->add_points_to_player(temp->countPoints(1), temp->paarungen[x]);
						temp->add_points_to_player(temp->countPoints(2), temp->paarungen[x + 1]);

						temp->add_siegpunkte_to_player(1, temp->paarungen[x]);
						temp->add_siegpunkte_to_player(1, temp->paarungen[x + 1]);
					}
					
				}
				
				
										
			}

			
			// Board wieder zurücksetzen auf Startzustand

			if (temp->paarungen[x + 2] != 99)
			{
				x += 2; // Nächste Paarungen in der Liste
				temp->setPlayer1(temp->paarungen[x]);
				temp->setPlayer2(temp->paarungen[x + 1]);
				temp->initListe();
				temp->resetGuiBoard();
				
			}
			else
			{
				gameoverOutput = true;
				// Ausgabe des Endergebnisses
				temp->sortPlayersbyPoints();

				if (!summary)
				{
					temp->writeInTextField("\nEndstand nach Gesamtpunkten:\n\n");
					summary = true;
					// Loggen in Datei
					logging << "\nEndstand nach Gesamtpunkten:\n" << endl;
					for (int i = 0; i<temp->getAnzahlSpieler(); i++)
					{
						temp->writeInTextField(temp->getNameInVector(i) + ": ");
						temp->writeInTextField(QString::number(temp->get_points_from_player(i)) + " Gesamtpunkte\n");
						// Loggen in Datei
						logging << temp->getNameInVector(i).toStdString() << " : " << temp->get_points_from_player(i) << " Gesamtpunkte" << endl;

					}


					temp->sortPlayersbyVictoryPoints();
					temp->writeInTextField("\nEndstand nach Siegpunkten:\n\n");
					// Loggen in Datei
					logging << "\nEndstand nach Siegpunkten:\n" << endl;
					for (int i = 0; i<temp->getAnzahlSpieler(); i++)
					{
						temp->writeInTextField(temp->getNameInVector(i) + ": ");
						temp->writeInTextField((QString::number(temp->get_siegpunkte_from_player(i))) + " Siegpunkte\n");
						// Loggen in Datei
						logging << temp->getNameInVector(i).toStdString() << " : " << temp->get_siegpunkte_from_player(i) << " Siegpunkte\n" << endl;
					}

					logging << "\n";
					temp->writeInTextField("\n");

					// Ausgabe der disqualifizierten Spieler
					for (int i = 0; i < temp->getAnzahlSpieler(); i++)
					{
						if (temp->get_disq_Status_from_player(i))
						{
							temp->writeInTextField("Spieler: " + temp->getNameInVector(i) + " wurde disqualifiziert\n");
							logging << ("Spieler: ");
							logging << temp->getNameInVector(i).toStdString();
							logging << (" wurde disqualifiziert\n");
						}
					}
					logging.close();
				}
				
			}

			


			
			
		}
			
			
	

	
}