#include "List.h"
#include <iostream>

using namespace std;

// Getters and setters

// Description: Returns the total element count currently stored in List.
int List::getElementCount() const { return elementCount; }

// List operations

// Description: Checks if a patient is already in the list.
bool List::has(const Patient &patient) const
{
  for (int i = 0; i < elementCount; i++)
  {
    if (patients[i] == patient)
    {
      return true;
    }
  }

  return false;
};

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient &newElement)
{
  if (has(newElement))
    return false;

  if (elementCount > capacity)
    return false;

  if (elementCount == 0)
  {
    patients[0] = newElement;
    elementCount++;
    return true;
  }

  for (int i = 0; i < elementCount; i++)
  {
    if (patients[i] < newElement && (i == elementCount - 1 || patients[i + 1] > newElement))
    {
      for (int j = elementCount - 1; j > i; j--)
      {
        patients[j + 1] = patients[j];
        patients[j] = Patient();
      }

      patients[i + 1] = newElement;

      break;
    }
  }

  elementCount++;

  return true;
};

// Description: Remove an element.
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
bool List::remove(const Patient &toBeRemoved)
{
  for (int i = 0; i < elementCount; i++)
  {
    if (patients[i] == toBeRemoved)
    {
      for (int j = i; j < elementCount; j++)
      {

        // Replace the current element with the next element
        // (shuffling all elements after the delete one to the left)
        patients[j] = patients[j + 1];
      }

      elementCount--;

      return true;
    }
  }

  return false;
};

// Description: Remove all elements.
void List::removeAll()
{
  delete[] patients;

  elementCount = 0;

  patients = new Patient[capacity];
};

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient *List::search(const Patient &target)
{
  for (int i = 0; i < elementCount; i++)
  {
    if (patients[i] == target)
    {
      return &patients[i];
    }
  }

  return NULL;
};

// Description: Prints all elements stored in List by descending order of search key.
void List::printList()
{
  for (int i = 0; i < elementCount; i++)
  {
    cout << patients[i] << endl;
  }
};

// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
List::~List()
{
  delete[] patients;
}
