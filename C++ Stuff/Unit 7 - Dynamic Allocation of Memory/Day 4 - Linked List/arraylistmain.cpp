//arraylistmain.cpp

#include "fraction.h"
#include "linkedlist.h"
#include <iostream>

using namespace std;

void readfile(string filename);

void sortfrac();

linkedlist<Fraction> fraclist;

int main()
{
    readfile("frac.dat");
    for (int i = 0; i < fraclist.size(); i ++)
      cout << (fraclist.get(i)) << " ";
    cout << endl;
    sortfrac();
    for (int i = 0; i < fraclist.size(); i ++)
      cout << (fraclist.get(i)) << " ";
    cout << endl;
}