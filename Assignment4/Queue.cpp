/*
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: John Ivison
 * Date: Feburary 16th, 2022
 */

#include <iostream>
#include <math.h>
#include "Queue.h"

// Description:  Constructor
template <class ElementType>
Queue<ElementType>::Queue() : elementCount(0), capacity(INITIAL_CAPACITY), frontindex(0), backindex(0)
{
  elements = new ElementType[capacity];
}

template <class ElementType>
Queue<ElementType>::~Queue()
{
  delete[] elements;
}

// Description:  Inserts element x at the back (O(1))
template <class ElementType>
void Queue<ElementType>::enqueue(ElementType x)
{
  if (elementCount + 1 > capacity)
  {
    resizeElements(2);
  }

  elementCount++;
  elements[backindex] = x;
  backindex = (backindex + 1) % capacity;
}

// Description:  Removes the frontmost element (O(1))
// Precondition:  Queue not empty
template <class ElementType>
void Queue<ElementType>::dequeue()
{
  elementCount--;
  frontindex = (frontindex + 1) % capacity;

  if (elementCount != 0 && capacity / 4 >= elementCount)
  {
    resizeElements(0.5);
  }
}

// Description:  Returns a copy of the frontmost element (O(1))
// Precondition:  Queue not empty
template <class ElementType>
ElementType Queue<ElementType>::peek() const
{
  return elements[frontindex];
}

// Description:  Returns true if and only if queue empty (O(1))
template <class ElementType>
bool Queue<ElementType>::isEmpty() const
{
  return elementCount == 0;
}

// Description: Resize the elements array by the given multiplier
// Postcondition: frontindex and backindex should point to the same element
template <class ElementType>
void Queue<ElementType>::resizeElements(float multiplier)
{
  capacity = static_cast<int>(ceil(capacity * multiplier));

  ElementType *newArray = new ElementType[capacity];
  int newIndex = 0;

  if (elementCount == 1)
  {
    elements[0] = elements[frontindex];
    frontindex = backindex = 0;
    return;
  }

  // Array has looped around
  if (backindex <= frontindex)
  {
    for (int i = 0; i < elementCount - frontindex; i++)
    {
      newArray[newIndex] = elements[frontindex + i];
      newIndex++;
    }

    for (int i = 0; i <= backindex; i++)
    {
      newArray[newIndex] = elements[i];
      newIndex++;
    }
  }
  else
  {
    for (; newIndex < backindex - frontindex; newIndex++)
    {
      newArray[newIndex] = elements[frontindex + newIndex];
    }
  }

  frontindex = 0;
  backindex = newIndex - 1;

  elements = newArray;
}
