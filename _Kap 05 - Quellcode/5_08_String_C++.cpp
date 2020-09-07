// String_C++.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
string meinName = "neu";
char oldName[25] = "alt";
string neuString;

int main()
{
	system ("color F2");
	neuString = meinName;            // "neu"
	cout << neuString << endl;

	neuString = oldName;
	cout << neuString << endl;// "alt"

	neuString = meinName + oldName;  // "neualt"
	cout << neuString << endl;

	neuString += oldName;            // "neualtalt"
	cout << neuString << endl;

	system("pause");

	//===================================================================

	string s("123"); // Konstruktor mit Initialisierung
	int len = s.length(); // Länge des Strings- hier 3
	cout << len << endl;

	s.insert(2, "xy");   // an Stelle [2] xy einfügen
	cout << s << endl;

	int pos = s.find("x"); // suche x, hier Stelle [2]
	cout <<"x an Position"<< pos << endl;

	s.erase(pos, 1);  //Lösche 1 Zeichen an Stelle pos
	cout << s << endl;

	system("pause");
	//===================================================================


	int meineZahl;
	string str2("123");
	istringstream inStream(str2);
	inStream >> meineZahl;

	cout << "str2  " << str2 << endl;
	cout << "meineZahl  " << meineZahl << endl;

	meineZahl = 976;
	ostringstream outStream;
	outStream << meineZahl;
	str2 = outStream.str();
	cout << "str2  " << str2 << endl;


	system("pause");
	return 0;
}

