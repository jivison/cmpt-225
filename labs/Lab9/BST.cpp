/*
 * BST.cpp
 *
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 *
 * Author: Inspired from our textbook + John Ivison
 * Date of last modification: March 2022
 */

#include "BST.h"
#include <iostream>

using namespace std;

/* Constructors and destructor */

// Default constructor
template <class ElementType>
BST<ElementType>::BST()
{
  root = NULL;
  elementCount = 0;
}

// Parameterized constructor
template <class ElementType>
BST<ElementType>::BST(ElementType &element)
{
  root = new BSTNode<ElementType>(element);
  elementCount = 1;
}

// Copy constructor
template <class ElementType>
BST<ElementType>::BST(const BST<ElementType> &aBST)
{
  if (aBST.elementCount != 0)
  {
    elementCount = aBST.elementCount;

    root = new BSTNode<ElementType>(aBST.root->element);

    copyR(aBST.root, root);
  }
}

// Destructor
template <class ElementType>
BST<ElementType>::~BST()
{
  if (elementCount != 0)
    destructR(root);
}

/* Getters and setters */

// Description: Returns the number of elements currently stored in the binary search tree.
// Time efficiency: O(1)
template <class ElementType>
unsigned int BST<ElementType>::getElementCount() const
{
  return this->elementCount;
}

/* BST Operations */

// Description: Copies each node from the source tree into the target tree, recursively
// Time efficiency: O(n) (must visit every node once)
template <class ElementType>
void BST<ElementType>::copyR(BSTNode<ElementType> *source, BSTNode<ElementType> *target)
{
  target->element = source->element;

  if (source->hasLeft())
  {
    target->left = new BSTNode<ElementType>();
    copyR(source->left, target->left);
  }

  if (source->hasRight())
  {
    target->right = new BSTNode<ElementType>();
    copyR(source->right, target->right);
  }
}

// Description: Destructs each node from the tree, recursively
// Time efficiency: O(n) (must visit every node once)
template <class ElementType>
void BST<ElementType>::destructR(BSTNode<ElementType> *current)
{
  if (current->hasLeft())
  {
    destructR(current->left);
  }

  if (current->hasRight())
  {
    destructR(current->right);
  }

  delete current;
}

// Description: Inserts an element into the binary search tree.
//              This is a wrapper method which calls the recursive insertR( ).
// Precondition: "newElement" does not already exist in the binary search tree.
// Exception: Throws the exception "ElementAlreadyExistsException"
//            if "newElement" already exists in the binary search tree.
// Time efficiency: O(log2 n)
template <class ElementType>
void BST<ElementType>::insert(const ElementType &newElement)
{

  // Binary search tree is empty, so add the new element as the root
  if (elementCount == 0)
  {
    root = new BSTNode<ElementType>(newElement);
    elementCount++;
  }
  else if (!insertR(newElement, root))
  {
    throw ElementAlreadyExistsException("Element already exists in the data collection.");
  }
  return;
}

// Description: Recursive insertion into a binary search tree.
//              Returns true when "anElement" has been successfully inserted into the
//              binary search tree. Otherwise, returns false.
template <class ElementType>
bool BST<ElementType>::insertR(const ElementType &anElement, BSTNode<ElementType> *current)
{
  if (anElement == current->element)
    return false;

  if (anElement > current->element)
  {
    if (current->hasRight())
    {
      return insertR(anElement, current->right);
    }

    current->right = new BSTNode<ElementType>(anElement);
    elementCount++;
    return true;
  }

  if (current->hasLeft())
  {
    return insertR(anElement, current->left);
  }

  current->left = new BSTNode<ElementType>(anElement);
  elementCount++;
  return true;
}

// Description: Retrieves "targetElement" from the binary search tree.
//              This is a wrapper method which calls the recursive retrieveR( ).
// Precondition: Binary search tree is not empty.
// Exception: Throws the exception "EmptyDataCollectionException"
//            if the binary search tree is empty.
// Exception: Throws (propagates) the exception "ElementDoesNotExistException"
//            thrown from the retrieveR(...)
//            if "targetElement" is not in the binary search tree.
// Time efficiency: O(log2 n)
template <class ElementType>
ElementType &BST<ElementType>::retrieve(const ElementType &targetElement) const
{
  // Check precondition: If binary search tree is empty
  if (elementCount == 0)
    throw EmptyDataCollectionException("Binary search tree is empty.");

  // Otherwise, search for it
  ElementType &translated = retrieveR(targetElement, root);

  return translated;
}

// Description: Recursive retrieval from a binary search tree.
// Exception: Throws the exception "ElementDoesNotExistException"
//            if "targetElement" is not found in the binary search tree.
template <class ElementType>
ElementType &BST<ElementType>::retrieveR(const ElementType &targetElement, BSTNode<ElementType> *current) const
{
  if (targetElement == current->element)
  {
    return current->element;
  }

  if (targetElement > current->element && current->hasRight())
  {
    return retrieveR(targetElement, current->right);
  }

  if (targetElement < current->element && current->hasLeft())
  {
    return retrieveR(targetElement, current->left);
  }

  throw ElementDoesNotExistException("That element was not found in the binary tree.");
} // end of retrieveR

// Description: Traverses the binary search tree in order.
//              This is a wrapper method which calls the recursive traverseInOrderR( ).
//              The action to be done on each element during the traverse is the function "visit".
// Precondition: Binary search tree is not empty.
// Exception: Throws the exception "EmptyDataCollectionException"
//            if the binary search tree is empty.
// Time efficiency: O(n)
template <class ElementType>
void BST<ElementType>::traverseInOrder(void visit(const ElementType &)) const
{

  // Check precondition: If binary search tree is empty
  if (elementCount == 0)
    throw EmptyDataCollectionException("Binary search tree is empty.");

  traverseInOrderR(visit, root);

  return;
}

// Description: Recursive in order traversal of a binary search tree.
template <class ElementType>
void BST<ElementType>::traverseInOrderR(void visit(const ElementType &), BSTNode<ElementType> *current) const
{
  if (current->hasLeft())
    traverseInOrderR(visit, current->left);

  visit(current->element);

  if (current->hasRight())
    traverseInOrderR(visit, current->right);
}
