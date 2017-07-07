//arraylist.cpp
#ifndef ARRAYLIST_H
#include "arraylist.h"
#endif 

template <class T>
void arraylist<T>::resize()
{
    if (listsize == arrlength)
    {
        T *temp = new T[arrlength * 2];
        for (int i = 0; i < arrlength; i ++)
            temp[i] = data[i];
        data = temp;
        arrlength *= 2;
    }
}

template <class T>
bool arraylist<T>::needtoresize()
{
    return arrlength == listsize;
}

template <class T>
void arraylist<T>::add(T item)
{
    if (needtoresize())
        resize();
    data[listsize] = item;
    listsize ++;
}

template <class T>
void arraylist<T>::add(int index, T item)
{
    if (needtoresize())
        resize();
    for (int i = listsize; i >= index; i --)
        data[i+1]=data[i];
    data[index]=item;
    listsize++;
}