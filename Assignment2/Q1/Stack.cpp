/*
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author: John Ivison
 * Date: February 16th, 2022
 */

#include <cstddef> // For NULL
#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
  head = new StackNode();
  tail = new StackNode();
}

Stack::~Stack() {}

void Stack::push(int x)
{
  StackNode *newNode = new StackNode();

  newNode->data = x;

  if (head->next == NULL)
  {
    head->next = newNode;
  }

  if (tail->next != NULL)
    tail->next->next = newNode;

  tail->next = newNode;
}

int Stack::pop()
{
  StackNode *popped = tail->next;
  StackNode *index = head;

  while (index != NULL)
  {
    if (index->next == popped)

    {
      index->next = NULL;

      if (index != head)
      {
        tail->next = index;
      }
    }

    index = index->next;
  }

  return popped->data;
}

int Stack::peek() const
{
  return tail->next->data;
}

bool Stack::isEmpty() const
{
  return head->next == NULL;
}