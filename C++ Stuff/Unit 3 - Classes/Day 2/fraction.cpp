//fraction.cpp
#ifndef FRACTION_H
#include "fraction.h"
#endif

#include <iostream>
using namespace std;

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

Fraction &operator+ (Fraction &lhs, Fraction &rhs)
{
    int commondenom = lhs.getdenom() * rhs.getdenom();
    int newnumer = lhs.getnumer() * rhs.getdenom() + rhs.getnumer() * lhs.getdenom();
    Fraction *sum = new Fraction(newnumer, commondenom);
    return *sum;
}

Fraction &operator- (Fraction &lhs, Fraction &rhs)
{
    int commondenom = lhs.getdenom() * rhs.getdenom();
    int newnumer = lhs.getnumer() * rhs.getdenom() - rhs.getnumer() * lhs.getdenom();
    Fraction *diff = new Fraction(newnumer, commondenom);
    return *diff;
}

Fraction &operator* (Fraction &lhs, Fraction &rhs)
{
    int commondenom = lhs.getdenom() * rhs.getdenom();
    int newnumer = lhs.getnumer() * rhs.getnumer();
    Fraction *product = new Fraction(newnumer, commondenom);
    return *product;
}

Fraction &operator/ (Fraction &lhs, Fraction &rhs)
{
    int commondenom = lhs.getdenom() * rhs.getnumer();
    int newnumer = lhs.getnumer() * rhs.getdenom();
    Fraction *quotient = new Fraction(newnumer, commondenom);
    return *quotient;
}

ostream &operator<< (ostream &out, Fraction &rhs)
{
    out << rhs.getnumer() << "/" << rhs.getdenom();
}