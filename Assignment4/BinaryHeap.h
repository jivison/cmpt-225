/*
 * BinaryHeap.h
 *
 * // To do: fill in the two blank spaces below
 * // Blank space 1: The choices are "minimum" or "maximum"
 *                   (Todo: fill in the other blank spaces below.)
 * // Blank space 2: Refer to our lecture notes for the data structure used as CDT.
 * Description: __________ Binary Heap data collection ADT class.
 *              __________ implementation.
 *
 * Class Invariant:  Always a __________ Binary Heap
 *
 * Author:
 *
 * Last Modification: March 2022
 *
 */

#pragma once

#include <iostream>
#include "EmptyDataCollectionException.h" // To do: Feel free to recycle an exception class from Assignment 3.

using namespace std;

template <class ElementType>
class BinaryHeap
{

private:
	int elementCount;
	ElementType *heap;

	int indexOfRoot;

	// Utility method - Recursively put the array back into a Minimum Binary Heap.
	void
	reHeapUp(unsigned int indexOfBottom);

	// Utility method - Recursively put the array back into a Minimum Binary Heap.
	void reHeapDown(unsigned int indexOfRoot);

	// Utility method - swaps two elements in the heap
	void heapSwap(int i, int j);

public:
	// Default Constructor
	BinaryHeap();

	// Description: Returns the number of elements in the Binary Heap.
	// Postcondition:  The Binary Heap is unchanged by this operation.
	// Time Efficiency: O(1)
	unsigned int getElementCount() const;

	// Description: Inserts newElement into the Binary Heap.
	//              It returns "true" if successful, otherwise "false".
	// Postcondition: Remains a Minimum Binary Heap after the insertion.
	// Time Efficiency: O(log2 n)
	bool insert(ElementType &newElement);

	// Description: Removes (but does not return) the element located at the root.
	// Precondition: This Binary Heap is not empty.
	// Postcondition: Remains a Minimum Binary Heap after the removal.
	// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	// Time Efficiency: O(log2 n)
	void remove();

	// Description: Retrieves (but does not remove) the element located at the root.
	// Precondition: This Binary Heap is not empty.
	// Postcondition: This Binary Heap is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	// Time Efficiency: O(1)
	ElementType &retrieve() const;

	void print() const;

	// For Testing Purposes
	// Description: Prints the content of "this".
	// friend ostream &operator<<(ostream &os, const BinaryHeap &rhs);

}; // end BinaryHeap

#include "BinaryHeap.cpp"