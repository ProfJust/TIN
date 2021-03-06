// 09_Zähle_die_Buchstaben.cpp 
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//------  Globale Variablen ----
char gedicht[] = " Dem Ingenieur ist nichts zu schwere -\n"
"Er lacht und spricht : Wenn dieses nicht, so geht doch das!\n"
"Er überbrückt die Flüsse und die Meere,\n"
"Die Berge unverfroren zu durchbohren ist ihm Spass.\n"
"Er thürmt die Bogen in die Luft,\n"
"Er wühlt als Maulwurf in der Gruft,\n"
"Kein Hinderniss ist ihm zu gross -\n"
"Er geht drauf los!\n"
"  \n"
"Den Riesen macht er sich zum Knechte,\n"
"Dess’ wilder Muth, durch Feuersgluth aus Wasserfluth befreit,\n"
"Zum Segen wird dem menschlichen Geschlechte -\n"
"Und ruhlos schafft mit Riesenkraft am Werk der neuen Zeit.\n"
"Er fängt den Blitz und schickt ihn fort\n"
"Mit schnellem Wort von Ort zu Ort,\n"
"Von Pol zu Pol im Augenblick\n"
"Am Eisenstrick!\n"
"   \n"
"Was heut sich regt mit hunderttausend Rädern,\n"
"In Lüften schwebt, in Grüften gräbt und stampft und dampft und glüht,\n"
"Was sich bewegt mit Riemen und mit Federn,\n"
"Und Lasten hebt, ohn’ Rasten’ webt und locht und pocht und sprüht,\n"
"Was durch die Länder donnernd saust\n"
"Und durch die fernen Meere braust,\n"
"Das Alles schafft und noch viel mehr\n"
"Der Ingenieur!\n"
" \n"
"Die Ingenieure sollen leben!\n"
"In ihnen kreist der wahre Geist der allerneusten Zeit!\n"
"Dem Fortschritt ist ihr Herz ergeben,\n"
"Dem Frieden ist hienieden ihre Kraft und Zeit geweiht\n"
"Der Arbeit Segen fort und fort,\n"
"Ihn breitet aus von Ort zu Ort,\n"
"Von Land zu Land, von Meer zu Meer -\n"
"Der Ingenieur!\n"
"   \n"
"Heinrich Seidel - 1871 \n";

// --- Call By Reference für die Übergabe des Textes ---
unsigned int zaehlZeichen(char * strPtr, char zeichen) {
	unsigned int   i = 0;
	unsigned int cnt = 0;
	while (strPtr[i] != '\0'){ //String-Ende?
		if (strPtr[i++] == zeichen) cnt++;
	}
	return cnt;
}

//--- globale Variablen --
char eingabe;
unsigned int anzahl;
//----------------------------------------------
int main()
{
	system("color F2");

	cout << gedicht << endl;
	
	cout << "Welcher Buchstabe soll gezaehlt werden? ";
	cin >> eingabe;
	anzahl = zaehlZeichen(gedicht, eingabe);
	
	cout << "Der Buchstabe " << eingabe << " kommt " << anzahl << "mal vor.\n";
	system("pause");
	return 0;
}

