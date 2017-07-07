//linkedlist.cpp
#ifndef LINKEDLIST_H
#include "linkedlist.h"
#endif 

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
void linkedlist<T>::add(T item)
{
    node<T>* n = new node<T>;
    n -> data = item;
    if (head == NULL) 
        head = n;
    else
    {
        node<T>* trav = head;
        while (trav -> next != NULL)
            trav = trav -> next;
        trav -> next = n;
    }
}

template <class T>
void linkedlist<T>::add(int index, T item)
{
    node<T>* n = new node<T>;
    n -> data = item;
    int i = 0;
    node<T>* trav = head;
    while (trav != NULL && i < index)
    {
        trav = trav -> next;
        i ++;
    }
    if (trav == NULL) throw std::out_of_range("Error: Can't add in that position.");
    if (trav -> next == NULL)
        trav -> next = n;
    else
    {
        n -> next = trav -> next;
        trav -> next = n;
    }
}

template <class T>
void linkedlist<T>::remove(int index)
{
    node<T>* trav = head;
    int i = 0;
    while (trav != NULL && i < index-1)
    {
        trav = trav -> next;
        i ++;
    }
    if (trav == NULL) throw std::out_of_range("Error: Can't remove that position.");
    if (trav -> next != NULL && trav -> next -> next != NULL)
    {
        node<T>* del = trav -> next;
        trav -> next = trav -> next -> next;
        delete (del);
    }
    else
    {
        delete (trav -> next);
        trav -> next = NULL;
    }
}

template <class T>
void linkedlist<T>::remove(T item)
{
    node<T>* trav = head;
    while (trav != NULL && trav -> data != item)
    {
        trav = trav -> next;
    }
    if (trav == NULL) throw std::out_of_range("Error: Item not found.");
    if (trav -> next != NULL && trav -> next -> next != NULL)
    {
        node<T>* del = trav -> next;
        trav -> next = trav -> next -> next;
        delete (del);
    }
    else
    {
        delete (trav -> next);
        trav -> next = NULL;
    }
}

template <class T>
T linkedlist<T>::get(int index)
{
    node<T>* trav = head;
    int i = 0;
    while (trav != NULL && i < index)
    {
        trav = trav -> next;
        i ++;
    }
    if (trav == NULL) throw std::out_of_range("Error: Can't get at that position.");
    else return trav -> data;
}

template <class T>
void linkedlist<T>::set(int index, T item)
{
    node<T>* trav = head;
    int i = 0;
    while (trav != NULL && i < index)
    {
        trav = trav -> next;
        i ++;
    }
    if (trav == NULL) throw std::out_of_range("Error: Can't set at that position.");
    else trav -> data = item;
}

template <class T>
int linkedlist<T>::indexOf(T item)
{
    node<T>* trav = head;
    int i = 0;
    while (trav != NULL)
    {
        if (trav -> data == item) return i;
        i ++;
    }
    return -1;
}

template <class T>
int linkedlist<T>::lastindexof(T item)
{
    node<T>* trav = head;
    int i = 0;
    int spot = -1;
    while (trav != NULL)
    {
        if (trav -> data == item) spot = i;
        i ++;
    }
    return spot;
}

template <class T>
bool linkedlist<T>::contains(T item)
{
    return (indexOf(item)) > -1;
}

template <class T>
int linkedlist<T>::size()
{
    node<T>* trav = head;
    int i = 0;
    while (trav != NULL)
    {
        i ++;
    }
    return i;
}