// Klasse Bruch.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//neue Version 27.11.2016

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Bruch
{
public:
	Bruch() { zaehler = 0; nenner = 1; }    // Standardkonstruktor
	~Bruch() { }							// Destruktor
											
	Bruch(int z, int n) {  // Konstruktor mit Parametern
		zaehler = z; if (n != 0) nenner = n; else nenner = 1;
	}
	int GetNenner() { return nenner; }
	int GetZaehler() { return zaehler; }
	void SetNenner(int p) { if (p != 0) nenner = p; }
	void SetZaehler(int long p) { zaehler = p; }

	void Addiere(int);
	Bruch operator+(int);

	void Addiere(Bruch);
	Bruch operator+(Bruch);

	Bruch operator/(int);

	void Zeige();
	void Erweitere(int);

private:
	int zaehler;
	int nenner;
};

void Bruch::Zeige()
{
		cout << setw(3) << zaehler << " / " << nenner << endl;
}
void Bruch::Erweitere(int faktor)
{
	zaehler *= faktor;
	nenner *= faktor;
}

// Zweimal die Funktion Addiere, aber mit verschiedenen Parametern
// ---> mit integer
void Bruch::Addiere(int summand)
{
	zaehler += summand*nenner;
}
// ---> mit einem Bruch
void Bruch::Addiere(Bruch summand)
{
	zaehler = zaehler*summand.GetNenner()
		+ summand.GetZaehler()*nenner;
	nenner = nenner * summand.GetNenner();
}

//--- Überladen des "+"-Zeichens als Operator für die Addition einer ganzen Zahl zu einem Bruch ---
Bruch Bruch::operator+(int summand)
{
	Addiere(summand);
	return *this;
}
//--- Überladen des "+"-Zeichens als Operator für die Addition zweier Brüche ---
Bruch Bruch::operator+(Bruch summand)
{
	Addiere(summand);
	return *this;
}
Bruch Bruch::operator/(int divisor)
{
	if (divisor == 0) throw 0;
	nenner *= divisor;
	return *this;
}
//--------------------------------------------------------------------------
Bruch b1(1, 2), b2(1, 4);
int main() {
	try {
		cout << "b1 und b2 - Werte nach Konstruktor  " << endl;
		b1.Zeige();
		b2.Zeige();
		
		b1 = b1 + b2;
		b1.Zeige();

		b1 = b1 + 1;
		b1.Zeige();

		b1 / 0; 
		system("pause");
		return(0);
	}
	catch (int errNo) {
		if (errNo == 0) cout << "Div by Zero "<<endl;
		system("pause");
	}
	return(0);
}





/*b1.Addiere(b2);
		b1.Zeige();

		b1.Addiere(1);
		b1.Zeige();*/

////--- Methoden der Klasse aufrufen   Objekt.Methode(Parameter) ---
	//Bruch b1, b2;
	//b1.SetZaehler(1);
	//b1.SetNenner(2);
	//b2.SetZaehler(5);
	//b2.SetNenner(6);
	//printf("\n b1 ");
	//b1.Zeige();
	//cout << "\n b2 ";
	//
	//cout << "\n b1 erweitert mit 3 ";
	//b1.Erweitere(3);
	//b1.Zeige();

	//// Versehentliche Veränderung von b1.nenner
 //  // durch falschen Vergleichsoperator:
	//if (b1.nenner == b2.nenner) {
	//	cout << "\n Gemeinsamer Nenner: ", b1.nenner;
	//}
	//cout << "\n Bruch b1 nach Fehler"
	//b1.zeige(); 

	//if (b1.GetNenner() == b2.GetNenner()) {
	//	cout << "\n Gemeinsamer Nenner: ", b1.GetNenner();
	//}



