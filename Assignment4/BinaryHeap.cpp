/*
 * BinaryHeap.cpp
 *
 *
 * To do: fill in the two blank spaces below
 * Description: Minimum Binary Heap data collection ADT class.
 *              Array implementation.
 *
 * Class Invariant:  Always a Minimum Binary Heap
 *
 * Author: John Ivison + AL
 *
 * Last Modification: March 2022
 *
 */

#include "BinaryHeap.h" // Header file
#include <math.h>
#include <iostream>

using namespace std;

// Default Constructor

template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap()
{
	indexOfRoot = 0;
	elementCount = 0;
	// 128 = 2^7 = 7 layers before resize
	heap = new ElementType[128]();

} // end of default constructor

// Description: Returns the number of elements in the Binary Heap.
// Postcondition:  The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const
{
	return elementCount;
} // end getElementCount

// Description: Inserts newElement into the Binary Heap.
//              It returns "true" if successful, otherwise "false".
// Postcondition: Remains a Minimum Binary Heap after the insertion.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType &newElement)
{
	bool ableToInsert = true;

	heap[elementCount] = newElement;
	reHeapUp(elementCount);

	elementCount++;

	return ableToInsert;
} // end insert

// Utility method - Recursively put the array back into a Minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfBottom)
{
	if (indexOfBottom > indexOfRoot)
	{
		int indexOfParent = floor((indexOfBottom - 1) / 2);

		if (heap[indexOfBottom] <= heap[indexOfParent])
		{
			heapSwap(indexOfParent, indexOfBottom);
			reHeapUp(indexOfParent);
		}
	}
	return;
} // end reHeapUp

// Description: Removes (but does not return) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: Remains a Minimum Binary Heap after the removal.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove()
{
	heapSwap(indexOfRoot, elementCount - 1);

	// Swap root and bottom element
	elementCount--;

	if (elementCount > 0)
	{
		reHeapDown(indexOfRoot);
	}

	return;
} // end remove

// Utility method - Recursively put the array back into a Minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot)
{
	unsigned int indexOfMinChild = indexOfRoot;

	// Find indices of children.
	unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
	unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

	// Base case: elements[indexOfRoot] is a leaf as it has no children
	if (indexOfLeftChild > elementCount - 1)
		return;

	// If we need to swap, select the smallest child
	// if (elements[indexOfRoot] > elements[indexOfLeftChild])
	if (!(heap[indexOfRoot] <= heap[indexOfLeftChild]))
		indexOfMinChild = indexOfLeftChild;

	// Check if there is a right child, is it the smallest?
	if (indexOfRightChild < elementCount)
	{
		// if (elements[indexOfMinChild] > elements[indexOfRightChild])
		if (!(heap[indexOfMinChild] <= heap[indexOfRightChild]))
			indexOfMinChild = indexOfRightChild;
	}

	// Swap parent with smallest of children.
	if (indexOfMinChild != indexOfRoot)
	{

		ElementType temp = heap[indexOfRoot];
		heap[indexOfRoot] = heap[indexOfMinChild];
		heap[indexOfMinChild] = temp;

		// Recursively put the array back into a heap
		reHeapDown(indexOfMinChild);
	}

	return;

} // end reHeapDown

// Description: Retrieves (but does not remove) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType &BinaryHeap<ElementType>::retrieve() const
{
	// Enforce precondition
	if (elementCount > 0)
		return heap[0];
	else
		throw(EmptyDataCollectionException("retrieve() called with an empty BinaryHeap."));

} // end retrieve

template <class ElementType>
void BinaryHeap<ElementType>::print() const
{
	for (int i = 0; i < elementCount; i++)
	{
		cout << i << ": " << heap[i] << endl;
	}
}

// // For Testing Purposes
// // Description: Prints the content of "rhs".
// template <class ElementType>
// ostream &operator<<(ostream &os, const BinaryHeap<ElementType> &rhs)
// {
// 	for (int i = 0; i < rhs.elementCount; i++)
// 	{
// 		os << i << ": " << rhs.heap[i];
// 	}
// } // end of operator <<

// Description: Swaps two elements located in the heap
// Postcondition: The two elements are swapped.
// Time Efficiency: O(1)
template <class ElementType>
void BinaryHeap<ElementType>::heapSwap(int i, int j)
{
	ElementType temp = heap[i];

	heap[i] = heap[j];
	heap[j] = temp;
} // end heapSwap

//  End of implementation file.
