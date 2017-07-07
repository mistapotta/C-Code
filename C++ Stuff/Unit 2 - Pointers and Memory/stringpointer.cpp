//stringpointer.cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "This is a test.";
    string str2 = str;
    
    cout << str << endl;
    cout << str[3] << endl;
    
    for (int i = 0; i < str.length(); i ++)
        cout << str[i] << " ";
    cout << endl;
    
    char beyond = str[16];
    cout << beyond << endl;
    
    for (int i = 0; i < str.length(); i ++)
        cout << &str[i] << endl;
    cout << endl;
    
    //strings are null terminated
    
    str[10] = '\0';
    
    cout << &str[0] << endl;
    cout << str << endl;
    cout << str.length() << endl;
    
    return 0;
}