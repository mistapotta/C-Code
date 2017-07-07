//filereader.cpp - Unit 1 Day 4

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream input;
    input.open ("alice.txt");
    
    string data, longerword;
    
    int wordcount = 0, wordlengthtotal = 0, sentencetotal = 0, longestlength = -1;
    
    while(input >> data)
    {
        //cout << data << endl;
        wordcount ++;
        int wordlength = data.length();
        wordlengthtotal += wordlength;
        if (wordlength > longestlength)
        {
            longestlength = wordlength;
            longerword = data;
        }// if
        if (data.find(".") != -1)
            sentencetotal ++;
    }//end of while
    
    cout << "average word length: " 
         << (double)(wordlengthtotal) / wordcount
         << " characters." << endl;
    cout << "number of sentences: " << sentencetotal << " ." << endl;
    cout << "the longest word is " << longerword << " with a length of " << longestlength << "." << endl;
    
    input.close();
    
    return 0;
}