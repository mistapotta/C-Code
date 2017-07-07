//stringmethods.cpp
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    string str = "A test string.";
    const char *s = &str[0];
    const char *t = "another test string.";
    char u[] = "Ultimate test string.";
    char v[] = "a long and broken string, broken by spaces.";
    
    cout << str.length() << endl;
    cout << strlen(s) << endl;
    
    int comp = strcmp (t, v);
    if (comp < 0)
    //first string comes first
        cout << t;
    else 
    //second string comes first
        cout << v;
    cout << " comes first lexicographically."<<endl;
    
    char *token = strtok(v, " ");
    while (token != NULL)
    {
        cout << token << endl;
        token = strtok(NULL, " ");
    }
    
    char output[15];
    strncat (output, s, 4);
    strncat (output, &t[3], 5);
    strncat (output, &u[10], 6);
    cout << output << endl;
    
    return 0;
}