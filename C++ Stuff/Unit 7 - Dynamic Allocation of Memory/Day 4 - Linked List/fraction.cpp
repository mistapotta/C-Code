//fraction.cpp
#ifndef FRACTION_H
#include "fraction.h"
#endif

#include <iostream>
#include <cmath>
using namespace std;

//code for the fraction class

//code for the constructor
Fraction::Fraction(int num, int den)
{
    numer = num;
    denom = den;
    reduce();
}

Fraction::Fraction(int num)
{
    numer = num;
    denom = 1;
}

Fraction::Fraction()
{
    denom = 1;
    numer = 0;
}

Fraction::Fraction (double value)  //4.31 = 4.31/1 = 43.1/10 = 431/100
{
    int num = (int)(value);
    int den = 1;
    while (abs(value - num) > 0.000001)
    {
        value *= 10;
        num = (int)(value);
        den *= 10;
    }
    numer = num;
    denom = den;
    reduce();
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

int Fraction::gcd(int a, int b)  
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

void Fraction::reduce()
{
    int GCD = gcd(numer, denom);
    numer /= GCD;
    denom /= GCD;
}