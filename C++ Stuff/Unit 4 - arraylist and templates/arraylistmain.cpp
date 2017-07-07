//arraylistmain.cpp

#include "fraction.h"
#include <iostream>

using namespace std;

void readfile(string filename);

void sortfrac();

ArrayList fraclist;

int main()
{
    fraclist = new ArrayList<Fraction>;    
    readfile("frac.dat");
    for (int i = 0; i < fraclist.size(); i ++)
      cout << fraclist.get(i) << " ";
    cout << endl;
    sortfrac();
    for (int i = 0; i < fraclist.size(); i ++)
      cout << fraclist.get(i) << " ";
    cout << endl;
}