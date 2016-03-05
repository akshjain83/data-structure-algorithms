/*
*@File   : core.cpp
*@Brief  : This file contain main() routine and other 
*          functions used to find the core of a tree
*          using Breadth First Search algorithm.
*
*
*@Author : Akshay Jain, <ajain2@mail.csuchico.edu>
*@Date   : 03/02/2016
*/


#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <vector>
#include <random>
using namespace std;

class Core
{
   private:
      int numberOfVertex;
      list<int> *adj;
      vector<int> path;
      void findCore();
      bool secondBFS;
   public:
      Core();
      Core(int);
      ~Core();
      void addEdge(int, int);
      int BFS(int);
      void display();
};


/* 
Core::Core()
Desc : Default Constructor to initialize data member
       secondBFS is intialized false and set to true
       when BFS is executed second time.
I/P  : N/A
O/P  : N/A
*/
Core::Core()
{
   secondBFS = false;
}


/* 
Core::Core(int n)
Desc : Parameterised Constructor to dynamically 
       allocate list<int> and store the value  
       of number of vertex.
I/P  : int n - number of Vertex
O/P  : N/A
*/
Core::Core(int n)
{
   numberOfVertex = n;
   adj = new list<int>[n];
}


/* 
Core::~Core()
Desc : Destructor to free up memory space by
       deleting the dymanically allocated space
       by using STL list destructor.
I/P  : N/A
O/P  : N/A
*/
Core::~Core()
{
   delete [] adj;
}


/*void Core::addEdge(int u, int v)
Desc : Function used to maintain the 
       adjacency list.
I/P  : int u - vertex whose adjacency
               list is updated
       int v - vertex to be added to
               in adjacency list of u.
O/P  : N/A
*/ 
void Core::addEdge(int u, int v)
{
   adj[u].push_back(v);
}


/* 
void Core::findCore()
Desc : This function is used to find the core
       of the tree, number of cores depend upon
       length of diameter.
I/P  : N/A
O/P  : N/A
*/
void Core::findCore()
{
   int diameterLength = path.size();
   if((diameterLength%2) == 0)
   {
      int core1, core2;
      core1 = (diameterLength / 2);
      core2 = core1 - 1;
      core1 = path[core1];
      core2 = path[core2];
      cout<<((core1 < core2)?core1:core2)<<" "<<((core1 > core2)?core1:core2)<<endl; 
   }
   else
   {
      int core = diameterLength / 2;
      cout<<path[core]<<endl;
   }
}


/* 
void Core::display()
Desc : This public function calls the private function
       findcore() to find the core of the tree.
I/P  : N/A
O/P  : N/A
*/
void Core::display()
{
   findCore();
}


/* 
int Core::BFS(int source)
Desc : This function is implementation of Breadth First Search
       and helper functionality needed to find the core.
I/P  : int source - vertex on which BFS is run
O/P  : int - one endpoint of diamter if BFS run first time,
             otherwise 0, if BFS run second time.
*/
int Core::BFS(int source)
{
   vector<int> distance;
   vector<int> parent;
   for(int i = 0; i < numberOfVertex; i++)
   {
      distance.push_back(-1);
      parent.push_back(source);
   } 
   list<int> Q;
   int u = source;
   distance[source] = 0;
   Q.push_back(source);
   list<int>::iterator itr;
   int end = 0;
   while(!Q.empty())
   {
      u = Q.front();
      end = u;
      Q.pop_front();
      for(itr = adj[u].begin(); itr != adj[u].end(); ++itr )
      {
         if(distance[*itr] == -1)
         {
            parent[*itr] = u; 
            distance[*itr] = distance[u] + 1;
            Q.push_back(*itr); 
         }
      }
   }
   if(secondBFS)
   {
      secondBFS = false;
      int par;
      path.push_back(end);
      par = parent[end];
      while(par != parent[par])
      {
         path.push_back(par);
         par = parent[par];
      }
      path.push_back(par);
      return 0;
   }
   secondBFS = true;
   return end;
}


/* 
int main()
Desc : This is the main() routine of the algorithm.
I/P  : N/A
O/P  : Return 0 if main() runs successfully.
*/
int main()
{
   srand(time(NULL));
   int from = 0, lineNo = 0;
   string cmdline, loop, a;
   getline(cin, a);
   int numberOfV = atoi(a.c_str());
   Core myCore(numberOfV);
   if(numberOfV <= 0)
      return 0;
   while((getline(cin,cmdline)) &&  lineNo < numberOfV)
   {
      if(cmdline=="")
      {}
      else
      {
         stringstream l(cmdline);
         bool numberofEdges = true;
         int numberOfE =0, i =0;
         while(getline(l,loop,' '))
         {
            if(numberofEdges)
            {
               numberOfE = atoi(loop.c_str());
               numberofEdges = false;
            }
            else
            {
               int to = atoi(loop.c_str());
               if(i < numberOfE && lineNo < numberOfV)
               {
                  if(to < numberOfV)
                  {
                     myCore.addEdge(from, to);
                     i++;
                  }
                  else
                     break;
               }
            }
         }
         lineNo++;
         from++;
      }
   }
   int i = rand() % numberOfV;
   int endp = myCore.BFS(i);
   myCore.BFS(endp);
   myCore.display();
   return 0;
}




