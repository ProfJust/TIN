// String_EinfuehrungsBsp.cpp 
// -----------------------------------------------------------
// TIN Vorlesung Beispiel 
// -----------------------------------------------------------

#include "stdafx.h"
#include <string.h>
//------ globale Variablen -----------
char einZeichen = 'a'; // ein einzelnes Zeichen 
					   // eine Zeichenkette  definieren (Länge 50) und Initialisieren
char Zeichenkette[50] = "Technische Informatik ";
//alternative Initialisierung der Zeichenkette: Elementweise
char String[11] = { 'i','s','t',' ','t','o','l','l','!','\0' };

int main() {

	//Ausgabe Einzelzeichen mit Code-Nr. und zugeordnetem Symbol
	printf("\n Zeichen-Nr. %d ist ein %c ", einZeichen, einZeichen);

	// Ausgabe der Zeichenketten
	printf("\n Zeichenkette: %s", Zeichenkette);
	printf("\n Zeichenkette: %s", String);

	//Bibliotheksfunktion aus string.h nutzen
	strcat(Zeichenkette, String); // verkettet Strings engl.:"concatenate"

								  //Ausgabe verkettete Strings
	printf("\n Verkettet: %s", Zeichenkette);
	getchar();
	return 0;
}