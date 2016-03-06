/**
 * @file MSTapp.cpp Definition of MSTapp.h file
 *                 to define functionalities.
 *
 * @brief This file contains main() and it parses
 *        the input to call appropriate process
 *        for the MST implementation.
 * @author Akshay Jain
 * @date 11/29/15
 **/
#include "MSTapp.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

//Global Variable for input manipulation.
string input;


/*
Func: MSTapp::MSTapp()
Desc: This is the default constructor
for class MSTapp. It initializes
bool flag variable, used to check 
if root is added, to false.
I/P : N/A
O/P : N/A
 */
MSTapp::MSTapp() : rootAdd(false)
{

}

/*
Func: MSTapp::~MSTapp()
Desc: This is the default destructor
for class MSTapp.
I/P : N/A
O/P : N/A
 */
MSTapp::~MSTapp()
{

}

/*
Func: bool MSTapp::validWeight(int x)
Desc: This function checks whether the
passed weight value is in valid
range or not.
I/P : int x - weight value
O/P : bool - Returns true if valid,
false otherwise.
 */
bool MSTapp::validWeight(int x)
{
   if(x >= 1 && x <= 99)
      return true;
   return false;
}

/*
Func: void MSTapp::readGraph()
Desc: This function is used to read the
input, parse it and call appropriate
functions on it..
I/P : N/A
O/P : N/A
 */
void MSTapp::readGraph()
{
   string inputLine;
   stringstream stss(input);
   while(getline(stss,inputLine,' '))
   {
      if(rootAdd == false)
      {
         myGraph.addVertex(inputLine);
      }
      else
      {
         int weight;
         string from, to, weigh2;
         stringstream stss2(input);
         stss2>>from>>to>>weigh2;
         weight = atoi(weigh2.c_str());
         if(validWeight(weight) == true)
         {
            myGraph.addEdge(from,to,weight);
            myGraph.addEdge(to,from,weight);
         }
      }
   }
   rootAdd = true;
}


/*
Func: int main()
Desc: This function is the main entry of
the program. It instantiate the objects
of class MSTapp and class Graph. It also
takes the input and calls readGraph() and
then finally calls mst(string start) to
implement MST on input graph.
I/P : N/A
O/P : int - Returns 0, when done.
 */
int main()
{
   MSTapp myApp;
   string inLine;
   while(getline(cin,inLine))
   {
      input = inLine;
      if(inLine=="")
      {
      }
      else
         myApp.readGraph();
   }

   /*Instantiated objects to access public and private 
     functions and data members.*/
   myApp.myGraph.mst(myApp.myGraph.getSource());

   return 0;
}
