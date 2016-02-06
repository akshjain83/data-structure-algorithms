/* This assignment originated at UC Riverside.*/
/**
 * @file hash_function.cpp
 *
 * @brief
 *    This file defines the hash function
 *    for the hash table.
 *
 * @author Akshay Jain
 * @date 10/29/15
 */
#include <string>
#include "hash.h"

using std::string;

/*
Func: int Hash::hf ( string ins )
Desc: This function is my version or the
      implementation of "Horer's Rule". I then
      found out that best prime number is 79.
      So i used it in my funtion with the ascii
      value of each character of the word.
Reference:
      http://www.cs.princeton.edu/courses/archive/
      fall05/cos226/lectures/hash.pdf
I/P : string ins - The string key that needs to hash.
O/P : int index - The slot or index in the hash table
                  where key will be hashed.
*/
int
Hash::hf ( string ins )
{
   int index = 0;
   int len = ins.length();
   for(int i = 0 ; i < len ; i++)
   {
      index = (ins[i] + 79 * index) % HASH_TABLE_SIZE;
   }
   return index;
}
