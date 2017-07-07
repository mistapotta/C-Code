//arrayqueue.h

#define QUEUE_H

template <class T>
class queue
{
    public:
        queue()
        {
            size = 5;
            data = new T[size];
            head = 0;
            tail = 0;
        }
        void enqueue (T data);
        T dequeue ();
        T peek ();
        bool isEmpty();
        
    private:
        T* data;
        int head, tail, size;
        bool needToResize();
        void resize();
};

#include "arrayqueue.cpp"
