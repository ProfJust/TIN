// 01_BspFunktion_Potenz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/* --- Funktion zur Berechnung von Potenzen mit ganzzahligem, positiven Exponenten --- */
float hoch(float mantisse, unsigned int exponent) {
	float ergebnis = mantisse;
	for (unsigned int i = 1; i < exponent; i++) {
		ergebnis = ergebnis * mantisse;
	}
	return ergebnis;
}

// --- Gloable Variablen ---
float x; // Eingabe Mantisse
int y;   // Eingabe Exponent

//-----------------------------------------
int main()
{
	system("color F2");
	cout << " Potenzrechner x ^ y " << endl;
	cout << " x ? "; cin >> x;
	cout << " y ? "; cin >> y;
	cout << " Ergebnis: " << hoch(x, y) << endl;

	system("pause");
    return 0;
}

