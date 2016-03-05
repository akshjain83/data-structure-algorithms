/**
 * @file rbtree.cpp The declaration for rbtree.cpp file.
 *
 * @brief This file is used to declare the function
 *        skeleton to implement and maintain the red
 *        black tree for application program.
 * @author Akshay Jain
 * @date 11/07/15
 **/

#ifndef CSCI_311_RBTREE_H
#define CSCI_311_RBTREE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class RBTree {

   public:

      RBTree();
      ~RBTree();

      void rbInsert(const string& key, const string& value);
      void rbDelete(const string& key, const string& value);
      vector<const string*> rbFind(const string& key);
      void rbPrintTree();

   private:

      // Node is a private nested class - used only by RBTree.
      class Node {
         public:
            Node();
            Node(const string&, const string&, Node*);   // Node* s/b a pointer to nil
            ~Node();
            Node *parent;
            Node *left;
            Node *right;
            char color;
            string *key;
            string *value;
      };

      Node *root;          // pointer to the root of the red-black tree
      Node *nil;           // pointer to the single nil node

      // private accessors - must all use nil
      Node* rbTreeMinimum(Node*);
      Node* rbTreeMaximum(Node*);
      Node* rbTreeSuccessor(Node*);
      Node* rbTreePredecessor(Node*);
      Node* rbTreeSearch(Node*, const string&);
      void reverseInOrderPrint(Node*, int);

      // private mutators
      void leftRotate(Node*);
      void rightRotate(Node*);
      void rbInsertFixup(Node*);
      void rbDeleteFixup(Node*);
      void rbTransplant(Node*, Node*);

      // private mutators overloaded from public interface
      void rbInsert(Node*);
      void rbDelete(Node*);

      // do not modify anything above this line!
      // you may add private functions below (although you shouldn't need to)

      //Delete tree by traversing with post order.
      void deleteWithPostOrder(Node*);
};

#endif // CSCI_311_RBTREE_H
