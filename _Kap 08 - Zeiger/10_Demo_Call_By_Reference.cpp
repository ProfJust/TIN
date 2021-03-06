// 10_Demo_Call_By_Reference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define PI 3.141592
#include <iostream>
using namespace std;

//------  Globale Variablen ----
float eingabe = 0;
float ausgabe = 0;

//--- Funktion mit WerteÜbergabe ---
float kreisflaecheCallByValue(float radius) {
	float flaeche; //Lokale Variable
	flaeche = radius * radius * PI;
	return flaeche;
}

//--- Funktion nutzt die globale Variable eingabe ---
float kreisflaecheMitGlobals() {
	float flaeche; //Lokale Variable
	flaeche = eingabe * eingabe * PI;
	return flaeche;
}

//--- Funktion mit Adressübergabe ---
float kreisflaecheCallByReference(float *radiusPtr) {
	float flaeche; //Lokale Variable
	// *-Operator ist die Dereferezierung
	flaeche = *radiusPtr * *radiusPtr * PI;
	return flaeche;
}

//--- Funktion mit Adressübergabe ---
// Werte die nur in die Funktion gehen, 
// werden oftmals mit const gekennzeichnet
// hier 3 Parameter 
void kreisCallByReference(const float *radiusPtr, float * flaechePtr, float * umfangPtr) {
	*flaechePtr = *radiusPtr * *radiusPtr * PI;
	*umfangPtr =  2 * *radiusPtr * PI;
	//kein return mehr notwendig
}


//----------------------------------------------
int main()
{
	cout << "Berechnung der Kreisflaeche\n";
	cout << "Bitte geben Sie den Radius ein : ";
	cin >> eingabe;

	ausgabe = kreisflaecheCallByValue(eingabe);
	cout << " Die Flaeche des Kreises betraegt: " << ausgabe << endl;
	system("pause");
	
	ausgabe = kreisflaecheMitGlobals();
	cout << " Die Flaeche des Kreises betraegt: " << ausgabe << endl;
	system("pause");

	//Übergabe einer Adresse => &-Operator
	ausgabe = kreisflaecheCallByReference(&eingabe); 
	cout << " Die Flaeche des Kreises betraegt: " << ausgabe << endl;
	system("pause");

	//globale Werte, deren Adresse übergeben wird
	float Umfang, Flaeche;
	// Aufruf der Funktion mit den Adressen
	kreisCallByReference(&eingabe, &Umfang, &Flaeche);
	cout << " Die Flaeche des Kreises betraegt: " << Flaeche << endl;
	cout << " Der Umfang  des Kreises betraegt: " << Umfang  << endl;
	system("pause");

    return 0;
}

