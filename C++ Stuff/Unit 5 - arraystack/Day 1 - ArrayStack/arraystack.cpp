#ifndef STACK_H
#include "arraystack.h"
#endif

#include <stdexcept>

template <class T>
void stack<T>::push (T item)
{
    if (needToResize())
        resize();
    data[top] = item;
    top ++;
}

template <class T>
T stack<T>::peek()
{
    if (top <= 0)
        throw std::out_of_range("Attempted to peek an empty stack.");
    return data[top - 1];
}

template <class T>
T stack<T>::pop()
{
    if (top <= 0)
        throw std::out_of_range("Attempted to pop an empty stack.");
    top --;
    return data[top];
}

template <class T>
bool stack<T>::needToResize()
{
    return (top == size);
}

template <class T>
void stack<T>::resize()
{
    T* newdata = new T[2*size];
    for (int i = 0; i < size; i ++)
        newdata[i] = data[i];
    data = newdata;
    size *= 2;
    
}

template <class T>
bool stack<T>::isEmpty()
{
    return (top == 0);
}