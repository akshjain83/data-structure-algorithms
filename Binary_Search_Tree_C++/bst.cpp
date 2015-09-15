/**
 * @file bst.cpp
 *
 * @brief
 *    This file defines the accessors, mutators and
 even helper functions which are used for generating
 Binary Search Trees.
 *
 * @author Akshay Jain
 * @date 9/5/15
*/


#include "bst.h"
#include<string>
#include<vector>
#include<utility>

using namespace std;

/*
   BST::BST()
   Desc - This is default constructor for class BST
   which intialized the root and nil nodes.

   I/P  - N/A
   O/P  - N/A
*/
BST::BST()
{
   nil = new Node();
   root = nil;
}

/*
   BST::~BST()
   Desc - This is destructor for class BST
   used for memory management against
   leak and dynamic allocation.

   I/P  - N/A
   O/P  - N/A
*/
BST::~BST()
{
   while(root != nil)
   {
      deleteContent(root);
   }
   delete nil;
}

/*
   BST::Node::Node()
   Desc - This is default constructor for private nested
   class Node which intialized the paramenters of
   a node to default(NULL value).
   I/P  - N/A
   O/P  - N/A
*/
BST::Node::Node()
{
   parent = NULL;
   left = NULL;
   right = NULL;
   this->word = new string();
   this->definition = new string();
}

/*
   BST::Node::Node(const string &word, const string &definition, Node *nil)
   Desc - This is parameterised constructor for private nested
   class Node which intialized the paramenters of
   a node to passed value to the constructor.
   I/P  - const string &word, const string &definition, Node *nil
   O/P  - N/A
*/
BST::Node::Node(const string &word, const string &definition, Node *nil)
{
   parent = nil;
   left = nil;
   right = nil;
   this->word = new string(word);
   this->definition = new string(definition);
}

/*
   BST::Node::~Node
   Desc - This is destructor for class Node
   used for memory management against
   leak and dynamic allocation.
   I/P  - N/A
   O/P  - N/A
*/
BST::Node::~Node()
{
   delete word;
   delete definition;
}

/*
   bool BST::isEmpty()
   Desc - This function is used to check whether
   BST is empty or not.
   I/P  - N/A
   O/P  - Return true if empty, false otherwise
*/
bool BST::isEmpty()
{
   if(root == nil)
   {
      return true;
   }
   return false;
}


/*
   BST::Node * BST::treeMinimum(Node *minNode)
   Desc - This is an accessor function for binary
   search tree used to find minimum node
   or say the leftmost node of the tree
   from a particular given node.

   I/P  - Node *minNode
   O/P  - Node *minNode
*/
BST::Node * BST::treeMinimum(Node *minNode)
{
   while (minNode->left != nil)
   {
      minNode = minNode->left;
   }
   return minNode;
}

/*
   void BST::treeTransplant(Node *u, Node *v)
   Desc - This is an mutator function for binary
   search tree used to transplant the
   subtree rooted at 'u' node by the
   subtree rooted at 'v'.

   I/P  - Node *u, Node *v
   O/P  - N/A
*/
void BST::treeTransplant(Node *u, Node *v)
{
   if(u->parent == nil)
   {
      root = v;
   }
   else if(u == u->parent->left)
   {
      u->parent->left = v;
   }
   else
   {
      u->parent->right = v;
   }
   if(v != nil)
   {
      v->parent = u->parent;
   }
}

/*
   BST::Node* BST::searchInTree(Node *startNode, const string &word)
   Desc - This is an accessor function for binary
   search tree used to search the node in the
   tree whose value(word) matches with the passed
   parameter.

   I/P  - Node *startNode, const string &word
   O/P  - Node *startNode
*/
BST::Node* BST::searchInTree(Node *startNode, const string &word)
{
   if(startNode == nil || word == *(startNode->word))
   {
      return startNode;
   }
   else if(word < *(startNode->word))
   {
      return searchInTree(startNode->left,word);
   }
   else
   {
      return searchInTree(startNode->right,word);
   }
}

/*
   const string* BST::getContent(const string &word)
   Desc - This is an public function used to look
   for the all content of the node whose
   value(word) matches with the passed
   parameter.

   I/P  - const string &word
   O/P  - const string *definition
*/
const string* BST::getContent(const string &word)
{
   Node *lookNode;
   const string *definition;
   lookNode = searchInTree(root,word);

   if(lookNode != nil && word == *(lookNode->word))
   {
      definition = lookNode->definition;
   }
   else
   {
      definition = NULL;
   }
   return definition;
}

/*
   void BST::insertContent(const string &word, const string &definition)
   Desc - This is an public function used as a
   helper function to call insertContent() to insert
   or add a new word to the BST.

   I/P  - const string &word, const string &definition
   O/P  - N/A
*/
void BST::insertContent(const string &word, const string &definition)
{
   Node *z = new Node(word,definition,nil);
   insertContent(z);
}

/*
   void BST::insertContent(Node *z)
   Desc - This is an mutator function used to insert
   or add a word to the BST.

   I/P  - Node *z
   O/P  - N/A
*/
void BST::insertContent(Node *z)
{
   Node *x = root;
   Node *y = nil;
   while (x != nil)
   {
      y = x;
      if(*(z->word) < *(x->word))
      {
         x = x->left;
      }
      else
      {
         x = x->right;
      }
   }
   z->parent = y;
   if(y == nil)
   {
      root = z;
   }
   else if(*(z->word) < *(y->word))
   {
      y->left = z;
   }
   else
   {
      y->right = z;
   }
   z->left = nil;
   z->right = nil;
}

/*
   void BST::deleteContent(string *word)
   Desc - This is an public function used as a
   helper function to call deleteContent() to delete
   or remove a word and its definition from the
   BST whose value(word) matches with passed paramenter.

   I/P  - string *word
   O/P  - N/A
*/
void BST::deleteContent(string *word)
{
   Node *z = nil;
   z = (searchInTree(root,*word));

   if(z != nil)
   {
      Node *dumpNode = z;
      deleteContent(dumpNode);
   }
   else
   {
      return;
   }
}

/*
   void BST::deleteContent(Node *z)
   Desc - This is an mutator function used to delete
   or remove a word and its definition from the BST.

   I/P  - Node *z
   O/P  - N/A
*/
void BST::deleteContent(Node *z)
{
   if(z->left == nil)
   {
      treeTransplant(z, z->right);
   }
   else if(z->right == nil)
   {
      treeTransplant(z, z->left);
   }
   else
   {
      Node *y = treeMinimum(z->right);
      if(y->parent != z)
      {
         treeTransplant(y, y->right);
         y->right = z->right;
         y->right->parent = y;
      }
      treeTransplant(z,y);
      y->left = z->left;
      y->left->parent = y;
   }

   delete z;

}


/*
   vector<pair<const string *,const string *>> BST::inOrderTraversal()
   Desc - This is an helper function used to call, overloaded
   accessor function, inOrderTraversal(Node *currentNode)
   for inorder traversal walk and returning a vector pair
   of two strings(word and definition) of every word(node) in
   inorder traversal.

   I/P  - N/A
   O/P  - vector<pair<const string *,const string *>> dictionaryDetails
*/
vector<pair<const string *,const string *>> BST::inOrderTraversal()
{
   inOrderTraversal(root);
   vector<pair<const string *,const string *>> dictionaryDetails;
   vector<Node *>::iterator itr;
   for( itr = myVector.begin() ; itr!= myVector.end() ; ++itr )
   {
      dictionaryDetails.push_back(make_pair(((*itr)->word),((*itr)->definition)));
   }
   myVector.clear();
   return dictionaryDetails;
}

/*
   void BST::inOrderTraversal(Node *currentNode)
   Desc - This is an accessor function used for inorder traversal
   walk and it pushes back the node(=~word) visited in
   inorder traversal into vector of Node.

   I/P  - Node *currentNode
   O/P  - N/A
*/
void BST::inOrderTraversal(Node *currentNode)
{
   if(currentNode != nil)
   {
      inOrderTraversal(currentNode->left);
      myVector.push_back(currentNode);
      inOrderTraversal(currentNode->right);
   }
}


/*
   vector<pair<const string *,const string *>> BST::preOrderTraversal()
   Desc - This is an helper function used to call, overloaded
   accessor function, preOrderTraversal(Node *currentNode)
   for preorder traversal walk and returning a vector pair
   of two strings(word and definition) of every word(node) in
   preorder traversal.

   I/P  - N/A
   O/P  - vector<pair<const string *,const string *>> dictionaryDetails
*/
vector<pair<const string *,const string *>> BST::preOrderTraversal()
{
   preOrderTraversal(root);
   vector<pair<const string *,const string *>> dictionaryDetails;
   vector<Node *>::iterator itr;
   for( itr = myVector.begin() ; itr!= myVector.end() ; ++itr )
   {
      dictionaryDetails.push_back(make_pair(((*itr)->word),((*itr)->definition)));
   }
   myVector.clear();
   return dictionaryDetails;
}

/*
   void BST::preOrderTraversal(Node *currentNode)
   Desc - This is an accessor function used for preorder traversal
   walk and it pushes back the node(=~word) visited in
   preorder traversal into vector of Node.

   I/P  - Node *currentNode
   O/P  - N/A
*/
void BST::preOrderTraversal(Node *currentNode)
{
   if(currentNode != nil)
   {
      myVector.push_back(currentNode);
      preOrderTraversal(currentNode->left);
      preOrderTraversal(currentNode->right);
   }
}


/*
   vector<pair<const string *,const string *>> BST::postOrderTraversal()
   Desc - This is an helper function used to call, overloaded
   accessor function, postOrderTraversal(Node *currentNode)
   for postorder traversal walk and returning a vector pair
   of two strings(word and definition) of every word(node) in
   postorder traversal.

   I/P  - N/A
   O/P  - vector<pair<const string *,const string *>> dictionaryDetails
*/
vector<pair<const string *,const string *>> BST::postOrderTraversal()
{
   postOrderTraversal(root);
   vector<pair<const string *,const string *>> dictionaryDetails;
   vector<Node *>::iterator itr;
   for( itr = myVector.begin() ; itr!= myVector.end() ; ++itr )
   {
      dictionaryDetails.push_back(make_pair(((*itr)->word),((*itr)->definition)));
   }
   myVector.clear();
   return dictionaryDetails;
}

/*
   void BST::postOrderTraversal(Node *currentNode)
   Desc - This is an accessor function used for postorder traversal
   walk and it pushes back the node(=~word) visited in
   postorder traversal into vector of Node.

   I/P  - Node *currentNode
   O/P  - N/A
*/
void BST::postOrderTraversal(Node *currentNode)
{
   if(currentNode != nil)
   {
      postOrderTraversal(currentNode->left);
      postOrderTraversal(currentNode->right);
      myVector.push_back(currentNode);
   }
}
