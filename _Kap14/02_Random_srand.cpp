// 02_Random_srand.cpp : Defines the entry point for the console application.
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


int main() {
	//--- Random zufällig initialisieren ----
	systemzeit = time(NULL); //Anzahl der Sekunden seit dem 1.1.1970

	seed = (unsigned int)systemzeit; //Datentyp wandeln mit C-Typecast

	srand(seed); // Zufallsliste auf seed initialisieren


	printf("\n\nDie Ziehung der Lottozahlen\n");

	//--- 6 Kugeln ziehen ---
	for (int i = 0; i<6; i++) {
		do {
			// Zahlen von 1 bis 49, sonst wiederhole
			zufall = rand();
		} while (zufall>49 || zufall <= 0);

		Lotto[i] = zufall;
		printf("%d \t", Lotto[i]); //direkte Ausgabe
	}

	printf("\n\n");
	system("PAUSE");
	return 0;
}




