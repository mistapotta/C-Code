//morris.cpp

#include <iostream>
#include <string>
#include "arrayqueue.h"

using namespace std;

queue<int> morris;

void doMorris()
{
    int data = morris.dequeue();
    int count = 1;
    while (morris.peek() != 0)
    {
        int newdata = morris.dequeue();
        if (data == newdata) //match
            count ++;
        else //doesn't match
        {
            morris.enqueue(count);
            morris.enqueue(data);
            data = newdata;
            count = 1;
        }
    }
    morris.enqueue(count);
    morris.enqueue(data);
    //take care of '0'
    morris.enqueue(morris.dequeue());
}

void setup()
{
    string input;
    cout << "Please enter a Morris sequence: " ;
    cin >> input;
    for (int i= 0; i < input.length(); i ++)
        morris.enqueue(input[i] - '0');
    //need terminator
    morris.enqueue(0);
}

void output()
{
    while (morris.peek() != 0)
    {
        int data = morris.dequeue();
        cout << data << " ";
        morris.enqueue(data);
    }
    //take care of zero
    morris.enqueue(morris.dequeue());
    cout << endl;
}

int main()
{
    setup();
    for (int i = 0; i < 10; i++)
    {
        doMorris();
        output();
    }
    return 0;
}