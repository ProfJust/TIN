// Demo_cin.cpp: 
//
#include "stdafx.h"
#include <iostream>
using namespace std;

int i = 2;
char c = 'a';

int main() {


	cout << "Geben Sie eine Zahl ein!  ";
	cin >> i;
	cout << "Inhalt von int i " << i << endl;

	/*Bei falscher Eingabe sollte der Tastaturpuffer geloescht werden	*/
	if (cin.fail()) // Error flag gesetzt?
	{
		cin.clear();  // Error Flag loeschen 
	//ignoriert maximal 100 Zeichen im Tastaturpuffer oder wenn ein \n auftritt
		//cin.ignore(100, '\n');
		//cin.ignore(std::numeric_limits<int>::max(), '\n'); //maximale Int-Zahl

	}

	cout << "Geben Sie einen Buchstaben ein!  ";
	cin >> c;
	cout << "\n Inhalt von char c: " << c << endl;


	
	
	// istream::ignore example http://www.cplusplus.com/reference/istream/istream/ignore/

	//char first, last;

	//std::cout << "Please, enter your first name followed by your surname: ";

	//first = std::cin.get();     // get one character
	//std::cin.ignore(256, ' ');   // ignore until space

	//last = std::cin.get();      // get one character

	//std::cout << "Your initials are " << first << last << '\n';


	return 0;
}



// #include <string>
//string str; //Zeichenkette
//cout << "Geben Sie str ein!  ";
//std::getline(std::cin, str);
//cout << "Inhalt von str " << str << endl;


