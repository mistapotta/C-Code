//fraction.h
#define FRACTION_H

class Fraction
{
    public:
        //constructor
        Fraction (int num, int den);
        //accessors
        int getnumer();
        int getdenom();
        double getvalue();
        //modifiers/mutators
        void setnumer(int newnum);
        void setdenom(int newden);
    
    private:
        //instance variables
        int numer;
        int denom;
        //helper functions
};

#include "fraction.cpp"