// 03_ASCII_ART.cpp :
//----------------------------------------------
// Version vom 9.10.2017
// jetzt mit den safen Fkt. fopen_s und fscanf_s
//----------------------------------------------
#include "stdafx.h"
#include <stdlib.h>  //wg. Dateifunktionen
#include <Windows.h> //wegen system()

#define DATEI_NAME "Käfer.txt"
//#define DATEI_NAME "Loewe.txt"

//--------- Globale Definitionen  ----------------
FILE *datei_ptr; // Ein Zeiger auf die Datei
				 //char ascii_art[ZEILEN * SPALTEN +1]; //Array für das Bild  //+1 wg EOF
char *ascii_art; //Array für das Bild, dynamischer Speicher => als Pointer
unsigned int charAnz;     //Anzal der Zeichen in der Datei

//--------- Die Funktionen ----------------------
//Zählt die Anzahl der Zeichen in der Datei und gibt sie zurück
unsigned int ZeichenZaehlen() {
	int scanOK;   //Rückgabewert fscanf()
	char zeichen; //aktuell aus der Datei gelesenes Zeichen
	unsigned int cnt = 0;      //zählt Zeichen

	//öffnet eine Datei
	//datei_ptr = fopen(DATEI_NAME, "r");
	fopen_s(&datei_ptr, DATEI_NAME, "r");

	if (datei_ptr == NULL) {
		printf("Fehler beim Oeffnen von %s\n", DATEI_NAME);
		return 0;
	}
	else {
		// Lesen der Zeichen
		do {
			scanOK = fscanf_s(datei_ptr, "%c", &zeichen,1);
			cnt++;
		} while (scanOK != EOF);
	}
	printf("\n Die Datei \"%s\" enthaelt %u Zeichen \n", DATEI_NAME, cnt);
	Sleep(2000);
	fclose(datei_ptr);
	return cnt;

}


void leseDatei() {
	char zeichen; //aktuell aus der Datei gelesenes Zeichen
	int scanOK;   //Rückgabewert fscanf()
				  //öffnet eine Datei
	//datei_ptr = fopen(DATEI_NAME, "r");
	fopen_s(&datei_ptr, DATEI_NAME, "r");

	if (datei_ptr == NULL)
		printf("Fehler beim Oeffnen von %s\n", DATEI_NAME);
	else {
		// Lesen der Zeichen		
		unsigned int i = 0;
		do {
			scanOK = fscanf_s(datei_ptr, "%c", &zeichen,1);
			// in das Array eintragen
			ascii_art[i] = zeichen;
			i++;
		} while (scanOK != EOF);
	}
}

void ausgabe(unsigned int n) {
	unsigned int i = 0;

	//--- Ausgabe zeichenweise ---
	do {
		printf("%c", ascii_art[i]);
		i++;

	} while (i <= n);
}

// --------------------------------------------------
void main() {
	system("COLOR F1");
	printf("------------ ASCII-ART ----------\n");
	// Anzahl der Zeichen ermitteln
	charAnz = ZeichenZaehlen();
	system("CLS");
	// reserviere Speicher
	ascii_art = (char *)malloc(sizeof(char) * charAnz + 1);

	leseDatei();
	ausgabe(charAnz);
	Sleep(8000);
}





