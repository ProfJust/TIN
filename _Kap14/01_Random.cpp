// 01_Random.cpp : 
// Ermittelt  6 Zufallszahlen im Intervall [1 .. 49]
// Version vom 6.10.17
//***************************************************

#include "stdafx.h"
#include <stdlib.h> //C-Standard-Bibliothek, enthält u.a. die Fkt. rand()

//---- globale Variablen --------------
int zufall;   //Speicher für eine zufällige ganze Zahl
int Lotto[6]; //die 6 Lottozahlen in einem Array



int main(){
	//TEST der Konstante RAND_MAX
	//printf("Die groesste mögliche Zufallszahl %d \n", RAND_MAX);

	printf("\n\nDie Ziehung der Lottozahlen\n");

	//--- 6 Kugeln ziehen ---
	for (int i = 0; i<6; i++) {
		do{
			// Zahlen von 1 bis 49, sonst wiederhole
			zufall = rand();
		} while (zufall>49 || zufall <= 0);

		Lotto[i] = zufall;
		printf("%d \t", Lotto[i]); //direkte Ausgabe
	}
	
	printf("\n\n");
	system("PAUSE"); 
    return 0;
}




