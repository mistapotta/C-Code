//arraylist.h

#define ARRAYLIST_H

template <class T>
class arraylist
{
  private:
    T *data;
    int arrlength; //length of the actual array
    int listsize;  //number of elements the list contains
    void resize(); //resize the array if necessary
    bool needtoresize(); //determine if we need to resize
    
  public:
    //constructor
    arraylist()
    {
        //get an array set up
        data = new T[5]; //Unit 2
        //initialize parameters
        arrlength = 5;
        listsize = 0;
    }
    //accessor
    bool contains(T item);
    int indexof (T item);
    int lastindexof (T item);
    T get (int index);
    int size();
    //modifiers
    void add(T item);
    void add(int index, T item);
    void set(int index, T item);
    void remove(int index);
    void remove(T item); //talk about this...
};


#include "arraylist.cpp"