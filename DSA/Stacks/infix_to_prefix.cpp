#include <iostream>
#include <stack>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

// utility function to set character preference
// higher preference means lower value returned
int prec(char c)
{

    // multiplication and division
    if (c == '*' || c == '/')
    {
        return 3;
    }

    // addition and subtraction
    if (c == '+' || c == '-')
    {
        return 4;
    }

    // AND
    if (c == '&')
    {
        return 8;
    }

    // XOR
    if (c == '^')
    {
        return 9;
    }

    // OR
    if (c == '|')
    {
        return 10;
    }

    // closing bracket ')'
    return INT_MAX;
}

// utility function to check if the incoming character is an operator or an operand
bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// function to reverse the infix string
// will keep the order of () same
// so have to exchange ( with ) and vise-versa.
void reverse_infix(string &infix)
{
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
}

string infixToPrefix(string infix)
{

    // for storing the operators order
    stack<char> s;

    // for storing the output
    string prefix;

    // follows same method as we did in postfix case
    // just have to reverse the incoming infix
    reverse_infix(infix);

    for (char c : infix)
    {

        // case 1
        // current token is '('
        // push it in the stack
        if (c == '(')
            s.push(c);

        // case 2
        // current token is ')'
        // pop all the char from s till '(' is reached. pop that as well
        else if (c == ')')
        {
            while (s.top() != '(')
            {
                prefix.push_back(s.top());
                s.pop();
            }
            s.pop();
        }

        // case 3
        // current token is an operand
        // add it to the output directly
        else if (isOperand(c))
        {
            prefix.push_back(c);
        }

        // case 4
        // current token is an operator
        // pop all the c in s till we reach a c whose preference is lower than the current. Finally push the current operator
        else
        {
            int currPref = prec(c);
            while (!s.empty() && currPref >= prec(s.top()))
            {
                prefix.push_back(s.top());
                s.pop();
            }
            s.push(c);
        }
    }

    // append all the remaining operators to the output
    while (!s.empty())
    {
        prefix.push_back(s.top());
        s.pop();
    }

    // reverse the prefix as that output is actually the prefix of the reversed infix
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

// to check
int main()
{
    string infix = "((A-(B/C))*((A/K)-L))";
    string postfix = infixToPrefix(infix);
    cout << postfix << endl;

    // output:
    // *-A/BC-/AKL

    return 0;
}