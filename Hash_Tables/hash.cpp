/* This assignment originated at UC Riverside */
/**
 * @file hash.cpp
 *
 * @brief
 *    This file defines the funtions used to hash,
 *    unhash, search, print the keys that are stored
 *    in hash table. This file operates and maintains
 *    the hash table and its statistics.
 *
 * @author Akshay Jain
 * @date 10/26/15
 */
#include "hash.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Func: Hash::Hash()
Desc: This is default constructor for Class Hash,
      which initialize the hash table statistic's
      variables to zero.
I/P : N/A
O/P : N/A
*/
Hash::Hash()
{
   avgLength = 0;
   collisions = 0;
   position = 0;
   longestList = 0;
   loadFactor = 0.0;
}

/*
Func: void Hash::processFile(string file)
Desc: This function takes an input file, process
      the file,i.e. it hashes the content of the
      file to the hash table according to hash
      function. It also updates the statistics.
I/P : string file - Name of the input file
O/P : N/A
*/
void Hash::processFile(string file)
{
   int index;
   unsigned int listSize;
   string key;
   double currentAvgListLen;
   ifstream ifs;
   ifs.open(file);
   if(ifs.is_open())
   {
      while(!ifs.eof())
      {
         ifs>>key;
         if(key != "")
         {
            index = hf(key);
            hashTable[index].push_back(key);
            listSize = hashTable[index].size();
            if(listSize > 1)
            {
               collisions++;
            }
            if(listSize > longestList)
            {
               longestList = listSize;
            }
            currentAvgListLen = avrgLength();
            avgLength = (currentAvgListLen + avgLength)/2.0;
            key = "";
         }
      }
   }
   ifs.close();
}

/*
Func: void Hash::avrgLength()
Desc: This function is used to calculate the
      running average list length.
I/P : N/A
O/P : double - Its returns double type value i.e
               of running average list length.
*/
double Hash::avrgLength()
{
   double totalItems, totalLists;
   totalItems = totalLists = 0;
   for(int i = 0; i < HASH_TABLE_SIZE; i++)
   {
      totalItems = hashTable[i].size() + totalItems;
      if(hashTable[i].size() > 0)
      {
         totalLists++;
      }
   }
   loadFactor = totalItems;
   return totalItems/totalLists;
}

/*
Func: void Hash::print()
Desc: This function is used to call the printToStream()
      function to print the hash table to standard
      output(cout) in a particular display format.
I/P : N/A
O/P : N/A
*/
void Hash::print()
{
   printToStream(cout);
}

/*
Func: void Hash::printToStream(ostream &redirect)
Desc: This function is used to print the hash table,
      in a specific display format, which redirects
      either to a file or standard output depending
      upon the passed input parameter.
I/P : ostream &redirect - It stores the ostream object
                          passed to the function, may
                          be cout or file name.
O/P : N/A
*/
void Hash::printToStream(ostream &redirect)
{
   list<string>::iterator itr;
   for(int i = 0; i < HASH_TABLE_SIZE; i++)
   {
      redirect<<i<<":\t";
      for(itr = hashTable[i].begin(); itr != hashTable[i].end(); itr++)
      {
         redirect<<*itr<<", ";
      }
      redirect<<endl;
   }
}

/*
Func: void Hash::output(string file)
Desc: This function is used to call printToStream()
      function to print the hash table in a specific
      display format to a output file.

I/P : string file - Name of the file where printToStream()
                    function is output into.
O/P : N/A
*/
void Hash::output(string file)
{
   ofstream ifs;
   ifs.open(file);
   if(ifs.is_open())
   {
      printToStream(ifs);
   }
   ifs.close();
}

/*
Func: void Hash::printStats()
Desc: This function is used to print the various
      statistics of hash table. The statistics
      are calculated during hashing or unhashing
      operations. It prints to a standard output.
I/P : N/A
O/P : N/A
*/
void Hash::printStats()
{
   loadFactor = loadFactor/HASH_TABLE_SIZE;
   cout<<"Total Collisions = "<<collisions<<endl;
   cout<<"Longest List Ever = "<<longestList<<endl;
   cout<<"Average List Length Over Time = "<<avgLength<<endl;
   cout<<"Load Factor = "<<loadFactor<<endl;
}

/*
Func: bool Hash::search(string key)
Desc: This function is used to find the key in the
      hash table within a slot or index and respective
      list that the key is likely to be hashed.
I/P : string key - The key to be find in the table.
O/P : bool type - Return true if key found,
                  false otherwise.
*/
bool Hash::search(string key)
{
   int i, index;
   list<string>::iterator itr2;
   i = index = hf(key);
   position = i;
   for(itr2 = hashTable[i].begin(); itr2 != hashTable[i].end(); itr2++)
   {
      if(*itr2 == key)
      {
         itr = itr2;
         return true;
      }
   }
   return false;
}
/*
Func: void Hash::remove(string key)
Desc: This function is used to remove or
      unhash the particular key from the
      hash table and then update the all
      statistics.
I/P : string key - The key that needs to be remove
                   or unhash from hash table.
O/P : N/A
*/
void Hash::remove(string key)
{
   double currentAvgListLen;
   bool keyExist = search(key);
   if(keyExist)
   {
      hashTable[position].erase(itr);
      currentAvgListLen = avrgLength();
      avgLength = (currentAvgListLen + avgLength)/2.0;
   }
}
