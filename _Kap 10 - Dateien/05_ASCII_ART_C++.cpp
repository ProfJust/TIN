// 03_ASCII_ART.cpp :
//----------------------------------------------
// Version vom 14.11.2017 für Visual Studio 2017
// jetzt mit fstream
//----------------------------------------------
#include "stdafx.h"
#include <Windows.h> //wegen system()
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//#define DATEI_NAME "Käfer.txt"
#define DATEI_NAME "Loewe.txt"

//--------- Globale Definitionen  ----------------
ifstream ArtFile;
string asciiArtStr;

//--------- Die Funktionen ----------------------
void leseDatei() {
	ArtFile.open(DATEI_NAME, ios::in);
	while (!ArtFile.eof())          // Solange noch Daten vorliegen
	{
		string readStr;
		getline(ArtFile, readStr); // Lese eine Zeile
		asciiArtStr += readStr;
		asciiArtStr += "\n";
	}
}

// --------------------------------------------------
void main() {
	system("COLOR F2");
	cout << "------------ ASCII-ART ----------\n";
	system("CLS");
	leseDatei();
	cout << asciiArtStr;

	system("pause");
}





