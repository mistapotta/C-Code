//fractionmain.cpp
#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
    Fraction f1(2, 3);
    Fraction f2(5, 8);

    cout << f1.getnumer() << "/" << f1.getdenom() << endl;
    f2.setnumer(6);
    f2.setdenom(9);
    
    cout << f2.getvalue() << endl;
    
    Fraction f3 = f1 + f2;
    cout << f3 << endl;
    Fraction f4 = f1 - f2;
    cout << f4 << endl;
    Fraction f5 = f1 * f2;
    cout << f5 << endl;
    Fraction f6 = f1 / f2;
    cout << f6 << endl;
    
    
    return 0;
}