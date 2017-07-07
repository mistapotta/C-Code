//functions.cpp - Unit 1 Day 5

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//prototyping
void wheels() ;
void wheels2(string object, string action);
string wheels3(string object, string action);

int main()
{
    wheels();
    wheels2("wipers", "swish swish swish");
    wheels2("brakes", "squeak squeak squeak");
    
    ofstream output;
    output.open ("output.txt");
    //change wheels2 functions to wheels3 functions
    output << wheels3("driver","please sit down");          //input >> variable
    output.close();
    
    return 0;
}

void wheels()
{
    cout << "The wheels on the bus go round and round." << endl;
    cout << "round and round, round and round." << endl;
    cout << "the wheels on the bus go round and round." << endl;
    cout << "all through the town." << endl<<endl;
    //no return statement
}

void wheels2(string object, string action)
{
    cout << "The "<< object << " on the bus go " << action << endl;
    cout << action << ", " << action << endl;
    cout << "The "<< object << " on the bus go " << action << endl;
    cout << "all through the town." << endl << endl;
    return;
}

string wheels3(string object, string action)
{
    string result = "The "+object+" on the bus go "+ action +"\n";
    result = result + action + ", "+action+"\n";
    result += "The "+object+" on the bus go "+action+"\n";
    result += "All through the town. \n\n";
    return result;
}