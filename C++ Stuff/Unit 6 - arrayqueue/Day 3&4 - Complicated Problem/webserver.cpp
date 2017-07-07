//webserver.cpp

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

class webserver
{
    public:
        webserver()
        {
            requestStartTime = 0;
            servername = ' ';
        }
        webserver (char c)
        {
            requestStartTime = 0;
            servername = c;
        }
        void addRequest(request req, int currTime)
        {
            r = req;
            requestStartTime = currTime;
        }
        request getRequest()
        {
            return r;
        }
        char getName()
        {
            return servername;
        }
        bool isRequestDone(int currTime)
        {
            return (currTime >= (requestStartTime + r.processTime));
        }
    private:
        request r;
        int requestStartTime;
        char servername;
};