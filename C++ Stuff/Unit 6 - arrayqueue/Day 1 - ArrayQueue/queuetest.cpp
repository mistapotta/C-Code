//queuetest.cpp

#include <iostream>
using namespace std;

#include "arrayqueue.h"
int main()
{
    queue<int> q;
    for (int i = 0; i < 10; i ++)
        q.enqueue(i*(i+1));
    while (!q.isEmpty())
    {
        cout << q.dequeue() << " ";
        q.enqueue(q.dequeue());
    }
}