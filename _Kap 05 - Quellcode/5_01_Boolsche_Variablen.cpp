// Boolsche_Variablen.cpp :
//--------------------------------------------------------
#include "stdafx.h"
#include <iostream>
using namespace std;

bool Aussage = true;   //C++-Typ 

int main() {
	Aussage = false;    // Zuweisung typgerecht
	Aussage = 5 * 3;    // Zuweisung möglich aber nicht typgerecht

	if (Aussage == false) {  // Vergleich
		cout << "\n Aussage falsch! \n";
	}
	else
	{
		cout << "\n Aussage richtig!" << endl;
	}

	cout << endl;
	
	
	//unsigned char geht von 0..255
	unsigned char a = 128, b = 211;

	int c = static_cast< int > (a + b);
	cout << " c " << c << endl;
	
	c = static_cast<int> (a) + static_cast<int>(b);
	cout << " c " << c << endl;

	system("pause");
	return 0;
}


