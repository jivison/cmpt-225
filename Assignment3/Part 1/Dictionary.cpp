/*
 * Dictionary.cpp
 *
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *
 * Author: John Ivison
 * Date: March 2022
 */

#include "Dictionary.h"

// Constructors and destructor:

// Default constructor
template <class ElementType>
Dictionary<ElementType>::Dictionary()
{
    keyValuePairs = new BST<ElementType>();
}

// Parameterized constructor
template <class ElementType>
Dictionary<ElementType>::Dictionary(ElementType &element)
{
    keyValuePairs = new BST<ElementType>(element);
}

// Destructor
template <class ElementType>
Dictionary<ElementType>::~Dictionary()
{
    delete keyValuePairs;
}

// Dictionary operations:

// Description: Returns the element count
template <class ElementType>
unsigned int Dictionary<ElementType>::getElementCount() const
{
    return keyValuePairs->getElementCount();
};

// Description: Puts "newElement" into the dictionary.
//              If "newElement" is already in the dictionary, no error is thrown
template <class ElementType>
void Dictionary<ElementType>::put(const ElementType &newElement)
{
    try
    {
        keyValuePairs->insert(newElement);
    }
    catch (const std::exception &e)
    {
        // If a word is already in the dictionary, no need to panic
        // Silently suppress the error
    }
}

// Description: Gets "newElement" from the dictionary.
// Exception: Throws an error if "newElement" is not in the dictionary
template <class ElementType>
ElementType &Dictionary<ElementType>::get(const ElementType &targetElement) const
{
    return keyValuePairs->retrieve(targetElement);
}

// Description: calls "visit()" for each node in the tree, in order
template <class ElementType>
void Dictionary<ElementType>::displayContent(void visit(const ElementType &)) const
{
    keyValuePairs->traverseInOrder(visit);
}
