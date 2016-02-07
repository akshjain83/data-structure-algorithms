Citation - This assignment is from a course at California State University, Chico. Thereby, all credits for assignment instructions and program problem statement should be given to the cited personnel or organization. http://www.ecst.csuchico.edu/~judyc/1516F-csci311/assignments/program3-hash.html Professor Judith Challinger, California State University, Chico

The Program

In this assignment you will write a program to create a hash table for 5-letter words. You will need to design and implement your own hash function. Your grade will be based on both passing the functionality tests and the success of your hash function.


The Hash Table

Use chaining to resolve collisions. You must use the Standard Template Library list class for your chains.

hash.h - Use this header file and ensure that you provide the definitions of all the specified functions in hash.cpp. You may add additional functions where indicated. You must use the function prototypes exactly as provided. If you change these function prototypes at all, your code will not compile with the test harness. The required functions are:

void print()

Print the hash table to standard output (cout) in the following format. Each array location will be printed on a seperate line. The line will start with the number of the array location followed by a colon (:) and followed by one tab. You will then print each key stored at that hash array location separated by a comma (,) and a single space. After all words at that hash array location are printed, you will output a newline. 

hash.out - Output obtained by printing the hash table in main.cpp (provided below) to the output file. The provided main() outputs this file. Use diff to ensure that your output file matches this one using the provided main.cpp. 

void processFile(string filename)

Add all of the words in the file specified as "filename" to the hash table. Use push_back to insert each of the words into the list at the hash location that the words hashes to. Updates statistics.

test1.txt - The sample input file used to obtain hash.out given above. The provided main() reads this file. 

bool search(string word)

Search for the string "word" in the hash table. Return true if it is found and false if it is not found.

void remove(string word)

Remove the string "word" from the hash table. Updates statistics as needed. 

void output (string filename)

Output the hash table to the file specified as "filename." The format should be exactly the same as specified for the print() function.

void printStats()

Print the hash statistics. During program execution, you will need to keep track of some statistics.

int collisions - keep a count of the number of collisions when doing inserts. A collision occurs when a word is being inserted into a non-empty list. Add 1 to the count when there is a collision. All other operations should not affect count in any way.

unsigned int longestList - keep track of the length of the longest list ever generated. Update after every insert. This will never be decremented. 

double avgLength - keep track of the running average list length (a running average means that you will update this value after EACH SUCCESSFUL insert and remove operation and not simply find the average list length at the end of the program). So after EACH SUCCESSFUL insert or remove operation, determine the current average list length of the hash table. The current average list length of the hash table is defined as number of items in the hash table divided by the number of non-empty lists. Then average the current average list length with the running average list length. Your running average list length must match mine exactly (you will see a sample below) in order to pass the functionality tests. Your average length variable should start at 0 and each time a successful insert/remove is done update the average length. Here is a formula you can use to update your average length: 

avgLength = (currentAvgListLen + avgLength) / 2.0 

load factor - you will also calculate and print the load factor for the table. There is no member variable for this.
The Hash Function

Review Cormen chapter 11.3 on hash functions. You will design and write your own hash function for this assignment. Your hash function should be unique. Do not share your hash function with other students.

hash_function.cpp - A very simple and very poor hash function is provided. You will need to delete the contents of the hash function and replace it with your own hash function. You MUST place your hash function code in the hash function in hash_function.cpp and link this file to your project with the makefile. This is extremely important because for some of the functionality tests of your program, we will be replacing your hash_function.cpp with this original (poor) version. DO NOT put any code necessary for correct operation of your program in hash_function.cpp besides your hash function. 

At the top of this file, use a large comment block to describe your hash function, why it is good, and how you happened upon it. There are a lot of good resources and tutorials on hashing and hash functions on the Web. Research is encouraged, however, you may not simply copy a hash function that you find somewhere. If you did research on the Web, you must give credit and include any links in the comments. Failure to provide this documentation at the top of hash_function.cpp will result in a zero for the hash function component of the grade.

Other Provided Files

main.cpp - A sample test harness. This contains enough for you to test the basic functionality of your hash table. It is recommended that you add to these tests, as we will when grading your submission! DO NOT put any code necessary for correct operation of your program in your main.cpp file since it will be replaced during grading. The output of your program must look EXACTLY like sample.out using the provided hash function in hash_function.cpp and a hash table size of 10.

sample.out - Sample output obtained by using main.cpp and hash_function.cpp, and redirecting standard output to a file. Your output must look EXACTLY like this, down to the spaces, tabs, etc. Do a diff to make sure. Grading is done by a script and if your output does not match exactly your submission will not pass the functionality tests.

makefile

Some of the larger word lists that may be used to grade your assignment:

dict5.txt
random.txt
sgb-words.txt
When grading the hash table will have entries numbering in the low thousands (<5,000). You can use the above files and experiment with table sizes, along with the statistics you are generating, to tune your hash function.

Additional Requirements:

Your program must compile and execute on jaguar using -std=c++11 -Wall -W -Werror -pedantic -D HASH_TABLE_SIZE=X
Be sure to document your code and be consistent with style, naming, indentation, etc.
Suggestions:


Citation: This assignment originated at UC Riverside
