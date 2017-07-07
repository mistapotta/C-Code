//pointers.cpp
#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 7, c = 10, d = 14;
    cout << a << " " << b << " " << c << " " << d << endl;
    
    int *pa = &a, *pb = &b, *pc = &c, *pd = &d;
    cout << pa << " " << pb << " " << pc << " " << pd << endl;
    
    pa ++;
    pb ++;
    pc ++;
    pd ++;
    cout << pa << " " << pb << " " << pc << " " << pd << endl;
    
    int da = *pa;
    int db = *pb;
    int dc = *pc;
    int dd = *pd;
    
    cout << da << " " << db << " " << dc << " " << dd << endl;
    cout << &da << " " << &db << " " << &dc << " " << &dd << endl;

    bool s;
    bool *ps = &s;
    for (int i = 0; i < 5; i ++)
    {
        cout << ps << " ";
        ps ++;
    }
    cout << endl;

    
    return 0;
}