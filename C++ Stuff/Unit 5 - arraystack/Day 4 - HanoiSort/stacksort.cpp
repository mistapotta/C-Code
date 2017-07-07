//stacksort.cpp

#include <iostream>
#include "arraystack.h"

using namespace std;

stack<int> source;
stack<int> incr;
stack<int> decr;

void listToStack(int list[], int len)
{
    for (int i = 0; i < len; i ++)
        source.push(list[i]);
}

void moveIncToDec()
{
    bool done = false;
    do
    {
        if (incr.isEmpty())
        {
            while (!source.isEmpty() && source.peek() <= decr.peek())
                decr.push(source.pop());
            done = true;
        }
        else
        {
            if (source.isEmpty())
            {
                while (!incr.isEmpty())
                    decr.push(incr.pop());
                done = true;
            }
            else //they're not both empty
                if (source.peek() > incr.peek() && source.peek() <= decr.peek())
                    decr.push(source.pop());
                else
                    decr.push(incr.pop());
        }
    }
    while (!done);
}

void moveDecToInc()
{
    bool done = false;
    do
    {
        if (decr.isEmpty())
        {
            while (!source.isEmpty() && source.peek() >= incr.peek())
                incr.push(source.pop());
            done = true;
        }
        else
        {
            if (source.isEmpty())
            {
                while (!decr.isEmpty())
                    incr.push(decr.pop());
                done = true;
            }
            else
                if (source.peek() < decr.peek() && source.peek() >= incr.peek())
                    incr.push(source.pop());
                else
                    incr.push(decr.pop());
        }
    }
    while (!done);
}

void sort(int list[], int len)
{
    listToStack(list, len);
    
    while (!source.isEmpty())
    {
        //start
        if (decr.isEmpty() && incr.isEmpty())
            decr.push(source.pop());
        else
        {
            moveIncToDec();
            moveDecToInc();
        }//at end, decr is empty
    }
    int i = 0;
    while (!incr.isEmpty())
    {
        list[len-i-1] = incr.pop();
        i ++;
    }
}

int main()
{
    //int list[] = {1, 4, 9, 2, 8, 5, 7, 3, 6};
    //int list[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int list[] = {1, 2, 3, 4, 3, 2, 1, 2, 3, 2, 1};
    int len = sizeof(list)/sizeof(list[0]);
    sort(list, len);
    
    for (int i = 0; i < len; i ++)
        cout << list[i] << " ";
    cout << endl;
    
    return 0;
}