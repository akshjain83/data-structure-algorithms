/**
 * @file minpriority.h The declaration for minpriority.cpp file.
 *
 * @brief This file is used to declare the function
 *        skeleton to implement and maintain the min
 *        heap for application program.
 * @author Akshay Jain
 * @date 11/17/15
 **/
#ifndef CSCI_311_MINPRIORITYQ_H
#define CSCI_311_MINPRIORITYQ_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
   Declaration of class MinPriorityQ and the
   private nested class Element according to
   the UML Given*/
class MinPriorityQ
{
   public:
      MinPriorityQ();
      MinPriorityQ(int);
      ~MinPriorityQ();
      void insert(string , int);
      void decreaseKey(string , int);
      string extractMin();
      void buildMinHeap();
      unsigned int minHeapSize();
      bool isMember(string id);

   private:
      class Element
      {
         public:
            string id;
            int key;
      };

      //Element minHeap[];
      void minHeapify(int);
      int parent(int);
      int left(int);
      int right(int);
      vector<Element> minHeap;
      int heapSize;
};
#endif
