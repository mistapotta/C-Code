//calculator.cpp

#include <iostream>
#include <string>

#include "arraystack.h"

using namespace std;

//check if char is a digit.
bool isDigit(char c)
{
    return  (c >= '0' && c <= '9');
}

//check if char is an operator.
bool isOp(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

//determine the precedence of an operator
int getPrecedence (char c)
{
    switch (c)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '(':
        case ')': return 3;
        default: return -1;
    }
}

//evaluate an arithmetic expression
int operate (int val1, int val2, char op)
{
    if (op == '+') return val1 + val2;
    if (op == '-') return val1 - val2;
    if (op == '*') return val1 * val2;
    return val1 / val2;
}

//evaluate a string.
int evaluate (string s)
{
    stack<int> vals;
    stack<char> ops;
    
    int val = 0;
    int pos = 0;
    
    while (pos < s.length())
    {
        char spot = s[pos];
        if (isDigit(spot))
        {
            val = (val * 10) + (int)(spot - '0');
        }
        else if (isOp(spot))
        {
            if (spot == '(')
            {
                cout << "open parens, val = " << val << endl;
                ops.push (spot);
                val = 0;
            }
            else if (vals.isEmpty())
            {
                cout << "empty stack, val = " << val << endl;
                vals.push(val);
                ops.push(spot);
                val = 0;
            }
            else if (spot == ')')
            {
                cout << "close parens, val = " << val << endl;
                vals.push(val);
                while (ops.peek() != '(')
                {
                    spot = ops.pop();
                    val = vals.pop();
                    int prev = vals.pop();
                    val = operate(prev, val, spot);
                    vals.push(val);
                }
                ops.pop();
                vals.pop();
                cout << "finished close parens, val = " << val << endl;
            }
            else
            {
                char prev = ops.peek();
                if (getPrecedence(spot) > getPrecedence(prev))
                {
                    cout << "high precedence, val = " << val << endl;
                    vals.push(val);
                    ops.push(spot);
                    val = 0;
                }
                else
                {
                    cout << "low precedence, val = " << val << endl;
                    int prevval = vals.pop();
                    int prevop = ops.pop();
                    prevval = operate(prevval, val, prevop);
                    vals.push(prevval);
                    ops.push(spot);
                    val = 0;
                }
            }
        }
        pos ++;
    }
    
    while (!ops.isEmpty())
    {
        cout << "ops not empty, val = " << val << endl;
        int prev = vals.pop();
        char spot = ops.pop();
        val = operate(prev, val, spot);
        
    }
    return val;
}