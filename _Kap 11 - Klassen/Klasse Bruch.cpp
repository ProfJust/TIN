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
	/*printf("\n\n %3d", zaehler);
	printf("\n------");
	printf("\n %3d \n\n", nenner);*/
	/*cout << endl << setw(3) << zaehler << endl;
	cout << "----" << endl;
	cout << setw(3) << nenner;*/
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
	zaehler += summand*nenner;
	return *this;
}
//--- Überladen des "+"-Zeichens als Operator für die Addition zweier Brüche ---
Bruch Bruch::operator+(Bruch summand)
{
	zaehler = zaehler*summand.GetNenner()
		+ summand.GetZaehler()*nenner;
	nenner = nenner * summand.GetNenner();
	return *this;
}
Bruch Bruch::operator/(int divisor)
{
	if (divisor == 0) throw 0;
	nenner *= divisor;
	return *this;
}
//--------------------------------------------------------------------------
Bruch b1(1, 2), b2(5, 6);
int main() {
	try {
		cout << "b1 und b2 - Werte nach Konstruktor  " << endl;
		b1.Zeige();
		b2.Zeige();
		b1 / 0; 
		system("pause");
		return(0);
	}
	catch (int errNo) {
		if (errNo == 0) cout << "Div by Zero "<<endl;
		system("pause");
	}

	////--- Methoden der Klasse aufrufen   Objekt.Methode(Parameter) ---
	//b1.SetZaehler(1);
	//b1.SetNenner(2);
	//b2.SetZaehler(5);
	//b2.SetNenner(6);
	//printf("\n b1 ");
	//b1.Zeige();
	//printf("\n b2 ");
	//
	//printf("\n b1 erweitert mit 3 ");
	//b1.Erweitere(3);
	//b1.Zeige();

	///*printf("\n b1 + 2 ");
	//b1.Addiere(2);
	//b1.Zeige();

	//printf("\n b1 + b2 ");
	//b1.Addiere(b2);
	//b1.Zeige();*/

	//printf("\n b1 + 2 ");
	//b1 = b1 + 2;
	//b1.Zeige();

	//printf("\n b1 + b2 ");
	//b1 = b1 + b2;
	//b1.Zeige();


}
