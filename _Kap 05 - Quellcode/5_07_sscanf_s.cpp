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

//---------------------------------------------------------------
int main() {

	///////////////////////////////////////////////
	char str[] = "25";
	int n;

	//Liest die Zahl n aus einem int 
	//und schreibt sie in einen String  str
	sscanf_s(str, "%d", &n);
	//sscanf_s siehe https://msdn.microsoft.com/de-de/library/t6z7bya3.aspx


	//Ausgabe des String und der Integer-Zahl
	printf(" %s  %d \n", str, n);

	///////////////////////////////////////////////
	char sentence[] = "Rudolph ist 12 Jahre alt"; //char[25]
	char str1[10];
	char str2[10];
	int i;

	// Liest mehrere Strings und ints in eine Zeichenkette
	sscanf_s(sentence, "%s %s %d", str1, sizeof(str1), str2, sizeof(str2), &i);
	printf("%s %s  %d\n", str1, str2, i);

	///////////////////////////////////////////////
	//ignorieren von Teilstrings mit dem Asterisken 
	// d.h. einlesen aber nicht speicher ->%*S

	sscanf_s(sentence, "%20s %*s %d", str1, sizeof(str1), &i);
	printf("%s : %d\n", str1, i);

	Sleep(2000);
	exit(0); //Korrektes Ende 
}

