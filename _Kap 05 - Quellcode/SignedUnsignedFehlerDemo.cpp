// SignedUnsignedFehlerDemo.cpp:
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	int sigInt = -1;
	unsigned int unsigInt = 1;

	if (sigInt > unsigInt)
		cout << " -1 > 1    ,oder? \n";
	else
		cout << " -1 <= 1          \n";

	return 0;
}

