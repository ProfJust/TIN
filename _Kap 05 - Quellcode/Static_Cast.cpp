// Static_Cast.cpp: 
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	float a = 11.5, b = 3.7;

	float erg = a + b;
	cout << " a + b als float " << erg << endl;

	int c = static_cast< int > (a + b);
	cout << " (a + b) als int " << c << endl;

	c = static_cast<int> (a) + static_cast<int>(b);
	cout << " a als int + b als int " << c << endl;

	system("PAUSE");
	return 0;
}

