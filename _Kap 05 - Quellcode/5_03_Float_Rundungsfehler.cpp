// Float_Rundungsfehler.cpp 
// -----------------------------------------------------------
// TINF Vorlesung Beispiel 
// Ausgabe von zwei verknüpften float-Werten
// zur Darstellung der Genauigkeitsverluste
// Version vom 6.09.2020  by OJ
// -----------------------------------------------------------
#include <iostream>
#include <iomanip>  //fixed für Festkomma-Ausgabe von cout
using namespace std;

//------  Variablen (global) ------ 
float fl_gross = 1e7;        // sehr großer Float-Wert
float fl_klein = 1.234567;   // sehr kleiner Float-Wert
float fl_erg;                // Ergebnis der Berechnung

int main() {
	// Ausgabe Kopfzeile
	system("COLOR F2");
	cout << "Berechnung des Rundungsfehlers bei der Addition von float-Variablen \n";

	// Berechnung der Verluste, 
	// fl_gross wird bei jedem Durchlauf kleiner
	while (fl_gross >= 1)
	{
		fl_erg = fl_gross + fl_klein;  //Berechnung der Addition

		//printf("\n %16.6f + %f = %16.6f", fl_gross, fl_klein..
		cout << "\n" << fixed << fl_gross << " + "
			 << fl_klein << " = " << fl_erg << endl;

		// Rundungsfehler ermitteln und ausgeben 
		// (Subtraktion müsste eigentlich Null ergeben)
		cout << " Rundungsfehler " << fixed 
			 << (fl_erg - fl_gross - fl_klein) << endl;


		fl_gross /= 10;  //um eine Zehnerpotenz verringern
	}
	return 0;
}

