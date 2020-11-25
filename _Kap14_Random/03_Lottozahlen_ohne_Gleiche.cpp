// 03_Lottozahlen_ohne_Gleiche.cpp : Defines the entry point for the console application.
// Ermittelt  6 Zufallszahlen im Intervall [1 .. 49]
// Version vom 6.10.17
//***************************************************
#include "stdafx.h"
#include <stdlib.h> //C-Standard-Bibliothek
#include <time.h>   //C-Standard-Bib für Zeitfunktionen

//---- globale Variablen --------------
int zufall;   //Speicher für eine zufällige ganze Zahl
int Lotto[6]; //die 6 Lottozahlen in einem Array

time_t systemzeit; // 64-Bit Zeitdatentyp 
unsigned int seed; // Keim für rand() Initialisierung


bool EquFlag = false;  //Boolsche Variable /Flag für gleiche Zahl schon vorhanden

int randIntervall(unsigned int a, unsigned int b) {
	return  a + rand() % (b-a + 1);
}

int main() {
	//--- Random zufällig initialisieren ----
	systemzeit = time(NULL); //Anzahl der Sekunden seit dem 1.1.1970
	seed = (unsigned int)systemzeit; //Datentyp wandeln mit C-Typecast
	srand(seed); // Zufallsliste auf seed initialisieren

	//--- 6 Kugeln ziehen ---
	for (int i = 0; i<6; /* i++ nur wenn Zahl noch nicht vorhanden */  ) {
		zufall = randIntervall(1,49);
		
		//---Alle bisherigen (i-1)-Kugeln vergleichen --
		for (int j = 0; j<i; j++) 
		{
			if (zufall == Lotto[j]) //Zahl war schon mal da
				EquFlag = true;
		}

		//Äußere For-Schleif mit i nur hochzählen wenn neue Lottozahl noch nicht vorhanden war
		if (EquFlag == false) {
			Lotto[i] = zufall; // neue Lottozahl merken
			i++; //Index inkrementieren (fehlt jetzt oben => for (int i = 0; i<6; ) 
		}
	} //ende for(int i= ...

	//--------------- Ausgabe Lottouzahlen ---------------------
	printf("\n\nDie Ziehung der Lottozahlen\n");
	for (int i = 0; i < 6; i++)
		printf(" %d \t", Lotto[i]);
	printf("\n\n");
	system("PAUSE");
	return 0;
}





