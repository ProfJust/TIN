// Ausgabe_ASCII.cpp 
// -----------------------------------------------------------
// TINF Vorlesung Beispiel 
// Ausgabe aller ASCII-Zeichen von 0.255
// Version vom 7.9.2020  by OJ
// -----------------------------------------------------------
#include <iostream>

//---- globale Variablen ----
int zeichenNr = 0; // Aktulles ASCII-Zeichen / Code-Nr.

int main()
{
	std::cout << " Ausgabe aller Zeichen(Nr. 0..255) des \
                   erweiterten ASCII-Zeichensatzes \n";
	 
	            // Zeilenumbruch langer Text mit Backslash \

	std::cout << "----------------------------------------\
                  -------------------------------\n";
	do {
		std::cout <<" Das Zeichen mit der Nr." << zeichenNr 
			      <<" sieht so aus: " << static_cast<char>(zeichenNr) <<std::endl;
		zeichenNr++;
	} while (zeichenNr <= 255);

	return 0;
}
