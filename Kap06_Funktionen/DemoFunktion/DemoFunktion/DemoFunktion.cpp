// DemoFunktion.cpp: 

#include "stdafx.h"
#include <iostream>
using namespace std;

/* Definition der Funktion addiere() */
int addiere(int summand1, int summand2) {
	return (summand1 + summand2);
}

/* Aufruf der Funktion */
int main() {
	int summe = addiere(3, 7);
	cout << "Summe von 3 und 7 ist "<<summe<<"\n";
	return 0;
}

