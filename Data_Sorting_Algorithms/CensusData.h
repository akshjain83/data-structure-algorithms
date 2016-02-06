/**
 * @file CensusData.h   Declaration of the CensusData class.
 *
 *@brief
 *     This file contains declaration of various function
 *and helpers for different sorts.
 * @author Akshay Jain
 * @date 10/01/15
 */

#ifndef CSCI_311_CENSUSDATA_H
#define CSCI_311_CENSUSDATA_H

#include <vector>
using std::ifstream;
using std::string;
using std::vector;

class CensusData {
public:
   static const int POPULATION = 0;       // type of sort
   static const int NAME = 1;
   ~CensusData();
   void initialize(ifstream&);            // reads in data
   int getSize(){return data.size();}
   void print();                          // prints out data
   void insertionSort(int);               // sorts data using insertionSort
   void mergeSort(int);                   // sorts data using mergeSort
   void quickSort(int);                   // sorts data using quickSort
private:
   class Record {                         // declaration of a Record
   public:
      string* city;
      string* state;
      int population;
      Record(string&, string&, int);
      ~Record();
   };
   vector<Record*> data;                  // data storage
//
// You may add your private helper functions here!
//
// Overloaded functions
   void mergeSort(int p, int r, int type);
   void quickSort(int p, int r, int type);

// Other helper functions
   void merge(int p, int r, int, int type);
   int quickPartition(int p, int r, int type);
   int partition(int p, int r, int type);
   void pivotSwap(int &p, int &r);
};

#endif // CSCI_311_CENSUSDATA_H
