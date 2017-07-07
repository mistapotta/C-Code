#include <iostream>
using namespace std;

string ones(int val) {
    switch (val) {
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        default: return "";
    }
}

string teens(int val) {
    switch (val) {
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 15: return "fifteen";
        default: return ones(val%10)+"teen";
    }
}

string enty(int val) {
    switch (val) {
        case 2: return "twenty-";
        case 3: return "thirty-";
        case 4: return "forty-" ;
        case 5: return "fifty-";
        case 8: return "eighty-";
        default: return ones(val)+"ty-";
    }
}

string hto (int val) {
    string ans="";
    if (val / 100 > 0)
        ans = ones(val/100)+" hundred ";
    val %= 100;
    if (val / 10 > 1)
        ans = ans + enty(val/10);
    else if (val > 9)
        return ans + teens(val);
    return ans + ones(val%10);
}

string illions (int val) {
    if (val == 1000000000) return "a beeleeon!";
    if (val == 0) return "zero";
    string ans = "";
    if (val >= 1000000)  {
        ans = ans + hto(val / 1000000) + " million ";
        val %= 1000000;
    }
    if (val >= 1000) {
        ans = ans + hto(val / 1000) + " thousand ";
        val %= 1000;
    }
    ans = ans + hto(val);
    return ans;
}

int main() {
    int val;
    cin >> val;
    cout <<  illions(val) << endl;
    return 0;
}