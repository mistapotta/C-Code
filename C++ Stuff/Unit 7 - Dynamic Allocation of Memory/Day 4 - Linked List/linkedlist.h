//arraylist.h
#define LINKEDLIST_H
#include "node.cpp"

#ifndef NULL
#define NULL 0
#endif

using namespace std;

template <class T>
class linkedlist 
{
    
    private:
        node<T>* head;
        
    public:
        //constructor
        linkedlist()
        {
            head = NULL;
        }
        //modifiers
        void add(T item);
        void add(int index, T item);
        void remove(int index);
        void remove(T item);
        void set(int index, T item);
        //accessors
        T get(int index);
        int indexOf(T item);
        int lastindexof(T item);
        int size();
        bool contains(T item);
};

#include "linkedlist.cpp"