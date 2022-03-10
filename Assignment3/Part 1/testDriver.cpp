/*
 * testDriver.cpp
 *
 * Description: Drives the testing of the BST, the BSTNode,
 *              the WordPair and all the exceptions classes.
 *
 * Author: John Ivison
 * Last Modification Date: March 2022
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"

BST<WordPair> *generateBST();

void display(const WordPair &anElement)
{
  cout << anElement << endl;
} // end of display

int main(int argc, char *argv[])
{
  BST<WordPair> *testing = generateBST();

  // Test tree was generated properly
  if (testing->getElementCount() != 82)
  {
    cout << "FAIL: Tree does not have correct amount of elements" << endl;
  }
  else
  {
    cout << "PASS: Tree has correct amount of elements" << endl;
  }

  try
  {
    WordPair aWordPair("sneeze");
    testing->retrieve(aWordPair);
    cout << "PASS: Test element was found in the tree" << endl;
  }
  catch (const std::exception &e)
  {
    cout << "FAIL: Test element was not found in the tree" << endl;
  }

  try
  {
    WordPair aWordPair("c++");
    testing->retrieve(aWordPair);
    cout << "FAIL: Non-existent element was found in the tree" << endl;
  }
  catch (const std::exception &e)
  {
    cout << "PASS: Non-existent element was not found in the tree" << endl;
  }

  try
  {
    WordPair aWordPair("sneeze");
    testing->insert(aWordPair);
    cout << "FAIL: Duplicate element was added to the tree" << endl;
  }
  catch (const std::exception &e)
  {
    cout << "PASS: Duplicate element was not added to the tree" << endl;
  }

  // Test copy constructor
  BST<WordPair> *duplicate = new BST<WordPair>(*testing);

  // Test duplicate tree was copied properly
  if (duplicate->getElementCount() != testing->getElementCount())
  {
    cout << "FAIL: Duplicate tree does not have correct amount of elements" << endl;
  }
  else
  {
    cout << "PASS: Duplicate tree has correct amount of elements" << endl;
  }

  try
  {
    WordPair aWordPair("sneeze");
    duplicate->retrieve(aWordPair);
    cout << "PASS: Test element was found in the duplicate tree" << endl;
  }
  catch (const std::exception &e)
  {
    cout << "FAIL: Test element was not found in the duplicate tree" << endl;
  }

  // Test empty tree
  BST<WordPair> *empty = new BST<WordPair>();

  try
  {
    WordPair aWordPair("sneeze");
    empty->retrieve(aWordPair);
    cout << "FAIL: Exception was not thrown trying to retrieve an element from the empty tree" << endl;
  }
  catch (const std::exception &e)
  {
    cout << "PASS: Exception was thrown trying to retrieve an element from the empty tree" << endl;
  }

  // Test destructor
  delete testing;
  delete duplicate;
  delete empty;

  return 0;
}

BST<WordPair> *generateBST()
{
  BST<WordPair> *bst = new BST<WordPair>();

  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string filename = "dataFile.txt";
  string delimiter = ":";
  size_t pos = 0;
  WordPair translated;

  ifstream myfile(filename);
  if (myfile.is_open())
  {
    cout << "Reading from a file:" << endl;
    while (getline(myfile, aLine))
    {
      pos = aLine.find(delimiter);
      englishW = aLine.substr(0, pos);
      aLine.erase(0, pos + delimiter.length());
      translationW = aLine;
      WordPair aWordPair(englishW, translationW);
      try
      {
        bst->insert(aWordPair);
      }
      catch (const std::exception &e)
      {
      }
    }
    myfile.close();
  }
  else
    cout << "Unable to open file";

  return bst;
}
