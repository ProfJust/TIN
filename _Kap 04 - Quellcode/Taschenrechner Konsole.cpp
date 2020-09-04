// -----------------------------------------------------------
// Taschenrechner Konsole.cpp 
// Demo switch case Anweisung
// -----------------------------------------------------------
#include "stdafx.h"
#include <iostream>
#define VERSION2
using namespace std;

//--- globale Variablen -----
int x, y, ergebnis = 0;
char c;

#ifdef VERSION1
int main()
{
	system("COLOR F2"); //Konsolenfarbe setzen 

	do {	
		//--- Eingabe ----
		system("CLS");      //Clear Screen

		cout << "T A S C H E N R E C H N E R\n" ; //Titelzeile
		cout << "\n  x ? ";
		cin >> x;

		cout << "\n+ - * / % ?  ";
		cin >> c;

		cout << "\n y ? ";
		cin >> y;

		//--- Verarbeitung ----
		if (c == '+') {
			ergebnis = x + y;
		}
		if (c == '-') {
			ergebnis = x - y;
		}
		if (c == '*') {
			ergebnis = x*y;
		}
		if (c == '/') {
			ergebnis = x / y;
		}
		if (c == '%') {
			ergebnis = x%y;
		}
		//--- Ausgabe -------------
		cout << "\n\n Ergebnis: \n " << x << " " << c << " " << y << " = " << ergebnis << endl;

		cout <<"\n Weiter ? (j/n)";
		cin >> c;
	} while (c != 'n');
    return 0;
}

#endif
#ifdef VERSION2
//-------- Verbesserte Variante-------------
int main()
{
	system("COLOR F2"); //Konsolenfarbe setzen 

	do {
		//--- Eingabe ----
		system("CLS");      //Clear Screen

		cout << "T A S C H E N R E C H N E R\n"; //Titelzeile
		cout << "\n  x ? ";
		cin >> x;

		cout << "\n+ - * / %% ?  ";
		cin >> c;

		cout << "\n y ? ";
		cin >> y;

		//--- Verarbeitung ----
		switch (c) {
		case '+':    ergebnis = x + y; break;
		case '-':    ergebnis = x - y; break;
		case '*':    ergebnis = x*y; break;
		case '/':    ergebnis = x / y; break;
		case '%':    ergebnis = x%y; break;
		default: 
			cout << "\n \a Operator "<< c <<" nicht bekannt \n";
			system("pause");
			continue; //while Schleife von vorne beginnen
		}

		//--- Ausgabe -------------
		cout << "\n\n Ergebnis: \n " << x << " " << c << " " << y << " = " << ergebnis << endl;

		cout << "\n Weiter ? (j/n)";
		cin >> c;
	} while (c != 'n');
	return 0;
}
#endif