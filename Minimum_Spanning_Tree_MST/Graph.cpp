/**
 * @file Graph.h The definction for Graph.h file.
 *
 * @brief This file is used to define the function
 *        skeleton to implement and maintain the map
 *        , graph or adjanceny list and other helper
 *        functionalities for getting Minimum Spanning
 *        Tree of the given input graph.
 * @author Akshay Jain
 * @date 12/03/15
 **/
#include "Graph.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
/*
Func: Graph::Graph()
Desc: This is the default constructor
      for class Graph. It initializes
      bool flag variables, used to check 
      certain conditions.
I/P : N/A
O/P : N/A
 */
Graph::Graph()
{
   ifBegin = false;
   totalWeight = 0;
   minQ = NULL;
}

/*
Func: Graph::~Graph()
Desc: This is the destructor for the class
      Graph. It manages the memory, free up
      any allocated space before termination.
I/P : N/A
O/P : N/A
 */
Graph::~Graph()
{
   for(auto it = vertices.begin(); it != vertices.begin(); it++)
   {
      Vertex *temp = it->second;
      delete temp;
   }
   for(auto it2 = adjList.begin(); it2 != adjList.end(); it2++)
   {
      vector<Neighbor*> *temp2 = it2->second;
      for(auto it3 = temp2->begin(); it3 != temp2->end(); it3++)
      {
         Neighbor *neww = *it3;
         if(neww)
            delete neww;
      }
   }
   delete minQ;
}

/*
Func: Graph::Vertex::Vertex()
Desc: This is the default constructor for 
      class Vertex, a private nested class
      of class Graph. It initializes the 
      parent and weight to default.
I/P : N/A
O/P : N/A
 */
Graph::Vertex::Vertex()
{
   pi = "NIL";
   key = 100;
}

/*
Func: Graph::Vertex::Vertex(string piP, int keyP)
Desc: This is the parameterised constructor for 
      class Vertex, a private nested class of 
      class Graph. It initializes the parent and
      weight with passed argument values.
I/P : string piP - Parent or Predecessor of the
                   vertex.
      int keyP - Key value of the vertex.
O/P : N/A
 */
Graph::Vertex::Vertex(string piP, int keyP)
{
   pi = piP;
   key = keyP;
}

/*
Func: Graph::Vertex::~Vertex()
Desc: This is the destructor for the
      class Vertex.
I/P : N/A
O/P : N/A
 */
Graph::Vertex::~Vertex()
{

}


/*
Func: Graph::Neighbor::Neighbor()
Desc: This is the default constructor for 
      class Neighbor, a private nested class
      of class Graph.
I/P : N/A
O/P : N/A
 */
Graph::Neighbor::Neighbor()
{

}

/*
Func: Graph::Neighbor::Neighbor(string name, int weight)
Desc: This is the parameterised constructor for 
      class Neighbor, a private nested class of 
      class Graph. It initializes the name and
      weight with passed argument values.
I/P : string name - Name of the Vertex.
      int weight - Value of the weight attribute.
O/P : N/A
 */
Graph::Neighbor::Neighbor(string name, int weight)
{
   this->name = name;
   this->weight = weight;
}


/*
Func: Graph::Neighbor::~Neighbor()
Desc: This is the destructor for the
      class Neighbor.
I/P : N/A
O/P : N/A
 */
Graph::Neighbor::~Neighbor()
{

}


/*
Func: void Graph::initializeMinQ()
Desc: This function is used to instantiate
      the min priority queue, creates the
      the new minQ with the size as of the
      vertices size.
I/P : N/A
O/P : N/A
 */
void Graph::initializeMinQ()
{
   ifBegin = true;
   minQ = new MinPriorityQ((int)vertices.size());
}

/*
Func: 
map<string,Graph::Vertex*>::iterator 
Graph::vertexAttrib(string vertex,char flag)

Desc: This function is used to calculate map 
      begin, end and find access iterator. It
      returns the iterator point depending
      upon the flag argument passed.
      I/P : string vertex - name of the vertex.
      char flag - Access iterator that need to
      calculate, f for find, b for
      begin and e for end.
O/P : map<string, Graph::Vertex*>::iterator -
            The iterator point in the map.
 */
map<string, Graph::Vertex*>::iterator Graph::vertexAttrib(string vertex, char flag)
{
   if(flag == 'f')
      return vertices.find(vertex);
   /*
      else if(flag == 's')
      return vertices.size();
    */
   else if(flag == 'b')
      return vertices.begin();
   else if(flag == 'e')
      return vertices.end();
   return vertices.end();
}

/*
Func: void Graph::fillMinQ(string vertex, int initWeight)
Desc: This function is used to insert the vertices
      into the min priority queue.
I/P : string vertex - Name of the vertex, that is
                      source here.
      int initWeight - Initial weight, which is 0.
O/P : N/A
 */
void Graph::fillMinQ(string vertex, int initWeight)
{
   auto it = vertices.end();;
   auto begin = vertices.end();;
   auto end = vertices.end();;
   minQ->decreaseKey(vertex, initWeight);
   begin = vertexAttrib(vertex, 'b');
   end = vertexAttrib(vertex, 'e');
   for(it = begin; it != end; ++it)
   {
      Vertex *neww = it->second;
      minQ->insert(it->first, neww->key);
   }
   //minQ->minHeapify(1);
   minQ->buildMinHeap();
}


/*
Func: vector<Graph::Neighbor*>* Graph::findAdjacency(string vertex)
Desc: This function is used to get the adjacency
      list of the particular vertex passed as
      the argument.
I/P : string vertex - Name of the vertex
O/P : <Graph::Neighbor*>* - Adjacency List of
                            the vertex.
 */
vector<Graph::Neighbor*>* Graph::findAdjacency(string vertex)
{
   auto it = adjList.find(vertex);
   //return it->second;
   vector<Neighbor*> *adj2 = it->second;
   return adj2;
}


/*
Func: int Graph::weightUV(string u, string v)
Desc: This function is used to calculate the
      weight between u and v or the distance,
      which is the key of following one.
I/P : string u - Name of the vertex
      string v - Name of the vertex
O/P : int - Returns the distance or weight if
            found, 0 otherwise.
 */
int Graph::weightUV(string u, string v)
{
   vector<Neighbor*> *adj = findAdjacency(u);
   for(auto it = adj->begin(); it != adj->end(); ++it)
   {
      Neighbor *neww = *it;
      if(neww && neww->name == v)
      {
         return neww->weight;
      }
   }
   return 0;
}


/*
Func: int Graph::keyOfV(string v)
Desc: This function is used here to get the 
      key of the particular vertex if found.
I/P : string v - Name of the vertex
O/P : int - Returns the key if vertex is
            found, 0 otherwise.
 */
int Graph::keyOfV(string v)
{
   auto it = vertexAttrib(v,'f');
   Vertex *temp = it->second;
   return temp->key;
}


/*
Func: 
void Graph::updatePredecessor(string u, string v, int weight)

Desc: This function is used to update the parent 
or say the predecessor of the vertex passed
as argument, and also the distance or weight.
I/P : string u - Name of the vertex, parent here.
string v - Name of the vertex, who needs to update.
int weight - The weight or distance upto parent.
O/P : N/A
 */
void Graph::updatePredecessor(string u, string v, int weight)
{
   auto it = vertexAttrib(v,'f');
   Vertex *temp = it->second;

   //Update Predecesoor or Parent
   temp->pi = u;
   temp->key = weight;
}

/*
Func: void Graph::addVertex(string name)
Desc: This function is used to add the vertex 
to the map and make a pair of the
name of the vertex and vertex element.
It adds to the map of type Vertex and string.
I/P : string name - Name of the vertex.
O/P : N/A
 */
void Graph::addVertex(string name)
{
   itr2 = vertexAttrib(name, 'e');
   itr = vertexAttrib(name,'f');
   if(vertices.size() == 0)
   {
      source = name;
   }
   if(itr == itr2)
   {
      Vertex *newV = new Vertex();
      vertices.insert(make_pair(name, newV));
   }
}
/*
Func: void Graph::addEdge(string from, string to, int weight)
Desc: This function is used to add the edge
to the map of adjacency list and make a pair of the
name of the vertex and its neighbor Veretx element.
It adds to the map of type Neighbor and string.
I/P : string from - Name of the vertex, edge 'from'
string to - Name of the vertex, edge 'to'
int weight - The weight or value of edge.
O/P : N/A
 */
void Graph::addEdge(string from, string to, int weight)
{

   auto it = adjList.find(from);
   auto adjEnd = adjList.end();
   auto  vEnd = vertices.end();
   vEnd = vertexAttrib(to,'e');
   itr = vertexAttrib(from,'f');
   itr2 = vertexAttrib(to,'f');
   if(itr != vEnd && itr2 != vEnd)
   {
      if(it == adjEnd)
      {
         Neighbor *neww = new Neighbor(to, weight);
         vector<Neighbor*> *stackNeighbor = new vector<Neighbor*>;
         stackNeighbor->emplace_back(neww);
         adjList.insert(make_pair(from, stackNeighbor));
      }
      else
      {
         vector<Neighbor*> *stackNeighbor = it->second;
         bool vertex_found = false;
         for(auto i = stackNeighbor->begin(); i != stackNeighbor->end(); ++i)
         {
            Neighbor *neww = *i;
            if(neww->name == to)
            {
               vertex_found = true;
               break;
            }
         }
         if(!vertex_found)
         {
            Neighbor *neww = new Neighbor(to, weight);
            stackNeighbor->emplace_back(neww);
         }
      }
      //Beginning of minQ
      if(!ifBegin)
         initializeMinQ();
   }
}


/*
Func: void Graph::mst(string start)
Desc: This function is used for the implementation
of Prim's algorithm for minimum spanning tree.
I/P : string start - Name of the vertex, the source
or root vertex from where mst
starts.
O/P : N/A
 */
void Graph::mst(string start)
{
   string u = "";
   itr = vertexAttrib(start,'f');
   Vertex *root = itr->second;
   root->key = 0;
   fillMinQ(start, 0);
   //unsigned int heapSize = minQ->minHeapSize();
   while(minQ->minHeapSize() >= 1)
   {
      u = minQ->extractMin();
      vector<Neighbor*> *adj = findAdjacency(u);
      for(auto it = adj->begin(); it != adj->end(); ++it)
      {
         //Neighbor *v = *(*it);
         Neighbor *v = *it;
         int udistv = weightUV(u, v->name);
         int vKey = keyOfV(v->name);
         if((minQ->isMember(v->name) == true) && (udistv < vKey))
         {
            updatePredecessor(u, v->name, udistv);
            minQ->decreaseKey(v->name, udistv);
         }
         //printVertex(u);
      }
      printVertex(u);
   }
   cout<<totalWeight<<endl;
}

/*
Func: void Graph::printVertex(string startVertex)
Desc: This function is used for the implementation
of Prim's algorithm for minimum spanning tree.
I/P : string startVertex - Name of the vertex to be
print. 
O/P : N/A
 */
void Graph::printVertex(string startVertex)
{
   auto it = vertexAttrib(startVertex,'f');
   Vertex *temp = it->second;
   cout<<it->first<<" "<<temp->pi<<" ";
   cout<<temp->key<<endl;
   totalWeight = totalWeight + temp->key;
}
