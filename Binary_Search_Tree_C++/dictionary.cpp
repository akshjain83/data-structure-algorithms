/**
 * @file dictionary.cpp
 *
 * @brief
 *    This file defines the functions used to take input,
 parse strings, print tree in different traversal
 or tree walk and call appropriate functions from
 bst.cpp to add, remove words or get content of words.

 * @author Akshay Jain
 * @date 9/5/15
*/
#include "dictionary.h"
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

/*
   Dictionary::Dictionary()
   Desc - This is default constructor for class Dictionary.

   I/P  - N/A
   O/P  - N/A
*/
Dictionary::Dictionary()
{

}

/*
   Dictionary::~Dictionary()
   Desc - This is destructor for class Dictionary
   used for memory management against
   leak and dynamic allocation.

   I/P  - N/A
   O/P  - N/A
*/
Dictionary::~Dictionary()
{

}

/*
   void Dictionary::mainLoop()
   Desc - This function is used to take standard input
   in a loop and call processInput() to call
   different methods accordingly.

   I/P  - N/A
   O/P  - N/A
*/
void Dictionary::mainLoop()
{
   string commandLine;

   while(getline(cin,commandLine))
   {

      if(commandLine=="")
      {
         continue;
      }
      string input = commandLine;
      if(processInput(input) == 0)
      {
         break;
      }
   }
}

/*
   int Dictionary::processInput()
   Desc - This function is used to parse the
   string input and call appropriate methods
   and functions.

   I/P  - string input - one line input to be parse.
   O/P  - Returns Value 0 or 1
*/
int Dictionary::processInput(string input)
{

   string command, word, definition;
   istringstream sentence(input);
   sentence>>command>>word;
   if(command == "add")
   {
      getline(sentence,definition, '\n');
      int leadSpace = definition.find_first_not_of(' ');
      int trailSpace = definition.find_last_not_of(' ');
      definition = definition.substr(leadSpace,trailSpace);
      add(word,definition);
   }
   else if(command == "remove")
   {
      remove(word);
   }
   else if(command == "print")
   {
      const string *printDefintion = getDefinition(word);
      if(printDefintion !=  NULL)
      {
         cout<<word<<" "<<*printDefintion<<endl;
      }
   }
   else if(command == "printInOrder")
   {
      if(myBST.isEmpty() != true)
         inOrderTraversal();
   }
   else if(command == "printPreOrder")
   {
      if(myBST.isEmpty() != true)
         preOrderTraversal();
   }
   else if(command == "printPostOrder")
   {
      if(myBST.isEmpty() != true)
         postOrderTraversal();
   }
   else if(command == "quit")
   {
      return 0;
   }
   return 1;
}

/*
   void Dictionary::add(const string &word, const string &definition)
   Desc - This function is a public interface to
   BST::insertContent method to add words with definitions
   in the BST.

   I/P  - const string &word, const string &definition
   O/P  - N/A
*/
void Dictionary::add(const string &word, const string &definition)
{
   myBST.insertContent(word,definition);
}

/*
   void Dictionary::remove(const string &word)
   Desc - This function is a public interface to
   BST::deleteContent method to remove words with definitions
   from the BST.

   I/P  - const string &word
   O/P  - N/A
*/
void Dictionary::remove(const string &word)
{
   string *delWord = const_cast<string*>(&word);
   myBST.deleteContent(delWord);
}


/*
   const string* Dictionary::getDefinition(const string &word)
   Desc - This function is a public interface to
   BST::getContent method to get the content
   or say defintion of a particular word.

   I/P  - const string &word
   O/P  - const string * --> Definition of the word
*/
const string* Dictionary::getDefinition(const string &word)
{
   return myBST.getContent(word);
}

/*
   void Dictionary::printTree(vector<pair<const string *, const string *>> merriamWebster)
   Desc - This function is used to print the pair of two
   string vectors that contains word and definition.

   I/P  - vector<pair<const string *, const string *>> merriamWebster
   O/P  - N/A
*/
void Dictionary::printTree(vector<pair<const string *, const string *>> merriamWebster)
{
   for(unsigned int i = 0; i < merriamWebster.size(); i++)
   {
      cout<<*merriamWebster[i].first<<" "<<*merriamWebster[i].second<<endl;
   }
}

/*
   void Dictionary::inOrderTraversal()
   Desc - This function is a public interface to
   BST::inOrderTraversal method for
   the inorder tree walk.

   I/P  - N/A
   O/P  - N/A
*/
void Dictionary::inOrderTraversal()
{
   vector<pair<const string *, const string *>> merriamWebster;
   merriamWebster = myBST.inOrderTraversal();
   printTree(merriamWebster);
}

/*
   void Dictionary::preOrderTraversal()
   Desc - This function is a public interface to
   BST::preOrderTraversal method for
   the preorder tree walk.

   I/P  - N/A
   O/P  - N/A
*/
void Dictionary::preOrderTraversal()
{
   vector<pair<const string *, const string *>> merriamWebster;
   merriamWebster = myBST.preOrderTraversal();
   printTree(merriamWebster);
}

/*
   void Dictionary::postOrderTraversal()
   Desc - This function is a public interface to
   BST::postOrderTraversal method for
   the postorder tree walk.

   I/P  - N/A
   O/P  - N/A
*/
void Dictionary::postOrderTraversal()
{
   vector<pair<const string *, const string *>> merriamWebster;
   merriamWebster = myBST.postOrderTraversal();
   printTree(merriamWebster);
}
