/* 
 *@File - knapsack.cpp
 *
 *@Desc - This files solves the knapsack problem
 *         using dynamic programming. It uses vectors of
 *         vectors to store best values and backtracking.
 *         It recursively find the items to be picked up.
 *
 *@Author - Akshay Jain, <ajain2@mail.csuchico.edu>
 *@Credits - Dr. Elena Harris, CSU, Chico.
 *@Date - 03/20/2016
 *
 *@Brief - This program finds the items, with the
 *         maximum value possible, for a thief to 
 *         take for a given knapsack capacity. The
 *         recurrence relation used to solve this
 *         problem is as follow:
 *         V[1,j] = 0  , if w1 > j
 *         V[1,j] = vi , if w1 <= j
 *         V[i,j] = V[i-1,j], if wi > j
 *         V[i,j] = max(V[i-1,j], V[i-1, j-wi] + vi) if wi<=j
 *
 *         The following for Backtracking:
 *         B[i,j] = j , if i is not in optimal solution
 *         B[i,j] = j - wi, if i is in optimal solution.
 */


#include <iostream>
#include <sstream>
#include <vector>
#include <utility>

using namespace std;


class Knapsack
{
   private:
      int capacity;
      int numberOfItems;
      bool readyToDisplay;
      vector<pair<int, int> > items;
      //To store best values
      vector<vector<int>> bestValues;
      //To store the backtracking
      vector<vector<int>> backTrack;
      int fillValueAndBacktrack();
      int findMaximum(int, int);
      //Recursive function to backtrack items
      bool backTrackItems(int, int);

   public:
      Knapsack();
      Knapsack(int, int);
      int fillItemsVector();
      void display();
};


/*
Func : Knapsack::Knapsack()
Desc : The default contructor for class Knapsack that
       initializes the member flag to false. It is set
       true when program successfully fills/solves the
       up the items and values table.
I/P  : N/A
O/P  : N/A
 */
Knapsack::Knapsack()
{
   readyToDisplay = false;
}


/*
Func : Knapsack::Knapsack(int totalItems, int knapsack)
Desc : The parameterised contructor for class Knapsack
       to intialize the vectors of vectors for best values
       and backtracking of items and store the knapsack
       capacity and total number of items.
I/P  : int totalItems - total number of items
       int knapsack - the knapsack capacity(weight)
O/P  : N/A
 */
Knapsack::Knapsack(int totalItems, int knapsack)
{
   numberOfItems = totalItems;
   capacity = knapsack;
   //Initialize the vector of vector with the size and a default value
   bestValues = vector<vector<int>>(numberOfItems, vector<int>(knapsack+1, 99));
   backTrack = vector<vector<int>>(numberOfItems, vector<int>(knapsack+1, -1));
}



/*
Func : void Knapsack::display()
Desc : This function is used to display the total value
       and items needs to be picked by thief(calls the
       recursive backTrackItems(int, int) function).
I/P  : N/A
O/P  : N/A
 */
void Knapsack::display()
{
    for(int i = 0; i < numberOfItems; i++)
    {
        for(int j = 0; j < capacity; j++)
        {
            cout<<bestValues[i][j]<<" ";
        }
        cout<<endl;
    }

   if(readyToDisplay)
   {
      cout<<bestValues[numberOfItems-1][capacity]<<endl;
      //recursive function to backtrack items
      backTrackItems(numberOfItems - 1, capacity);
      cout<<endl;
   }
}


/*
Func : bool Knapsack::backTrackItems(int row, int col)
Desc : This is the recursive function used to backtrack
       the items that thief should picked up to get
       items worth maximum value.
I/P  : int row - row index of the backTrack table
       int col - column index of the backTrack table
O/P  : bool - returns true when row < 0, false otherwise.
 */
bool Knapsack::backTrackItems(int row, int col)
{
   //Return when backtrack is done and row is less than 0
   if(row < 0)
      return true;
   backTrackItems(row-1, backTrack[row][col]);
   if(backTrack[row][col] < col)
   {
      cout<<(row+1)<<" ";
   }
   //Return when backtrack is done and row equals to 0
   return false;
}


/*
Func : int Knapsack::findMaximum(int i, int j)
Desc : The function is used to find maximum between 
       two possibilities when weight of ith item is
       less than or equal to j, and also fill the 
       backtracking accordingly.
I/P  : int i, int j - index value(for row and colomn
                      respectively.
O/P  : int - Returns the maximum value always,
             never returns 0.
 */
int Knapsack::findMaximum(int i, int j)
{
   //condition to check valid index(column)
   if((j - items[i].second) < 0)
   {
      backTrack[i][j] = j;
      return bestValues[i-1][j];
   }
   else
   {
      int w = items[i].second;
      w = j - w;

      //Selects i'th item when two possible values are equal
      if(((bestValues[i-1][w]) + items[i].first) >= bestValues[i-1][j])
      {
         backTrack[i][j] = w;
         return ((bestValues[i-1][w]) + items[i].first);
      }
      else
      {
         backTrack[i][j] = j;
         return bestValues[i-1][j];
      }
      //
   }
   //Control never reaches here
   return 0;
}

/*
Func : int Knapsack::fillValueAndBacktrack()
Desc : This function is used to fill the bestvalues
       and backtracking using the recurrence relation
       defined at the header.
I/P  : N/A
O/P  : int - Returns 0 when succesfully executes function
             , non-zero value otherwise.
 */
int Knapsack::fillValueAndBacktrack()
{
   int i,j;
   //Filling values in the 2D vectors using the recurrence relation
   for(i = 0; i < numberOfItems; i++)
   {
      bestValues[i][0] = 0;
      backTrack[i][0] = 0;	
      for(j = 1; j <= capacity; j++)
      {
         if(items[0].second > j && i == 0)
         {
            bestValues[0][j] = 0;
            backTrack[0][j] = 0;
         }
         if(items[0].second <= j && i == 0)
         {
            bestValues[0][j] = items[0].first;
            backTrack[0][j] = j - items[0].second;
         }
         if(items[i].second > j && i > 0)
         {
            bestValues[i][j] = bestValues[i-1][j];
            backTrack[i][j] = j;
         }
         if(items[i].second <= j && i > 0)
         {
            //calls findMaximum() to find max out of 2 possible values
            bestValues[i][j] = findMaximum(i, j);
         }
      }
   }
   //Flag set to indicate all values are filled up
   readyToDisplay = true;
   return 0;
}


/*
Func : int Knapsack::fillItemsVector()
Desc : The function is used to read the input(Line 2,3) 
       and fill the items vector which hold the pair 
       (value and the weight)of each item. It also calls
       fillValueAndBacktrack() to fill the values and
       respective backtracking using recurrence relation, 
       defined at the header.
I/P  : N/A
O/P  : int - Returns 0 when succesfully executes function
             , non-zero value otherwise.
 */
int Knapsack::fillItemsVector()
{
   int j = 0;
   bool firstLine =  true;
   string cmdLine, word;
   //Reads the second and third input line
   for(int i = 0; i < 2; i++)
   {
      getline(cin, cmdLine);
      stringstream inputLine(cmdLine);
      while(getline(inputLine, word, ' '))	
      {
         if(firstLine)
         {
            //This stores the value of the item with weight initialised as 0
            int value = atoi(word.c_str());
            items.push_back(make_pair(value, 0));
         }
         else
         {
            //This stores the weight of the item
            int weight = atoi(word.c_str());
            items[j].second = weight;
            j++;
         }
      }
      firstLine = false;
   }
   fillValueAndBacktrack();
   return 0;	
}



/*
Func : int main()
Desc : This is the main() routine of the program,
       that reads input(Line 1), creates the object
       of class Knapsack and calls the appropriate
       functions to solve the knapsack problem.
I/P  : N/A
O/P  : int - Returns 0 when succesfully executes function
             , non-zero value otherwise.
 */
int main()
{
   int nOfItems = 0, knapsack;
   bool firstWord = true;
   string cmdLine, word;
   getline(cin, cmdLine);
   stringstream ss(cmdLine);
   //Reads the first line of the input
   while(getline(ss, word, ' '))
   {
      if(firstWord)
      {
         //This stores the total number of items
         if(nOfItems == 0)
            nOfItems = atoi(word.c_str());
      }
      else
         //This stores the knapsack capacity
         knapsack = atoi(word.c_str());
      firstWord = false;
   }

   //Instantiated the object of class Knapsack
   Knapsack thief(nOfItems, knapsack);
   //Items to store the 
   thief.fillItemsVector();	
   thief.display();
}
