#pragma once

#include "BinaryHeap.h"

template <class ElementType>
class PriorityQueue
{
private:
  BinaryHeap<ElementType> heap;

public:
  // Description: Constructor, creates the binary heap
  PriorityQueue();

  // Description: Returns "true" if this Priority Queue is empty, otherwise "false".
  // Postcondition: This Priority Queue is unchanged by this operation.
  // Time Efficiency: O(1)
  bool isEmpty() const;

  // Description: Inserts newElement in this Priority Queue and
  //              returns "true" if successful, otherwise "false".
  bool enqueue(ElementType &newElement);

  // Description: Removes (but does not return) the element with the next
  //              "highest" priority value from the Priority Queue.
  // Precondition: This Priority Queue is not empty.
  // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
  void dequeue();

  // Description: Returns (but does not remove) the element with the next
  //              "highest" priority from the Priority Queue.
  // Precondition: This Priority Queue is not empty.
  // Postcondition: This Priority Queue is unchanged by this operation.
  // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
  ElementType &peek() const;

  void print() const;
};

#include "PriorityQueue.cpp"
