/*
 * Dictionary.h
 *
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *
 * Author: AL
 * Date: Feb. 2022
 */

#pragma once

#include "BST.h"

template <class ElementType>
class Dictionary
{

private:
  /* You cannot change the following data member of this class. */
  BST<ElementType> *keyValuePairs;

public:
  // Constructors and destructor:
  Dictionary();                     // Default constructor
  Dictionary(ElementType &element); // Parameterized constructor
  ~Dictionary();                    // Destructor

  // Dictionary operations:
  // Description: Returns the element count
  unsigned int getElementCount() const;

  // Description: Puts "newElement" into the dictionary.
  //              If "newElement" is already in the dictionary, no error is thrown
  void put(const ElementType &newElement);

  // Description: Gets "newElement" from the dictionary.
  // Exception: Throws an error if "newElement" is not in the dictionary
  ElementType &get(const ElementType &targetElement) const;

  // Description: calls "visit()" for each node in the tree, in order
  void displayContent(void visit(const ElementType &)) const;

}; // end Dictionary

#include "Dictionary.cpp" // Including "Dictionary.cpp" (instead of copying the content of Dictionary.cpp)
                          // is another way of creating templates.