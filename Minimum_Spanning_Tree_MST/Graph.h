/**
 * @file Graph.h The declaration for Graph.cpp file.
 *
 * @brief This file is used to declare the function
 *        skeleton to implement and maintain the map
 *        , graph or adjanceny list and other helper
 *        functionalities for MST.
 * @author Akshay Jain
 * @date 12/03/15
 **/

#ifndef __GRAPH_H
#define __GRAPH_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "MinPriority.h"

using namespace std;

class Graph
{
   public:
      Graph();
      ~Graph();
      void addVertex(string name);
      void addEdge(string from, string to, int weight);
      void mst(string start);
      string getSource() { return source; };

   private:
      class Vertex
      {
         public:
            Vertex();
            Vertex(string piP, int keyP);
            ~Vertex();
            string pi;
            int key;
      };

      class Neighbor
      {
         public:
            Neighbor();
            Neighbor(string name, int weight);
            ~Neighbor();
            string name;
            int weight;
      };

      map<string, Vertex*> vertices;
      map<string, vector<Neighbor*>*> adjList;
      MinPriorityQ *minQ;
      void initializeMinQ();
      void fillMinQ(string vertex, int initWeight);
      vector<Neighbor*> *findAdjacency(string vertex);
      map<string, Vertex*>::iterator itr, itr2;
      bool ifBegin;
      map<string, Vertex*>::iterator vertexAttrib(string vertex, char flag);
      int totalWeight;
      string source;
      int weightUV(string u, string v);
      int keyOfV(string v);
      void updatePredecessor(string u, string v, int weight);
      void printVertex(string startVertex);

};
#endif
