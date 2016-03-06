Citation - This assignment is from a course at California State University, Chico. Thereby, all credits for assignment instructions and program problem statement should be given to the cited personnel or organization. http://www.ecst.csuchico.edu/~judyc/1516F-csci311/assignments/program3-hash.html Professor Judith Challinger, California State University, Chico


The Program

This program reads a weighted undirected graph from stdin and writes the structure of the MST(Minimum Spanning Tree) to stdout.

The input will consist of a set of alphanumeric (string) vertex identifiers on one line, separated by spaces. The vertices will be followed by a list of edges, one edge per line, specified by two vertex identifiers and a numerical weight. For example, this graph


would be input as follows:

A B C D E F G

A B 3

A E 4

B C 7 

B E 6

B F 5

C D 9

C F 8

D F 9

D G 4

E F 6

F G 8


The graph should be stored in an adjacency list. Sort each individual adjacency list on the identifiers of the adjacent vertices, in ascending alphabetical order. Use the first vertex specified in the input as the root of the MST.

At the time each vertex is extracted from the queue, print the vertex identifier, the identifier of its predecessor, and its key. In addition, print the total weight for the MST. The output for the input given above would be:

A NIL 0

B A 3

E A 4 

F B 5

C B 7 

G F 8 

D G 4 

31

Additional Requirements:

Your files must be named MinPriority.cpp/MinPriority.h, Graph.cpp/Graph.h, andMSTapp.cpp/MSTapp.h.

You may use vector or another container from the Standard Template Library as needed for each individual adjacency list. You may use vector for the minHeap. You are required to use map where indicated in the UML below.

You must implement the min-priority queue yourself (do not use the STL container adapter).

You should have MinPriority, Graph, and MSTapp classes. You may define additional classes as needed - put them in their own .cpp/.h files named using the class name (you really shouldn't need any others).

The weights will be in the range [1,...,99] so use something larger than 99 to represent infinity. 

The program must read from standard input and write to standard output. Use redirection to input commands from a file or output results to a file. 

Implement Prim's algorithm using the pseudocode in Chapter 23 of CLRS - keep the same function names (translated to acceptable C++ identifiers). This is so the grader can easily find your implementation of specific functionality. The function should be a member of the Graph class.

Implement a min priority queue based on a min-heap using the pseudocode in Chapter 6 - keep the same function names but named for min and translated to acceptable C++ identifiers.

Clearly define a public interface for each class and make everything else private.

Your program must compile and execute on jaguar. That is where it will be graded. If the code can't be compiled you will receive a zero.
Be sure to document your code and be consistent with style, naming, indentation, etc.
Your program must compile and execute on jaguar using -std=c++11 -Wall -W -Werror -pedantic 

