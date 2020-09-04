// tryThrowCatch.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
// -----------------------------------------------------------
// TIN Vorlesung Beispiel 
// Demo Fehlerbehandlung
// Version vom 3.10.2018  by OJ
// -----------------------------------------------------------
#include "stdafx.h"
#include <iostream>
using namespace std;
/*++++ globale variablen ++++*/
float z = 0;    
float n = 0;
float erg = 0; //Ergebnis 

int main()
{
	cout << "\n Berechen eines Bruches z / n  \n";
	cin >> z;
	cin >> n;

	try {
		if (n == 0)  throw(0);
		erg = z / n;
					
		cout << "\n "<<z<< "/"<<n<< " als Dezimalwert:  " << erg << endl;
		system("pause");
		return 0; //i.o.
	}

	catch (int errorNr)
	{
		if (errorNr == 0)
			cout << "\n Error: DIV BY ZERO  ";
		else
			cout << "\n Error Nr. " << errorNr;
		system("pause");
		return 1; //n.i.o.
	}
}

