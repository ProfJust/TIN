// Satz des Heron.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

// ab VS2019 nicht mehr erforderlich:  #include "stdafx.h"
#include <iostream>
	using namespace std;

	double a, b, c; //Die Seiten des Dreiecks
	double s;		//Zwischenwert
	double A;		//Die Fläche

	int main() {
		//---- Eingabe ------------
		cout << "Eingabe a :"; 	cin >> a;
		cout << "Eingabe b :";	cin >> b;
		cout << "Eingabe c :";	cin >> c;

		if ((a < b + c) && (b < a + c) && (c < a + b)) {
			//---- Verarbeitung -----
			s = (a + b + c) / 2.0;
			A = sqrt(s * (s - a) * (s - b) * (s - c));
			//------ Ausgabe ----------------
			cout << "Flaeche:" << A << endl;
		}
		else  //--- Fehlerbehandlung ----
			cout << "Eingabefehler: Die Seiten " << a << " " << b << " " << c << " bilden kein Dreieck" << endl;

		system("pause"); //Windows wartet auf Taste	
		return 0;
	}



// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
