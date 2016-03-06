/**
 * @file MSTapp.h The declaration for MSTapp.cpp file.
 *
 * @brief This file is used to declare the function
 *        skeleton to implement and maintain the min
 *        heap for application program.
 * @author Akshay Jain
 * @date 11/29/15
 **/

#ifndef __MSTAPP_H
#define __MSTAPP_H

#include "Graph.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class MSTapp
{
   public:
      MSTapp();
      ~MSTapp();
      Graph getMyGraph(){ return myGraph; };
      Graph myGraph;
      void readGraph();

   private:
      bool validWeight(int);
      bool rootAdd;
};
#endif
