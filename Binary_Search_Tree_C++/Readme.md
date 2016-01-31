Citation -
           This assignment is from a course at California State University, Chico. Thereby, all credits for assignment                              instructions and program problem statement should be given to the cited personnel or organization.
           http://www.ecst.csuchico.edu/~judyc/1516F-csci311/assignments/program1-bst.html
           Professor Judith Challinger,
           California State University, Chico




The Program - C++ Implementation of Binary Search Tree for an application program



You are developing some software for an online dictionary. Fast retrieval of definitions is important, and the following functions will be supported:

add a word and its definition in the dictionary
remove a word and its definition from the dictionary
print a specific word and its definition
print all words, along with their definitions
The application designers have decided to make use of a binary search tree (BST) for the dictionary data structure. Your job is to implement the design as specified. The contents of the BST should be ordered lexicographically (alphabetical order) on the word being defined. You must implement the BST yourself. You may not use a library or borrowed code. The BST should store a word and its definition as two separate strings. Use the string class in the STL.

The application program will read from standard input and write to standard output. Redirection may be used to do file I/O. Your program will be compiled and tested automatically by a script, so do not deviate from the assignment specifications. Each command will be on one line of input. Well formed input will consist of a command, separated from the dictionary word (if any) by one or more spaces, and the remainder of the line is the definition (if any) ending with a newline. The definition may contain spaces; the word being defined may not contain spaces. Make sure to trim any extraneous space characters off the start and end of strings. Don't reinvent the wheel - make use of string class functions. Only well-formed commands will be issued during testing.

Your implementation must be object-oriented, and be correctly documented and written in a professional style. See my Expectations for Programming Assignments. Although a file of sample commands and the correct output for those commands are provided below, you are responsible for generating test cases for all possible scenarios, and handling potential errors. The provided sample is not the command list that will be used to grade your program. Errors (like trying to print a definition for a word that is not in the tree) are silently ignored and do not generate any output. The program must not segfault! Allocate dynamic memory to store the string data, and delete the memory when it is no longer needed. The most appropriate place to do this in is the constructor/destructor of the object holding the data. The program should not have a memory leak! There is no requirement to balance the tree. We will study balanced binary search trees later in the semester. You can find information and algorithms for the binary search tree in Chapter 12 of Cormen.

The commands are as follows, one per line in the input, where <word> stands for a string that is the dictionary word being defined, and <definition> stands for the string representing the definition of the dictionary word.

add <word> <definition>
<word> is inserted into the BST (in the correct position), along with its definition.
remove <word>
If <word> is found in the BST, it is deleted along with its definition.
print <word>
If <word> is found in the BST, it is printed along with its definition. If not found, nothing is printed.
printInOrder
Print all words and their definitions, in alphabetical order. This will be an in-order tree traversal.
quit
Program terminates (do not call exit(), just return)
The following two commands are also required, although they are only useful for checking the correctness of your implementation.

printPreOrder
Print all words and their definitions, using a pre-order tree traversal.
printPostOrder
Print all words and their definitions, using a post-order tree traversal.

You may need to add public and/or private functions or private member variables. In BST, use a private inner class Node, with public member variables and constructor/destructor. This makes it so that Node cannot be seen outside BST, and BST has public access to everything in Node. You may want to add additional constructors for Node. Your approach must correspond to this specification, including the naming of classes and member variables and functions. This eases the task of the grader who has to look at your code! Note especially that Node stores pointers to strings; it does not store the strings themselves. You are responsible for all memory allocation and deallocation. In order to implement the "print all" functions, you might consider adding functions that will return a vector of const string pointers (or references) in the appropriate order. This would allow you to get the dump of the dictionary in one function call. Returning pointers or references will be efficient, and making them const will protect the dictionary contents. You might find this discussion of const helpful, as well as Dr. Gibson's tutorial on references & constants.
To maximize points, implement, test, and debug features in the following order. Testing for points will be done incrementally in this order.

add
print
printInOrder
remove
printPreOrder
printPostOrder
Additional Requirements:

Your program must compile and execute on jaguar using: CFlags = -std=c++11 -Wall -W -Werror -pedantic - otherwise you will receive a zero on the assignment. Do not turn in code that you have not compiled and executed on jaguar. You will also want to include -g while debugging.
You must base your implementation on the provided UML. You must implement what is shown, and you will need to add to it.
All reading input, parsing, and printing output should be done in either main.cpp or in Dictionary, one or the other. BST should not do any I/O.
Remove all debugging statements and unused commented code before turning it in. Your code should look clean and professional.
Create a text file called readme with a status report - what works in your implementation, what doesn't work, what was challenging or easy.
