// 01_Veerbung_Beispiel.cpp :
#include "stdafx.h"
#include <string>
using namespace std;

class Person
{
public:
	string Name, Adresse, Telefon;
};


class Mitarbeiter : public Person
{
public:
	string IBAN;
	string Krankenkasse;
};


int main()
{
	Person person;
	Mitarbeiter mitarbeiter;

	person = mitarbeiter; // ok, aber Datenverluste
	mitarbeiter = person; // das mag der Compiler nicht
    return 0;
}

