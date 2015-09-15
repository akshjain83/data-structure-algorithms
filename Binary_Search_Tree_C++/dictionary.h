/**
 * @file dictionary.h
 *
 * @brief
 *    This file declares the functions used to take input,
 parse strings, print tree in different traversal
 or tree walk and call appropriate functions from
 bst.cpp to add, remove words or get content of words.
 *
 * @author Akshay Jain
 * @date 9/5/15
*/
#ifndef __DICTIONARY_H
#define __DICTIONARY_H

#include "bst.h"
#include<iostream>
#include<string.h>
#include<vector>
#include<utility>

using namespace std;

class Dictionary
{
   public:
      void mainLoop();
      int processInput(string);

      BST myBST;
      Dictionary();
      ~Dictionary();
      //function to call methods to add words
      void add(const string &word, const string &definition);

      //function to call methods to remove words
      void remove(const string&);

      //func. to call methods to get defn. of particular word
      const string* getDefinition(const string &word);

      /*Function to call methods for different tree
        traversal and print them*/
      void inOrderTraversal();
      void preOrderTraversal();
      void postOrderTraversal();
      void printTree(vector<pair<const string *, const string *>> );
};

#endif
