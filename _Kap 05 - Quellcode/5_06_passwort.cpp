// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// passwort.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
// BSP02_06

#include "stdafx.h"
#include <stdio.h>    
#include <string.h>
#include <stdlib.h>   //exit()
#include <windows.h>  //für Sleep() und System()

char passwort[] = "TI NF";
char eingabe[20];
//---------------------------------------------------------------
int main() {

	//Konsole  Grün auf Weiß einstellen (DOS-Befehl)
	system("COLOR F2");

	printf("Bitte Passwort eingeben! \n");
	gets_s(eingabe);

	//--- Vergleich der Strings mit strcmp() ----
	if (strcmp(passwort, eingabe) == 0) {
		puts("Passwort OK");
	}
	else {
		printf("\n Falsches Passwort !  \n Programm wird beendet");
		Sleep(2000);  //Wartet 2000ms
		exit(1);      //Fehler => Programm abbrechen
	}
	printf("Programm wird ausgefuehrt .....");
	Sleep(2000);
	//--- hier kommt jetzt der weiter Programmcode hin ---

	exit(0); //Korrektes Ende 
}

