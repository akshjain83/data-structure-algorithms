/**
 * @file minpriority.cpp Definition of minpriority.h file
 *                 to define functionalities.
 *
 * @brief This file contains main() and it parses
 *        the input to call appropriate process
 *        for the min heap implementaion.
 * @author Akshay Jain
 * @date 11/17/15
 **/

#include "MinPriority.h"
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

/*
Func: MinPriorityQ::MinPriorityQ()
Desc: This is the default constructor
for class MinPriorityQ.
I/P : N/A
O/P : N/A
 */
MinPriorityQ::MinPriorityQ(int heapSize)
{
   minHeap.reserve(heapSize);
   this->heapSize = 0;
}

/*
Func: MinPriorityQ::~MinPriorityQ()
Desc: This is the destructor function
for class MinPriorityQ.
I/P : N/A
O/P : N/A
 */
MinPriorityQ::~MinPriorityQ()
{


}

/*
Func: void MinPriorityQ::insert(string id, int key)
Desc: This function is used to insert
a new Element in the vector of
Element or min heap.
I/P : string id - string data of Element,
int key - The key value of Element.
O/P : N/A
 */
void MinPriorityQ::insert(string id, int key)
{
   Element x;
   x.id = id;
   x.key = key;
   minHeap.push_back(x);
   heapSize++;
   minHeap.resize(heapSize);
}

/*
Func: int MinPriorityQ::parent(int i)
Desc: This function is used to find out
the index of the parent of the
specified Element index.
I/P : int i - index of Element whose
parent needs to be find.
O/P : int - Index of parent of element,
if any.
 */
int MinPriorityQ::parent(int i)
{
   return floor(i/2);
}

/*
Func: int MinPriorityQ::left(int i)
Desc: This function is used to find out
the index of the left of the
specified Element index.
I/P : int i - index of Element whose
left needs to be find.
O/P : int - Index of left of element,
if any.
 */
int MinPriorityQ::left(int i)
{
   return 2*i;
}

/*
Func: int MinPriorityQ::right(int i)
Desc: This function is used to find out
the index of the right of the
specified Element index.
I/P : int i - index of Element whose
right needs to be find.
O/P : int - Index of right of element,
if any.
 */
int MinPriorityQ::right(int i)
{
   return ((2*i) + 1);
}

/*
Func: void MinPriorityQ::minHeapify(int i)
Desc: This function is used to maintain
the min heap property.
I/P : int i - index of Element on which
min heapify needs to perform
to maintain min heap property.
O/P : N/A
 */
void MinPriorityQ::minHeapify(int i)
{
   int l, r, small;
   small = 0;
   l = left(i);
   r = right(i);
   if(l <= heapSize && ((minHeap[l-1].key) < (minHeap[i-1].key)) )
   {
      small = l;
   }
   else
   {
      small = i;
   }
   if(r <= heapSize && ((minHeap[r-1].key) < (minHeap[small-1].key)))
   {
      small = r;
   }
   if( small != i)
   {
      swap(minHeap[i-1], minHeap[small-1]);
      minHeapify(small);
   }
}


/*
Func: void MinPriorityQ::buildMinHeap()
Desc: This function is used to produce
a min heap out of a unordered
set of elements.
I/P : N/A
O/P : N/A
 */
void MinPriorityQ::buildMinHeap()
{
   for(int i = floor(heapSize/2); i > 0; i--)
   {
      minHeapify(i);
   }
}


/*
Func: string MinPriorityQ::extractMin()
Desc: This function is used to extract
the min heap element and maintain
min heap property. Also it returns
id value of the element if any is
extracted.
I/P : N/A
O/P : string - ID value of the element
which is minimum in the
min heap, empty if there
is no element.
 */
string MinPriorityQ::extractMin()
{

   int length = (int)minHeap.size();
   if(length <= 0 )
   {
      return "empty";
   }
   Element min = minHeap[0];
   minHeap[0] = minHeap[length-1];
   heapSize = heapSize - 1;
   minHeap.resize(heapSize);
   minHeapify(1);
   return min.id;
}

/*
Func: void MinPriorityQ::decreaseKey(string id, int newKey)
Desc: This function is used to modify
the key of the element if the
current key is bigger than passed
argument. It also maintain min heap
if needed.
I/P : string id - string data of Element,
int key - The key value of Element.
O/P : N/A
 */
void MinPriorityQ::decreaseKey(string id, int newKey)
{
   int i,j;
   j = heapSize - 1;
   for(i = 0; i < heapSize; i++)
   {

      if(minHeap[i].id == id)
      {
         if(newKey < minHeap[i].key)
         {
            j = i;
            minHeap[j].key = newKey;
         }
      }
   }
   buildMinHeap();
}

/*
Func: unsigned int MinPriorityQ::minHeapSize()
Desc: This function is used to get the
size of the vector of type Element.
I/P : N/A
O/P : unsigned int - size of minHeap.
 */
unsigned int MinPriorityQ::minHeapSize()
{
   return minHeap.size();
}
/*
Func: bool MinPriorityQ :: isMember(string id)
Desc: This function is used to check if
the given vertex passed as argument
is part of min priority queue or not.
I/P : string id - string data of Element,
O/P : bool - Returns true if found,
false otherwise.
 */
bool MinPriorityQ :: isMember(string id)
{
   for(int i = 0; i < heapSize; i++)
   {
      if((minHeap[i].id == id))
      {
         return true;
      }
   }
   return false;
}
