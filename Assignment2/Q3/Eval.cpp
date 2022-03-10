/*
 * Eval.cpp
 *
 * Author: John Ivison
 * Date: February 16th, 2022
 */

#include "Scanner.h"
#include "Stack.h" // GENERIC STACK

#include <iostream>
using namespace std;

Token performOperation(Token lhs, Token rhs, Token op);
bool isMultiplicativeOperator(Token token);
bool isArithmeticOperator(Token token);
bool isNumericalOperator(Token token);

int main()
{
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack; // 2x Stacks of type Token

    t = S.getnext();

    while (t.tt != eof || !opstack.isEmpty())
    {
        cout << "Processing token " << t.text << endl;

        if (t.tt == integer)
        {
            numstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == lptok)
        {
            opstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == rptok)
        {
            if (opstack.peek().tt == lptok)
            {
                opstack.pop();
                t = S.getnext();
            }
            else
            {
                Token result = performOperation(numstack.pop(), numstack.pop(), opstack.pop());
                numstack.push(result);
            }
        }
        else if (isArithmeticOperator(t) || t.tt == eof)
        {
            if (!opstack.isEmpty() && isNumericalOperator(opstack.peek()))
            {
                Token result = performOperation(numstack.pop(), numstack.pop(), opstack.pop());

                numstack.push(result);
            }
            else
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
        else if (isMultiplicativeOperator(t))
        {
            if (!opstack.isEmpty() && isMultiplicativeOperator(opstack.peek()))
            {
                Token result = performOperation(numstack.pop(), numstack.pop(), opstack.pop());
                numstack.push(result);
            }
            else
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
    }

    Token finalResult = numstack.pop();

    cout << "Final result: " << finalResult << endl;

    return 0;
}

Token performOperation(Token rhs, Token lhs, Token op)
{
    int result;

    switch (op.tt)
    {
    case pltok:
        result = lhs.val + rhs.val;
        break;
    case mitok:
        result = lhs.val - rhs.val;
        break;
    case asttok:
        result = lhs.val * rhs.val;
        break;
    case slashtok:
        result = lhs.val / rhs.val;
        break;
    default:
        result = 0;
    }

    cout << "performed operation " << lhs.val << " " << op.text << " " << rhs.val << " and got " << result << "\n";

    lhs.val = result;

    return lhs;
}

bool isArithmeticOperator(Token token)
{
    return token.tt == pltok || token.tt == mitok;
}
bool isMultiplicativeOperator(Token token)
{
    return token.tt == asttok || token.tt == slashtok;
}

bool isNumericalOperator(Token token)
{
    return isArithmeticOperator(token) || isMultiplicativeOperator(token);
}
