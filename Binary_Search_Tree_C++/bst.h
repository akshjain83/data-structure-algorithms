/**
 * @file bst.h
 *
 * @brief
 *    This file declares the accessors, mutators and
 even helper functions which are used for generating
 Binary Search Trees.
 * @author Akshay Jain
 * @date 9/5/15
*/
#ifndef __BST_H
#define __BST_H

#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

class BST
{
   public:
      BST();
      ~BST();
      void insertContent(const string& word, const string& definition);
      void deleteContent(string *word);
      const string* getContent(const string& word);

      bool isEmpty();
      //public interface for traversal & returnS vector pair of word & Defn.
      vector<pair<const string *,const string *>> inOrderTraversal();
      vector<pair<const string *,const string *>> preOrderTraversal();
      vector<pair<const string *,const string *>> postOrderTraversal();


   private:
      class Node
      {
         public:
            Node();
            Node(const string&, const string&,Node *);
            ~Node();
            Node *parent;
            Node *left;
            Node *right;
            string *word;
            string *definition;
      };

      Node *root, *nil;

      //Vector of type 'Node'
      vector<Node *> myVector;

      //Private Accessors
      Node *treeMinimum(Node*);
      Node *searchInTree(Node *, const string &word);
      void inOrderTraversal(Node *);
      void preOrderTraversal(Node *);
      void postOrderTraversal(Node *);

      //Private Mutator
      void treeTransplant(Node *, Node *);

      //Overloaded private mutator from public interface
      void insertContent(Node *);
      void deleteContent(Node *);

};
#endif
