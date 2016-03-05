Citation - This assignment is from a course at California State University, Chico. Thereby, all credits for assignment instructions and program problem statement should be given to the cited personnel or organization. http://www.ecst.csuchico.edu/~judyc/1516F-csci311/assignments/program3-hash.html Professor Judith Challinger, California State University, Chico


The Program


This assignment is an exercise in implementing a red-black tree.

This program allows the user to enter commands to insert, delete, and find key-value pairs in a red-black tree. There is also a command to print the tree. Each command is entered on a separate line.

<command> [<key>] [<satellite data>]

the command is one of the words listed below - it has no spaces in it and is followed by a space (or a newline)
the key is preceded and followed by a space (or a newline) and has no space characters in it
the satellite data is everything on the line following the second space (the one after the key)
The commands are:

insert <key> <satellite data>
inserts a node in the tree at the appropriate place based on the key and stores the satellite data for the key
both the key and the satellite data are strings
since the key is a string, insert in lexicographical order (alphabetical)
do not make any modifications to the satellite data or the key

find <key>
searches for nodes with a matching key and prints out both the key and the satellite data
there may be duplicate keys and all matches should be printed along with the satellite data for each, one key-value pair per line
use the successor and predecessor functions to find additional matches and return a vector of string pointers to the values, one per matching key found

delete <key> <satellite data>
searches for nodes with a matching key and matching satellite data and deletes
there could be more than one match and they should all be deleted
use the successor and predecessor functions to look for additional matches

print
this function is provided for you
does a reverse in-order (go right, print, go left) tree walk and prints each node on a line
prints depth*4 spaces, followed R or B, followed by the key, followed by the satellite data - see example below
this prints the tree sideways, with the root at the left and the leaves to the right

quit
when the quit command is received, the mainLoop() function of RBapp should return to main()
in addition, if eof is reached, regardless of whether there was a quit command, mainLoop() should return
in turn, main() will also return and the program will terminate
do not call exit()

For example, if I wanted to use the application to remember special dates, I could enter:

insert 03/14 Jen's birthday
insert 11/12 Mom & Dad's Anniversary
insert 11/12 Dinner at Jack's
insert 04/28 Spring Fling
insert 04/01 April Fool's Day
insert 01/20 School Starts

Then if I want to know what is happening on 11/12:

find 11/12

And the program would print:

11/12 Mom & Dad's Anniversary 11/12 Dinner at Jack's

At this point the tree would look like the following (the keys are inside the nodes just for clarity - they should be stored on the heap and a pointer to the key stored in the node - satellite data not shown):


You could now type

print

And you should get the following output of a sideways tree:


Additional Requirements:

Your files must be named rbapp.cpp/rbapp.h, and rbtree.cpp/rbtree.h.
The program must read from standard input and write to standard output. Use redirection to input commands from a file or output results to a file. 
Your program should silently ignore errors (such as if a user tries to delete a node that doesn't exist).
The example above does not test all the logic. You are responsible for generating a complete set of tests.
Your program must not segfault!
Both the key and the satellite data should be dynamically allocated, and the node should only contain pointers.
Obviously, nodes are also dynamically allocated.

Your program should not have any memory leaks! You are responsible for memory management.
Implement the red-black tree algorithm following the pseudocode in Cormen, with the following exception...
1. when deleting a node x that has two children, there are two ways to proceed
   move the tree minimum of x.right (successor) to take the place of x, or
   move the tree maximum of x.left (predecessor) to take the place of x
2. Cormen uses the successor - the Red-Black Tree Visualization uses the predecessor
   in order that you will have a way to check the results of your tests, implement the predecessor version
   in the case for delete where there are two children
   set y = rbTreeMaximum(z->left)

switch left and right everywhere in that block of code

Your program must compile and execute on jaguar using -std=c++11 -Wall -W -Werror -pedantic
Be sure to document your code and be consistent with style, naming, indentation, etc.



Develop incrementally - implement insert first, and get it working before moving on.
Develop in the following order - always keep a backup of of your last working set of sources
insert
find (no duplicates)
find (with duplicates)
delete (no duplicates)
delete (with duplicates)
grading will proceed in this order with separate tests
Be sure to generate tests for all possible cases of insert, delete, etc.
Use the Red-Black Tree Visualization tool to choose test cases and check results.