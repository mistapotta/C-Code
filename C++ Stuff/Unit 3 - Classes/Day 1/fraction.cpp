//fraction.cpp
#ifndef FRACTION_H
#include "fraction.h"
#endif

//code for the fraction class

//code for the constructor
Fraction::Fraction(int num, int den)
{
    numer = num;
    denom = den;
}

//accessors
int Fraction::getnumer()
{
    return numer;
}

int Fraction::getdenom()
{
    return denom;
}

double Fraction::getvalue()
{
    return (double)(numer) / denom;
}

//modifiers/mutators
void Fraction::setnumer(int newnum)
{
    numer = newnum;
}

void Fraction::setdenom(int newden)
{
    denom = newden;
}
