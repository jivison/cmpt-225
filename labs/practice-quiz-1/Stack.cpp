/*
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author:
 * Date:
 */

#include <iostream>
#include "Stack.h"

// Description: Constructor
Stack::Stack()
{
    elementCount = 0;
}

// Description: Returns true if Stack empty.
bool Stack::isEmpty() const
{
    return elementCount == 0;
}

// Description: Insert element x to the top of Stack.
void Stack::push(int x)
{
    arr[elementCount++] = x;
}

// Description: Remove and return element at the top of Stack.
int Stack::pop()
{
    return arr[--elementCount];
}

// Description: Removes and returns the max element.
//              In case of duplicated max, take the one closest to the top.
// Precondition: Stack nonempty
// Postcondition: Order of remaining elements is preserved
int Stack::removeMax()
{
    if (isEmpty())
        return -1;

    if (elementCount == 1)
        return pop();

    Stack tempStack = Stack();

    int maxElement = 0;

    while (!isEmpty())
    {
        int element = pop();

        std::cout << element << " > " << maxElement << "?"
                  << "\n";

        if (element > maxElement)
        {
            maxElement = element;
        }
        else
        {
            tempStack.push(element);
        }
    }

    Stack reversedStack = Stack();

    while (!tempStack.isEmpty())
    {
        reversedStack.push(tempStack.pop());
    }

    while (!reversedStack.isEmpty())
    {
        push(reversedStack.pop());
    }

    return maxElement;
}
