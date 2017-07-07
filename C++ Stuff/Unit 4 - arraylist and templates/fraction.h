//fraction.h
#define FRACTION_H

class Fraction
{
    public:
        //constructor
        Fraction (int num, int den);
        Fraction (int num);
        Fraction ();
        Fraction (double value);
        //accessors
        int getnumer();
        int getdenom();
        double getvalue();
        //modifiers/mutators
        void setnumer(int newnum);
        void setdenom(int newden);
        void reduce();
        
    private:
        //instance variables
        int numer;
        int denom;
        //helper functions
        int gcd(int a, int b);
        
};

#include "fraction.cpp"