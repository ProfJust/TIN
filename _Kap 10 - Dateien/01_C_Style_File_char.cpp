// 01_C_Style_File_char.cpp 
// Dateien Beschreiben, hier Quadratzahlen
// TINF Vorlesung Beipiel
// Version vom 09.10.2017
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#define STR_LEN 100 //Maximale Länge der Strings

//++++++++++++ Globale Variablen ++++++
FILE *datei_ptr;    // Ein Zeiger auf eine Datei
char DateiName[STR_LEN];     //Ein String
int i;

int main()
{
	system("COLOR F2");  //Farben der Konsole setzen

	//---- Konsoleneingabe eines Dateinamens ----
	puts("Geben Sie einen Dateinamen ein: ");
	//!!%! gets(DateiName); //Liest String inklusive Leerzeichen 
	// https://www.proggen.org/doku.php?id=c:lib:stdio:gets
	// In der Version C11 wurde gets() komplett aus C entfernt.
	// Stattdessen wurde eine sicherere Variante mit dem Namen gets_s() eingeführt, 
	// die als zusätzlichen Parameter noch die maximale Anzahl an zu lesenden Zeichen 
	// (inklusive '\0') übergeben bekommt: 
	// char *gets_s(char *str, rsize_t n);
	gets_s(DateiName, STR_LEN); //Liest String inklusive Leerzeichen 

//---  Datei mit dem gewünschten Namen öffnen/erstellen ---
	//!!!%!$& 	datei_ptr = fopen(DateiName, "w");
	// fopen_s is a "secure" variant of fopen with a few extra options for the mode string 
	// and a different method for returning the stream pointer and the error code. 
	//It was invented by Microsoft and made its way into the C Standard:
	// https://msdn.microsoft.com/de-de/library/z5hh6ee9.aspx
	// errno_t fopen_s( FILE** pFile, const char *filename, const char *mode );

	fopen_s(&datei_ptr, DateiName, "w");

	if (datei_ptr == NULL)
		puts("Fehler beim Oeffnen!\n");
	else
	{ //--- Erfolgreich geöffnet => in Datei schreiben ---
		fprintf(datei_ptr, "Die ersten 100 Quadratzahlen:\n");

		for (i = 0; i < 100; i++) {
			fprintf(datei_ptr, "%d quadrat = %d\n", i, i*i);
		}
		//--- Datei wieder schliessen ---
		if (fclose(datei_ptr) != 0)
			puts("Fehler beim Schliessen!\n");
	}
	system("PAUSE"); //Windows wartet auf Taste

	
//=============================================================================
	//------ Lesen und auswerten der Datei -----------
	int wert = 0;
	int sum = 0;
	int noQu = 0; // Anzahl Quadratzahlen

	fopen_s(&datei_ptr, DateiName, "r+");  //r+ => von Beginn an Lesen, Schreiben erlaubt
	if (datei_ptr == NULL)
		puts("Fehler beim Oeffnen!\n");
	else
	{
		// mit dem * wird dieser eingelesene String ignoriert
		fscanf_s(datei_ptr, "%*s %*s %d %*s", &noQu);
		printf("\n Lese %d Quadratzahlen aus Datei %s und bilde die Sunmme", noQu, DateiName);

		//EOF = End OF File => Lesen bis zum Ende der Datei
		while (fscanf_s(datei_ptr, "%*d %*s %*c %5d", &wert) != EOF) {
			sum += wert;
		}
		printf("\nSumme: %d \n", sum);
		fprintf(datei_ptr, "Summe: %d", sum);
		

		//--- Datei wieder schliessen ---
		if (fclose(datei_ptr) != 0)
			puts("Fehler beim Schliessen!\n");
	}

	//--- Öffnen des Windows-Editors (nortepad.exe) über die Kommandozeile ----
	char systemStr[40] = "notepad.exe ";
	strcat_s(systemStr, DateiName); //Zusammenbauen der Strings
	system(systemStr);

	return 0;
}


