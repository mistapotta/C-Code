//loadbalancer.cpp

#ifndef LOADBALANCER_H
#include "loadbalancer.h"
#endif

int loadbalancer::getTime()
{
    return systemTime;
}

void loadbalancer::incTime()
{
    systemTime ++;
}

void loadbalancer::addRequest(request r)
{
    requestQueue.enqueue(r);
    incTime();
}

request loadbalancer::getRequest()
{
    incTime();
    if (!requestQueue.isEmpty())
    {
        request r = requestQueue.dequeue();
        return r;
    }
}

bool loadbalancer::isRequestQueueEmpty()
{
    return requestQueue.isEmpty();
}