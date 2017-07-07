//loadbalancermain.cpp

#include "request.cpp"
#include "webserver.cpp"
#include "loadbalancer.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

const int NUMWEBSERVERS = 8;

//create a request
request createRandomRequest()
{
    stringstream ips, ipd;
    request r;
    ips << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256);
    ipd << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256);
    r.source = ips.str();
    r.destination = ipd.str();
    r.processTime = rand()%500;
    return r;
}

int main()
{
    //random number generator
    srand(time(0));
    //create a loadbalancer
    loadbalancer lb;
    //start off with a "full" queue
    for (int i = 0; i < 10; i ++)
    {
        request r = (createRandomRequest());
        lb.addRequest(r);
    }
    //an array of webservers
    webserver webarray[NUMWEBSERVERS];
    for (int i = 0; i < NUMWEBSERVERS; i ++)
    {
        webserver w((char)(i + 65));
        webarray[i] = w;
        webarray[i].addRequest(lb.getRequest(), lb.getTime());
    }
    //loop
    while (lb.getTime() < 10000)
    {
        int currTime = lb.getTime();
        //check each webserver if it's done
        if (webarray[currTime % NUMWEBSERVERS].isRequestDone(currTime))
        {
            request r = webarray[currTime % NUMWEBSERVERS].getRequest();
            cout << "At " << currTime << " " << webarray[currTime % NUMWEBSERVERS].getName() << " processed request from "<< r.source << " to " << r.destination << endl;
            //then give it a new request
            webarray[currTime % NUMWEBSERVERS].addRequest(lb.getRequest(),currTime);
        }
        
        //every random amt of time, we get a new request
        if (rand() % 20 == 0)
        {
            request r = (createRandomRequest());
            lb.addRequest(r);
        }
        lb.incTime();
    }
}