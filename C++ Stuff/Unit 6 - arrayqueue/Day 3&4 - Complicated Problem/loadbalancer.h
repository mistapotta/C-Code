//loadbalancer.h

#define LOADBALANCER_H

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include "arrayqueue.h"

class loadbalancer
{
    public:
        loadbalancer()
        {
            systemTime = 0;
        }
        int getTime();
        void incTime();
        void addRequest (request r);
        request getRequest();
        bool isRequestQueueEmpty();
    private:
        int systemTime;
        queue <request> requestQueue;
};

#include "loadbalancer.cpp"