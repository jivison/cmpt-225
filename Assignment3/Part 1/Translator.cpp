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
#include "Dictionary.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"

Dictionary<WordPair> *generateDictionary(string filename);
void displayWordPair(const WordPair &anElement);

int main(int argc, char *argv[])
{
  Dictionary<WordPair> *dictionary = generateDictionary("myDataFile.txt");

  // Check if the argument input is "display"
  // The first element in argv is always the name of the script
  // Hence 1 here not 0
  if ((argc > 1) && (strcmp(argv[1], "Display") == 0 || strcmp(argv[1], "display") == 0))
  {
    dictionary->displayContent(displayWordPair);
  }
  else if (argc == 1)
  {
    string word = "";

    while (getline(cin, word))
    {
      WordPair aWordPair(word);

      try
      {
        cout << dictionary->get(word);
      }
      catch (const std::exception &e)
      {
        cout << "***Not Found!***" << endl;
      }
    }
  }

  delete dictionary;

  return 0;
}

void displayWordPair(const WordPair &anElement)
{
  cout << anElement;
}

Dictionary<WordPair> *generateDictionary(string filename)
{
  Dictionary<WordPair> *dictionary = new Dictionary<WordPair>();

  string line = "";
  string word = "";
  string englishWord = "";
  string delimiter = ":";
  size_t delimiterPosition = 0;
  WordPair wordPair;
  ifstream myfile(filename);

  if (myfile.is_open())
  {
    while (getline(myfile, line))
    {
      // Find the position of the delimiter
      delimiterPosition = line.find(delimiter);
      // Extract the english word
      englishWord = line.substr(0, delimiterPosition);
      // Erase the english word, leaving the translation
      line.erase(0, delimiterPosition + delimiter.length());

      WordPair wordPair(englishWord, line);

      dictionary->put(wordPair);
    }

    myfile.close();
  }
  else
  {
    cout << "Couldn't open '" << filename << "'!\n";
    exit(2);
  }

  return dictionary;
}
