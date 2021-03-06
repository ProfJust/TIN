// cout_Example.cpp : 
//--------------------------------------------------
// Zeigt die Benutzung der Ausgabefunktion cout

#include "stdafx.h"
// --- Die Bibliothek einbinden in der cout steht
#include <iostream>  //C++-Bibliothek ohne .h
#include <iomanip>   //enthält u.a. setw()

int main()
{
	std::cout << "Dieser Text steht nun in der Kommandozeile! \n\n";

	using namespace std; //Vereinbarung des Namensraumes

	//Zeilenumbruch im Code mit \ + return
	cout << "Zeichen / ASCII-Code  : " << 'a' 
		 << ' ' << static_cast<char>(65) << endl;
	cout << "Dezimalwert           : " << 2017 \
		<< " " << 650000 << "\n";
	cout << "mindestens 10 Stellen : " << setw(10) \
		<< 2017 << endl;
	cout << "Fuehrende Nullen      : " << setw(10) \
		<< setfill('0') << 2017 << endl;
	cout << "Hexadezimale Werte    : " << 100 << " " \
		<< hex << 100 << " " << showbase << 100 << endl;
	cout << "Fliesskommawert float : " << 3.1416 << " " \
		<< scientific << 3.1416 << " " << setprecision(2) \
		<< 3.1416 << endl;

	cout << "Zeichenkette / String : " \
		<< "TIN macht Spass!! \n" << endl;

	int i = 0;
	cout << "Bitte eine ganze Zahl eingeben: ";
	cin >> i;
	cout << "\n Eingabe war " << dec << i << endl;
	return 0;
}
