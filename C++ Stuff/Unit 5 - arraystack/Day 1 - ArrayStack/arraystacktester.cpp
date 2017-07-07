//arraystacktester.cpp

#include <iostream>
#include "arraystack.h"

using namespace std;

int main()
{
    stack<int> s;
    cout << s.isEmpty() << endl; //1
    for (int i = 0; i < 5; i ++)
        s.push(i*(i+1));//0 2 6 12 20
    cout << s.peek() << endl; //20
    while (!s.isEmpty())
        cout << s.pop() << " ";//20 12 6 2 0
    cout << endl;
    
    return 0;
}