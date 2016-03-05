/**
 * @file rbapp.cpp Definition of rbapp.h file
 *                 to define functionalities.
 *
 * @brief This file contains main() and it parses
 *        the input to call appropriate process
 *        for the red black tree implementaion.
 * @author Akshay Jain
 * @date 11/06/15
 **/


#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "rbapp.h"

using std::string;
using namespace std;

//Global Variable for input.
string cmdLine;
/*
Func: RBapp::RBapp()
Desc: This is the default constructor
      for class RBapp. It initializes
      the 'bool done' variable, to
      check whether program termination
      was called or not.
I/P : N/A
O/P : N/A
*/
RBapp::RBapp()
{
   done = false;
}

/*
Func: int main()
Desc: This is the main function of the
      program which instantiate the RBapp
      and call mainLoop() function.
I/P : N/A
O/P : int - Returns 0 if done.
*/
int main()
{
   RBapp myApp;
   myApp.mainLoop();
   return 0;
}

/*
Func: void RBapp::mainLoop()
Desc: This function process the commands until
      done viz, bool value of done is true. It
      reads the line and call process commands.
      It just returns when done eqauls true.
I/P : N/A
O/P : N/A
*/
void RBapp::mainLoop()
{
   string input;
   while(getline(cin,input))
   {
      cmdLine = input;
      processCommand();
      if(done == true)
      return;
   }
}

/*
Func: void RBapp::processCommand()
Desc: This function reads the line and parse it
      so that it can call appropriate function
      in response to the command read. The input
      contains the command, key and value, which
      are parsed as needed.
I/P : N/A
O/P : N/A
*/
void RBapp::processCommand()
{
   stringstream  ss(cmdLine);
   string command,key;
   ss>>command;
   if(command == "insert")
   {
      string data;
      getline(ss, data, '\n');
      processInsert(data);
   }
   else if(command == "print")
   {
      processPrint();
   }
   else if(command == "delete")
   {
      string data;
      getline(ss, data, '\n');
      processDelete(data);
   }
   else if(command == "find")
   {
      ss>>key;
      processFind(key);
   }
   else if(command == "quit")
   {
      processQuit();
   }
}

/*
Func: void RBapp::processInsert(string &input)
Desc: This function is used to call the
      function of Class RBTree(rbInsert(*params*))
      to insert the new node in the red black tree.
      This function parse the input to get the
      key and value of the new node that needs to
      be inserted.
I/P : string &input - Input that needs to parse
O/P : N/A
*/
void RBapp::processInsert(string &input)
{
   string key, value;
   stringstream ss(input);
   ss>>key;
   getline(ss, value,'\n');
   value = value.substr(1,value.length());
   myRBT.rbInsert(key,value);
}

/*
Func: void RBapp::processPrint()
Desc: This function is used to call the
      function of Class RBTree(rbPrintTree())
      to print the entire red black tree.
I/P : N/A
O/P : N/A
*/
void RBapp::processPrint()
{
   myRBT.rbPrintTree();
}

/*
Func: void RBapp::processQuit()
Desc: This function is used to terminate
      the program by setting the flag or
      the global bool variable as true.
      It quits the program.
I/P : N/A
O/P : N/A
*/
void RBapp::processQuit()
{
   done = true;
}

/*
Func: void RBapp::processDelete(string &input)
Desc: This function is used to call the
      function of Class RBTree(rbDelete(*params*))
      to delete the node from the red black tree.
      This function parse the input to get the
      key and value of the node that needs to
      be removed.
I/P : string &input - Input that will be parsed
                      for keys and values.
O/P : N/A
*/
void RBapp::processDelete(string &input)
{
   string key, value;
   stringstream ss(input);
   ss>>key;
   getline(ss, value,'\n');
   value = value.substr(1,value.length());
   myRBT.rbDelete(key,value);
}

/*
Func: void RBapp::processFind(string &key)
Desc: This function is used to find all the
      nodes matching with specified key
      'key'. It prints the vector of strings
      of values or satellite data of matching
      nodes.
I/P : string &key - Key whose matching nodes or
                    satellite data needs to find.
O/P : N/A
*/
void RBapp::processFind(string &key)
{
   vector<const string*> values;
   vector<const string*>::iterator itr;
   values = myRBT.rbFind(key);
   for(itr = values.begin(); itr != values.end(); itr++)
   {
      cout<<key<<" "<<*(*(itr))<<endl;
   }
}
