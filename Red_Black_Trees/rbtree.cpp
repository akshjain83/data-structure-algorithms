/**
 * @file rbtree.cpp The definition of rbtree.h file
 *                  that defines function skeleton.
 *
 * @brief This file is used to implement and maintain
 *        the red black tree for application program.
 * @author Akshay Jain
 * @date 11/07/15
 **/
#include <iostream>
#include <iomanip>
#include <vector>
#include "rbtree.h"

using std::cout;
using std::setw;
using std::endl;


/*
Func: void RBTree::reverseInOrderPrint(Node *x, int depth)
Desc: This function is already given which
      prints the red black tree sideways.
I/P : Node *x - The starting node or root from
                where the tree traversal and
                printing begins.
      int depth - Depth of the tree.
O/P : N/A
*/
void RBTree::reverseInOrderPrint(Node *x, int depth) {
   if ( x != nil ) {
      reverseInOrderPrint(x->right, depth+1);
      cout << setw(depth*4+4) << x->color << " ";
      cout << *(x->key) << " " << *(x->value) << endl;
      reverseInOrderPrint(x->left, depth+1);
   }
}

/*
Func: RBTree::RBTree()
Desc: This function is the default constructor
      of the class RBTree. It initializes
      the nil and root node.
I/P : N/A
O/P : N/A
*/
RBTree::RBTree()
{
   nil = new Node();
   root = nil;
}

/*
Func: RBTree::~RBTree()
Desc: This is the destructor for the
      class RBtree which deletes the
      allocated memory to free up
      the space.
I/P : N/A
O/P : N/A
*/
RBTree::~RBTree()
{
  deleteWithPostOrder(root);
  delete nil;
}

/*
Func: void RBTree::deleteWithPostOrder(Node *x)
Desc: This is the helper function used
      to delete the red black tree by
      visting and deletinf each node with
      a post order traversal..
I/P : Node *x - The root node of the subtree.
O/P : N/A
*/
void RBTree::deleteWithPostOrder(Node *x)
{
  if(x != nil)
  {
    deleteWithPostOrder(x->left);
    deleteWithPostOrder(x->right);
    delete x;
  }
}

/*
Func: RBTree::Node::Node()
Desc: This function is the default
      constructor of private nested
      class Node. It initializes the
      data members if class Node.
I/P : N/A
O/P : N/A
*/
RBTree::Node::Node()
{
   parent = NULL;
   left = NULL;
   right = NULL;
   this->key = new string();
   this->value = new string();
   color = 'B';
}

/*
Func:
RBTree::Node::Node(const string &key,const string &value,Node *nil)
Desc: This is the parameterised constructor
      of the class Node. It initializes the
      attributes or parameters for the Node.
I/P : const string &key - Key of the Node.
      const string &value - Value or satellite
                            data of Node.
O/P : N/A
*/
RBTree::Node::Node(const string &key, const string &value, Node *nil)
{
   parent = nil;
   left = nil;
   right = nil;
   this->key = new string(key);
   this->value = new string(value);
}

/*
Func: RBTree::Node::~Node()
Desc: This is the destructor for the
      class Node. It deletes the allocated
      memory to free up the space. It avoids
      memory leak and performs memory
      management.
I/P : N/A
O/P : N/A
*/
RBTree::Node::~Node()
{
   delete key;
   delete value;
}

/*
Func: void RBTree::rbInsert(const string &key, const string &value)
Desc: This is the public interface function
      that is used to insert the node in the
      red black tree with specified key and
      value or satellite data by calling a
      private function rbInsert(Node *x).
I/P : const string &key - Key of the Node.
      const string &value - Value or satellite
                            data of Node.
O/P : N/A
*/
void RBTree::rbInsert(const string &key, const string &value)
{
   Node *addNode = new Node(key, value, nil);
   rbInsert(addNode);
}

/*
Func: void RBTree::rbPrintTree()
Desc: This function checks whether the
      tree is empty or not and accordingly
      calls the reverseInOrderPrint(Node*,int)
      function to print the tree
I/P : N/A
O/P : N/A
*/
void RBTree::rbPrintTree()
{
   if(root != nil)
   {
      reverseInOrderPrint(root,0);
   }
   else
      return;
}

/*
Func: RBTree::Node* RBTree::rbTreeMinimum(Node *x)
Desc: This function is used to find the
      tree minimum of a particular node
      in the tree.
I/P : Node *x - Node whose tree minimum needs to
                find.
O/P : Node * - The tree minimum node of Node *x
               if any or Node *x otherwise.
*/
RBTree::Node* RBTree::rbTreeMinimum(Node *x)
{
   while(x->left != nil)
   {
      x = x->left;
   }
   return x;
}

/*
Func: RBTree::Node* RBTree::rbTreeMaximum(Node *x)
Desc: This function is used to find the
      tree maximum of a particular node
      in the tree.
I/P : Node *x - Node whose tree mmaximum needs to
                find.
O/P : Node * - The tree maximum node of Node *x
               if any or Node *x otherwise.
*/
RBTree::Node* RBTree::rbTreeMaximum(Node *x)
{
   while(x->right != nil)
   {
      x = x->right;
   }
   return x;
}

/*
Func: RBTree::Node* RBTree::rbTreeSuccessor(Node *x)
Desc: This function is used to find the
      successor of a node in the tree.
      It is the minimum node on the right
      if any.
I/P : Node *x - Node whose successor needs to
                find if any.
O/P : Node * - The successor node of Node *x.
*/
RBTree::Node* RBTree::rbTreeSuccessor(Node *x)
{
   Node *y;
   if(x->right != nil)
   {
      return rbTreeMinimum(x->right);
   }
   y = x->parent;
   while(y != nil && x == y->right)
   {
      x = y;
      y = y->parent;
   }
   return y;
}

/*
Func: RBTree::Node* RBTree::rbTreePredecessor(Node *x)
Desc: This function is used to find the
      predecessor of a node in the tree.
      It is the maximum node on the left
      if any.
I/P : Node *x - Node whose predecessor needs to
                find if any.
O/P : Node * - The predecessor node of Node *x.
*/
RBTree::Node* RBTree::rbTreePredecessor(Node *x)
{
   Node *y;
   if(x->left != nil)
   {
      return rbTreeMaximum(x->left);
   }
   y = x->parent;
   while(y != nil && x == y->left)
   {
      x = y;
      y = y->parent;
   }
   return y;
}

/*
Func: void RBTree::leftRotate(Node *x)
Desc: This function is used to rotate
      the tree rooted at a node by
      the left rotation.
I/P : Node *x - The node that needs to
                left rotate.
O/P : N/A
*/
void RBTree::leftRotate(Node *x)
{
   Node *y = x->right;
   x->right = y->left;
   if(y->left != nil)
   {
      y->left->parent = x;
   }
   y->parent = x->parent;
   if(x->parent == nil)
   {
      root = y;
   }
   else
   {
      if(x == x->parent->left)
      {
         x->parent->left = y;
      }
      else
      {
         x->parent->right = y;
      }
   }
   y->left = x;
   x->parent = y;
}

/*
Func: void RBTree::rightRotate(Node *x)
Desc: This function is used to rotate
      the tree rooted at a node by
      the right rotation.

I/P : Node *x - The node that needs to
                right rotate.
O/P : N/A
*/
void RBTree::rightRotate(Node *x)
{
   Node *y = x->left;
   x->left = y->right;
   if(y->right != nil)
   {
      y->right->parent = x;
   }
   y->parent = x->parent;
   if(x->parent == nil)
   {
      root = y;
   }
   else
   {
      if(x == x->parent->right)
      {
         x->parent->right = y;
      }
      else
      {
         x->parent->left = y;
      }
   }
   y->right = x;
   x->parent = y;
}

/*
Func: void RBTree::rbTransplant(Node *u, Node *v)
Desc: This function is used to transplant
      the subtree rooted at u with the
      subtree rooted at v.

I/P : Node *u - The subtree to be transplant
                with Node *v.
Node *u - The subtree to be transplant
          with Node *v.
O/P : N/A
*/
void RBTree::rbTransplant(Node *u, Node *v)
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
   v->parent = u->parent;
}

/*
Func:
RBTree::Node* RBTree::rbTreeSearch(Node *searchNode,const string &key)
Desc: This function is used to search the
      node in the tree with a specified
      value.
I/P : Node *searchNode - Node to start the search with.
O/P : Node * - Returns Node with matching key.
*/
RBTree::Node* RBTree::rbTreeSearch(Node *searchNode, const string &key)
{
   if ( searchNode == nil)
   {
      return nil;
   }
   else if( key == *(searchNode->key) )
   {
      return searchNode;
   }
   else if( key < *(searchNode->key) )
   {
      return rbTreeSearch( searchNode->left, key );
   }
   else
   {
      return rbTreeSearch( searchNode->right, key );
   }
}

/*
Func: void RBTree::rbInsert(Node *z)
Desc:This function is used to insert the
     node in the tree. This is implementaion
     of cormen's red black tree algorithm.
     It calls rbInsertFixup(Node*) to
     maintain the red black tree property.
I/P : Node *z - Node to be inserted.
O/P : N/A
*/
void RBTree::rbInsert(Node *z)
{
   Node *y, *x ;
   y = nil;
   x = root;
   while(x != nil)
   {
      y = x;
      if(*(z->key) < *(x->key))
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
   else if (*(z->key) < *(y->key))
   {
      y->left = z;
   }
   else
   {
      y->right = z;
   }
   z->left = nil;
   z->right = nil;
   z->color = 'R';
   rbInsertFixup(z);
}

/*
Func: void RBTree::rbInsertFixup(Node *z)
Desc: This function is used to maintain
      the properties of red black tree
      after a new node is inserted into
      the tree.
I/P : Node *z - Recently added node.
O/P : N/A
*/
void RBTree::rbInsertFixup(Node *z)
{
   Node *y;
   while(z->parent->color == 'R')
   {
      if(z->parent == z->parent->parent->left)
      {
         y = z->parent->parent->right;
         if(y->color == 'R')
         {
            z->parent->color = 'B';
            y->color = 'B';
            z->parent->parent->color = 'R';
            z = z->parent->parent;
         }
         else if(z == z->parent->right)
         {
            z = z->parent;
            leftRotate(z);
         }
         else
         {
            z->parent->color = 'B';
            z->parent->parent->color = 'R';
            rightRotate(z->parent->parent);
         }
      }
      else
      {
         y = z->parent->parent->left;
         if(y->color == 'R')
         {
            z->parent->color = 'B';
            y->color = 'B';
            z->parent->parent->color = 'R';
            z = z->parent->parent;
         }
         else if(z == z->parent->left)
         {
            z = z->parent;
            rightRotate(z);
         }
         else
         {
            z->parent->color = 'B';
            z->parent->parent->color = 'R';
            leftRotate(z->parent->parent);
         }
      }
   }
   root->color = 'B';
}

/*
Func:
void RBTree::rbDelete(const string& key, const string& value)
Desc: This function is the public interface
      function is used to call rbDelete(Node*)
      function to delete a node with matching
      key and value.
I/P : const string& key - Key of Node, to be delete.
      const string& value - Value of Node, to delete.
O/P : N/A
*/
void RBTree::rbDelete(const string& key, const string& value)
{
   Node *findNode, *temp, *temp1, *temp2;
   vector<Node*> nodeVector;
   vector<Node*>::iterator itr;
   findNode = rbTreeSearch(root, key);
   temp1 = temp2 = findNode;
   if(findNode != nil)
   {
      if(*(findNode->value) == value)
         nodeVector.push_back(findNode);
      while(temp1 != nil)
      {
         temp = rbTreePredecessor(temp1);
         if(*(temp->key) == key && *(temp->value) == value)
         {
            nodeVector.push_back(temp);
         }
         temp1 = temp;
      }
      while(temp2 != nil)
      {
         temp = rbTreeSuccessor(temp2);
         if(*(temp->key) == key && *(temp->value) == value)
         {
            nodeVector.push_back(temp);
         }
         temp2 = temp;
      }
   }

   for(itr = nodeVector.begin(); itr != nodeVector.end(); ++itr)
   {
      Node *z = *itr;
      rbDelete(z);
      delete z;
   }
}

/*
Func: void RBTree::rbDelete(Node *z)
Desc: This function is used to delete
      the node from the red black tree.
I/P : Node *z - Node to be delete.
O/P : N/A
*/
void RBTree::rbDelete(Node *z)
{
   Node *y, *x;
   y = z;
   char y_OriginalColor = y->color;
   if(z->left == nil)
   {
      x = z->right;
      rbTransplant(z, z->right);
   }
   else if(z->right == nil)
   {
      x = z->left;
      rbTransplant(z, z->left);
   }
   else
   {
      y = rbTreeMaximum(z->left);
      y_OriginalColor = y->color;
      x = y->left;
      if(y->parent == z)
      {
         x->parent = y;
      }
      else
      {
         rbTransplant(y, y->left);
         y->left = z->left;
         y->left->parent = y;
      }
      rbTransplant(z, y);
      y->right = z->right;
      y->right->parent = y;
      y->color = z->color;
   }
   if(y_OriginalColor == 'B')
      rbDeleteFixup(x);
}

/*
Func: void RBTree::rbDeleteFixup(Node *x)
Desc: This function is used to fixup the
      red black tree after a recent node
      deletion. It is used to maintain
      the red black tree properties.
I/P : Node *x - Node that needs to be fixed up.
O/P : N/A
*/
void RBTree::rbDeleteFixup(Node *x)
{
   Node *w;
   while((x != root) && (x->color == 'B'))
   {
      if(x == x->parent->left)
      {
         w = x->parent->right;
         if(w->color == 'R')
         {
            w->color = 'B';
            x->parent->color = 'R';
            leftRotate(x->parent);
            w = x->parent->right;
         }
         if((w->left->color == 'B') && (w->right->color == 'B'))
         {
            w->color = 'R';
            x = x->parent;
         }
         else
         {
            if(w->right->color == 'B')
            {
               w->left->color = 'B';
               w->color = 'R';
               rightRotate(w);
               w = x->parent->right;
            }
            w->color = x->parent->color;
            x->parent->color = 'B';
            w->right->color = 'B';
            leftRotate(x->parent);
            x = root;
         }
      }
      else
      {
         w = x->parent->left;
         if(w->color == 'R')
         {
            w->color = 'B';
            x->parent->color = 'R';
            rightRotate(x->parent);
            w = x->parent->left;
         }
         if((w->left->color == 'B') && (w->right->color == 'B'))
         {
            w->color = 'R';
            x = x->parent;
         }
         else
         {
            if(w->left->color == 'B')
            {
               w->right->color = 'B';
               w->color = 'R';
               leftRotate(w);
               w = x->parent->left;
            }
            w->color = x->parent->color;
            x->parent->color = 'B';
            w->left->color = 'B';
            rightRotate(x->parent);
            x = root;
         }
      }
   }
   x->color = 'B';
}

/*
Func:
vector<const string*> RBTree::rbFind(const string& key)
Desc: This function is used to find the nodes
      whose key matches with specified key and
      then return the vector of strings of the
      satellite data or values.
I/P : const string& key - Key, whose matching nodes are
                          to be searched.
O/P : vector<const string*> - Vector of strings of values
                              of node.
*/
vector<const string*> RBTree::rbFind(const string& key)
{
   Node *findNode, *temp, *temp1, *temp2;
   vector<const string*> values;
   findNode = rbTreeSearch(root, key);
   temp1 = temp2 = findNode;
   if(findNode != nil)
   {
      values.push_back(findNode->value);
      while(temp1 != nil)
      {
         temp = rbTreePredecessor(temp1);
         if(*(temp->key) == key)
         {
            values.push_back(temp->value);
         }
         temp1 = temp;
      }
      while(temp2 != nil)
      {
         temp = rbTreeSuccessor(temp2);
         if(*(temp->key) == key)
         {
            values.push_back(temp->value);
         }
         temp2 = temp;
      }
   }
   return values;
}
