// TIN_Kap08_Zeiger.cpp : 
// OJ 4 TIN am 6.11.20


#include <iostream>
using namespace std;

int main()
{
    int zahl;
    int i = 2;
    int* zeiger;

    zeiger = &i;
    zahl = 5 * *zeiger;

    printf("%d \n", zahl);
    cout << zahl << endl;

}
