//parameters.cpp
#include <iostream>
using namespace std;

//prototype
void a (int x, int y);
void b (int x, int &y);
void c (int &x, int &y);

int main ()
{
    int m = 3, n = 5;
    cout << "&m = " << &m << ", &n = " << &n << endl << endl;
    cout << "m = " << m << ", n = " << n << endl;
    a(m, n);
    cout << "m = " << m << ", n = " << n << endl;
    b(m, n);
    cout << "m = " << m << ", n = " << n << endl;
    c(m, n);
    cout << "m = " << m << ", n = " << n << endl;
    
    return 0;
}

void a (int x, int y) //parameters passed by value
{
    cout << "&x = " << &x << ", &y = " << &y << endl;
    x ++; y ++;
    cout << "x = " << x << ", y = " << y << endl;
}

void b (int x, int &y) //y parameters has been passed by reference
{
    cout << "&x = " << &x << ", &y = " << &y << endl;
    x ++; y ++;
    cout << "x = " << x << ", y = " << y << endl;
}

void c (int &x, int &y) //both parameters has been passed by reference
{
    cout << "&x = " << &x << ", &y = " << &y << endl;
    x ++; y ++;
    cout << "x = " << x << ", y = " << y << endl;
}