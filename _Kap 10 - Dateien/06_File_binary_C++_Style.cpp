// 06_File_binary_C++_Style.cpp : 
// Binäere Dateien Beschreiben
// TINF Vorlesung Beipiel
// Version vom 14.11.2017
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "stdafx.h"
#include <Windows.h>
#include <fstream>
#include <iostream>
using namespace std;
#include <string.h>

// --- globale Variablen ---
int feld[6] = { 48,49,13,45,46,50 }; // Eine Liste mit Daten
int neufeld[6]; // Liste für die Daten aus der Datei
int anz;        // Anzahl der enthaltenen Daten
//----------------------------------------------------------
int main(){
	system("COLOR F2"); // Farben der Konsole setzen

//--- SCHREIBEN ---
	// Eine Datei namens testdatei wird zum Schreiben geöffnet
	fstream myBinaryFile("testdatei", ios::out | ios::binary);

	myBinaryFile.write((char *) &feld, sizeof(feld)); //Schreiben

	cout << "\n" << sizeof(feld)/sizeof(int) << " Daten werden binaer in Datei geschrieben: \n \n";

	myBinaryFile.close(); // Datei schliessen
	
//---LESEN ---
// Eine Datei namens testdatei wird zum Lesen geöffnet
	fstream myBinaryFile2("testdatei", ios::in | ios::binary);
	
	//--- Die Daten holen
	myBinaryFile2.read((char *)&neufeld, sizeof(neufeld));
	myBinaryFile.close(); // Datei schliessen

	anz = sizeof(neufeld)/sizeof(int);
	cout << anz <<" Daten gelesen >>\t";

	//--- Ausgeben ---
	for (int i = 0; i<6; i++)
		cout << neufeld[i] << "\t";
	
	cout << "\n\n";
	system("pause");
	return 0;
}

