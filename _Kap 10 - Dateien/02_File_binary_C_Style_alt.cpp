// 02_File_binary_C_Style.cpp : 
// Binäere Dateien Beschreiben
// TINF Vorlesung Beipiel
// Version vom 09.10.2017
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>

// --- globale Variablen ---
FILE *filePtr; //Zugriffsadresse der Datei
int feld[6] = { 48,49,13,45,46,50 }; // Eine Liste mit Daten
int neufeld[6]; // Liste für die Daten aus der Datei
int anz;        // Anzahl der enthaltenen Daten
int main()
{
	system("COLOR F2"); // Farben der Konsole setzen
//--- SCHREIBEN ---
	//filePtr = fopen("test.bin", "wb");   //Alte Version ASNSI-C
	fopen_s(&filePtr, "test.bin", "wb");   //zum Schreiben öffnen
	
	anz = fwrite(feld, sizeof(int), 6, filePtr); //Feld in Datei Schreiben
	printf("\n%d Daten werden binaer in Datei geschrieben: \n \n",anz);
	fclose(filePtr); // Datei schliessen

	 // Öffnet man die Datei mit dem Editor, sieht man dort die ASCII-Zeichen 48 = '0',11,...

//---LESEN ---
	fopen_s(&filePtr, "test.bin", "rb");
	//filePtr = fopen("test.bin", "rb"); //Alte Version ASNSI-C

	//--- Die Daten holen, Menge wird an anz zurückgegeben
	anz = fread(neufeld, sizeof(int), 6, filePtr);
	printf("%d Daten gelesen: ", anz);

	//--- Ausgeben ---
	for (int i = 0; i<6; i++)
		printf("%d ", neufeld[i]);

	getchar(); // Warte auf Taste
	return 0;
}

