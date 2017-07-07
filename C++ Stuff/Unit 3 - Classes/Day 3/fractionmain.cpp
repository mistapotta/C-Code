//fractionmain.cpp
#include <iostream>
#include "fraction.h"
using namespace std;

//Fraction Main to test Fraction class
//CS3DS - October 2015
//Mista Potta

int main()
{
    Fraction f1(22, 7);
    Fraction f2(355,113);
    Fraction f3;
    Fraction f4(3.14159);


    cout << f1.getnumer() << "/" << f1.getdenom() << endl;
    cout << f2 << endl;
    f3.setnumer(314);
    f3.setdenom(100);
    f3.reduce();
    cout << f3 << endl;
    cout << f4.getvalue() << endl;
    
    Fraction sum = f1 + f2;
    cout << sum << endl;
    Fraction diff = f1 - f2;
    cout << diff << endl;
    Fraction prod = f1 * f2;
    cout << prod << endl;
    Fraction quot = f1 / f2;
    cout << quot << endl;
    
    cout << f1 < f2 << endl;
    cout << f2 > f3 << endl;
    cout << f3 <= f4 << endl;
    cout << f4 >= f1 << endl;
    cout << f1 != f3 << endl;
    cout << f2 == f4 << endl;
    
    return 0;
}