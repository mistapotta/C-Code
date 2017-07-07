//arraylist.cpp
#ifndef ARRAYLIST_H
#include "arraylist.h"
#endif 

#ifndef NULL
#define NULL 0
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

template <class T>
void arraylist<T>::remove(int index)
{
    // 0 1 3 4 
    for (int i = index; i < listsize; i ++)
        data[i] = data[i+1];
    listsize --;
}

template <class T>
T* arraylist<T>::get(int index)
{
    if (index <= listsize && index >= 0)
        return &data[index];
    //else
    return NULL;
}

template <class T>
void arraylist<T>::set(int index, T item)
{
    if (index <= listsize && index >= 0)
        data[index] = item;
}

template <class T>
int arraylist<T>::indexOf(T item)
{
    for (int i = 0; i <= listsize; i ++)
        if (item == data[i])
            return i;
    //didn't find it
    return -1;
}

template <class T>
int arraylist<T>::lastindexof(T item)
{
    for (int i = listsize; i >= 0; i --)
        if (item == data[i])
            return i;
    //didn't find it
    return -1;
}

template <class T>
bool arraylist<T>::contains(T item)
{
    return (indexOf(item)) > -1;
}

template <class T>
int arraylist<T>::size()
{
    return listsize;
}