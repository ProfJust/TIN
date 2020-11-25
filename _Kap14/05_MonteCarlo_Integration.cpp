// 05_MonteCarlo_Integration.cpp :
// Berechnung eines bestimmten Integrals einer FUnktion f(x)
// mit der Monte-Carlo-Methode
// NUR für Funktionen f(x) >= 0
// Intervall [VON, BIS]
// Version vom 6.10.2017
//***********************************************************
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <math.h>
#include <time.h>  //wegen time()

//+++++++++++++++ globals +++++++++++++++++++++++++++
unsigned int versuche = 0;		//Anzahl der Versuche
const unsigned int MAX_TRY = 10000000; //Höchster zugelassener Wert

float flaecheM = 0;				//Die aus den treffern errechnetete Fläche
float flaecheS = 0;				//Die aus der Stammfunktion errechnete Fläche
float Abweichung;				//Die Absolute Abweichung der Flächen
clock_t start_time, end_time;	//Datentyp für Zeitangaben des Systems
double dauer;
char taste;						// Taste zum einlesen mit cin

//++++++++++++++++++++++++++++++++++++++++++
//Die zu berechnende Funktion
char f_str[] = "x^2"; //Funktion als Zeichenkette
//Intervallgrenzen und MAXimum müssen hier eingetragen werden
#define VON 0
#define BIS 3
#define MAX 9 //MAXimalwert VON f(x) im Intervall
#define PREC 1000 // Genauigkeit der Float-Werte => tausendstel

float f(float x){
	if ((VON <= x) && (x <= BIS))
		return x*x;
	else
		return 0.0;
}

//Stammfunktion, nur zur Fehlerberechnung
float F(float x){
	if ((VON <= x) && (x <= BIS))
		return x*x*x / 3.0;
	else
		return 0.0;
}

//----- Funktion für float-Zufallszahlen mit Nachkommastellen ----
float randIntervall_Float(unsigned int a, unsigned int b, unsigned int precision){
	unsigned int eins = rand() % (precision + 1);   //Zufallswert [0..precision]
	float zwei = (float)eins / (float)precision;	//[0...1,000] 
	float drei = a + zwei * b;				        //[a .. b] mit 3 Nachkommastellen
	return drei;
}

//Fläche wird durch Trefferquote ermittelt
float monte_carlo(unsigned int n){
	float x, y;     //Koordinaten des aktuellen Testpunktes
	int treffer = 0; //Anzahl der Punkte zwischen X-Achse und Kurve
	srand(time(NULL)); //Initialisierung auf die Systemzeit 

	for (int i = 0; i < n; i++)
	{
		//Testpunktkoordinaten bestimt der Zufall
		y = randIntervall_Float(0, MAX, PREC);
		x = randIntervall_Float(VON, BIS, PREC);

		//Liegt der Graph oberhalb? => Treffer
		if (f(x) > y)	treffer++;
		
		//Ausgabe des Schleifenzählers 
		if (i % 100 == 99) { //nur jedes 100mal
			cout << "\b\b\b\b\b\b\b\b\b\b\b\b"; //Zeile Löschen durch Backspace
			cout << " n= " << i + 1;
		}
	}
	return ((float)treffer / n*(BIS - VON)*MAX); //Größe Rechteck *  Trefferquote    
}

//++++++++++++++++++++++++++++++++++++++++++
int main() {
	do {
	 //---------- Eingabe ----------------
		cout << "\n ---- Flaechenberechnung mit der Monte Carlo Methode ----";
		cout << "\n Funktion " << f_str << " im Intervall [" << VON << ".. " << BIS << " ]";
		cout << "\n Anzahl der Zufallsversuche? <quit=0>: ";
		cin >> versuche;
		if (versuche > MAX_TRY) {
			cout << "\n\a Fehler: Zahl zu Gross! (Dauert zu lange) \n";
			cin.clear(); // löscht EIngabepuffer
			continue;
		}
		if (versuche == 0) exit(1); //Programm ggf.beenden

	 //---------Verarbeitung--------- 
		start_time = clock(); //Systemzeit holen 
		flaecheM = monte_carlo(versuche);
		end_time = clock(); //Systemzeit holen 
		dauer = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		// CLOCKS_PER_SEC ist ein Prozessorabhängiges define
		// Bei mir 1000 Takte pro Sekunde also 1ms Takt

		flaecheS = F(BIS) - F(VON);
		Abweichung = abs(flaecheM - flaecheS);

	 //---------Ausgabe---------
		cout << "\n\n Ergebnis Monte Carlo:\t\t " << flaecheM;
		cout << "\n Ergebnis mit Stammfunktion:\t " << flaecheS;
		cout << "\n Abweichung in %:\t\t " << Abweichung / flaecheS * 100;
		cout << "\n Dauer der Berechnung \t\t " << dauer << " sec \n\n";
		cout << "----------------------------------------------------\n";

	} while (1);
	return 0;
}

