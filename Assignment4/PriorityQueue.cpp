#include "PriorityQueue.h"

template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{
  heap = BinaryHeap<ElementType>();
}

template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const
{
  return heap.getElementCount() == 0;
}

template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType &newElement)
{
  return heap.insert(newElement);
}

template <class ElementType>
void PriorityQueue<ElementType>::dequeue()
{
  return heap.remove();
}

template <class ElementType>
ElementType &PriorityQueue<ElementType>::peek() const
{
  return heap.retrieve();
}

template <class ElementType>
void PriorityQueue<ElementType>::print() const
{
  heap.print();
}