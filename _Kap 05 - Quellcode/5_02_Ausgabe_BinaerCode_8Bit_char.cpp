// Ausgabe_BinaerCode_8Bit_char.cpp 
//

#include "stdafx.h"
#include <iostream>
using namespace std;

unsigned char ganzeZahl = 65;
unsigned char maske = 0x80; //0b1000 0000

int main()
{
	// Ausgabe als Zeichen 65 = 'A' 
	cout << ganzeZahl << endl;
	// Ausgabe als Hexadezimalwert  
	cout << "0x" << hex << ganzeZahl << endl;
    // Ausgabe als Binärwert  
    // so geht es leider nicht:  cout << "0b" << bin << ganzeZahl << endl;

	// Ausgabe char -Typ als Integer-Zahl 
	cout << static_cast<int> (ganzeZahl) << endl;

	// Ausgabe als Binärwert  in einzelnen Bits
	cout << "0b "; //Prefix
	cout << static_cast<int>((ganzeZahl & maske) >> 7);
	maske = maske >> 1;
	cout << static_cast<int>((ganzeZahl & maske) >> 6);
	maske = maske >> 1;
	cout << static_cast<int>((ganzeZahl & maske) >> 5);
	maske = maske >> 1;
	cout << static_cast<int>((ganzeZahl & maske) >> 4);
	maske = maske >> 1;
	cout << " " << static_cast<int>((ganzeZahl & maske) >> 3);
	maske = maske >> 1;
	cout << static_cast<int>((ganzeZahl & maske) >> 2);
	maske = maske >> 1;
	cout << static_cast<int>((ganzeZahl & maske) >> 1);
	maske = maske >> 1;
	cout << static_cast<int>((ganzeZahl & maske) >> 0);

	cout << endl;
	system("pause");
	return 0;
}

