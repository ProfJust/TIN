// 04_File_read_write_in_C++_Style.cpp 
//---------------------------------------
// Version vom 9.10.2017
//---------------------------------------
#include "stdafx.h"
#include <string>
#include <fstream> // http://www.willemer.de/informatik/cpp/fileop.htm
using namespace std;

string DateiNameStr = "meineDatei.txt"; //Name der Datei
string diesIstEinText = "Hallo liebe Studentinen und Studenten"; //Inhalt
string systemStr = "notepad.exe ";

//-------------------------------------------------------------------------
int main()
{
	fstream meineDatei;

	meineDatei.open(DateiNameStr, ios::out);
		meineDatei << "Dieser Text wird in die Datei <" << DateiNameStr << "> geschrieben" << endl;
		meineDatei << diesIstEinText << endl;
	meineDatei.close();
	
	systemStr += DateiNameStr;
	//system("notepad.exe meineDatei.txt");
	system(systemStr.c_str()); //c_str() gibt den String wie in C zurück

    return 0;
}

