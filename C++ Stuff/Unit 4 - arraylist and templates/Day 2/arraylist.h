//arraylist.h
#define ARRAYLIST_H
template <class T>
class arraylist 
{
    
    private:
        T *data;
        int arrlength;
        int listsize;
        void resize();
        bool needtoresize();
    
    public:
        //constructor
        arraylist()
        {
            data = new T[5];
            arrlength = 5;
            listsize = 0;
        }
        //modifiers
        void add(T item);
        void add(int index, T item);
        void remove(int index);
        void remove(T item);
        void set(int index, T item);
        //accessors
        bool contains(T item);
        T get(int index);
        int indexof(T item);
        int lastindexof(T item);
        int size();
    

};

#include "arraylist.cpp"