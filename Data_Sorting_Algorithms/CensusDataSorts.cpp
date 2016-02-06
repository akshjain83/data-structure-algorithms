/**
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 *
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Akshay Jain
 * @date 10/02/15
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include "CensusData.h"

std::default_random_engine generator;
using namespace std;

/*
FUNC : void CensusData::insertionSort(int type)
DESC : This function is c++ implementation of
       cormen's insertion sort algorithm.
       It sorts data on the basis of target type.

I/P  : int type - target type, population or city name.
O/P  : N/A
*/
void CensusData::insertionSort(int type)
{
  Record *key = NULL;
  int i = 0;
  for(int j = 1; j < getSize(); j++)
  {
     key = data[j];
     i = j - 1;
    if(type == 0)
    {
        while (i >= 0 && (data[i]->population > key->population))
        {
          data[i+1] = data[i];
          i--;
        }
        data[i+1] = key;
    }
    else if(type == 1)
    {
        while (i >= 0 && (*(data[i])->city > *(key)->city))
        {
          data[i+1] = data[i];
          i--;
        }
        data[i+1] = key;
    }
  }
}


/*
FUNC : void CensusData::mergeSort(int type)
DESC : This function is used to determine p
       and r, to pass arguments while calling
       overloaded function mergeSort().

I/P  : int type - target type, population or city name.
O/P  : N/A
*/
void CensusData::mergeSort(int type)
{
  int r = getSize() - 1;
  mergeSort(0,r,type);
}

/*
FUNC : void CensusData::mergeSort(int p, int r, int type)
DESC : This function is c++ implementation of
       cormen's merge sort algorithm.
       It sorts data on the basis of target type.
       Its an oveloaded funtion.

I/P  : int p, int r - indices.
       int type - target type, population or city name.
O/P  : N/A
*/
void CensusData::mergeSort(int p, int r, int type)
{
  if(p < r)
  {
    int q = floor((p + r)/2);
    mergeSort(p,q,type);
    mergeSort(q+1,r,type);
    merge(p,q,r,type);
  }
}

/*
FUNC : void CensusData::merge(int p, int q, int r, int type)
DESC : This function is c++ implementation of merge method
       for cormen's merge sort algorithm. It merges data
      on the basis of target type.

I/P  : int p, int q, int r - indices.
       int type - target type, population or city name.
O/P  : N/A
*/
void CensusData::merge(int p, int q, int r, int type)
{
  long int n1,n2;
  int i,j,k;
  n1 = q - p + 1;
  n2 = r - q;
  vector<Record*> L(n1);
  vector<Record*> R(n2);
  for(i = 0 ; i < n1 ; i++)
  {
    L[i] = data[p+i];
  }
  for(j = 0 ; j < n2 ; j++)
  {
    R[j] = data[q+j+1];
  }
  i = j = 0;
  k = p;
  if(type == 0)
  {
    while(i < n1 && j < n2)
    {
      if(L[i]->population <= R[j]->population)
      {
        data[k] = L[i];
        i++;
      }
      else
      {
        data[k] = R[j];
        j++;
      }
      k++;
    }
  }
  else if(type == 1)
  {
    while(i < n1 && j < n2)
    {
      if(*(L[i])->city <= *(R[j])->city)
      {
        data[k] = L[i];
        i++;
      }
      else
      {
        data[k] = R[j];
        j++;
      }
      k++;
    }
  }
  while(i < n1)
  {
    data[k] = L[i];
    i++;
    k++;
  }
  while(j < n2)
  {
    data[k] = R[j];
    j++;
    k++;
  }
}


/*
FUNC : void CensusData::quickSort(int type)
DESC : This function is used to determine p
       and r, to pass arguments while calling
       overloaded function quickSort().

I/P  : int type - target type, population or city name.
O/P  : N/A
*/
void CensusData::quickSort(int type)
{
  int r = data.size() - 1;
  generator.seed(time(0));
  quickSort(0, r, type);
}

/*
FUNC : void CensusData::quickSort(int p, int r, int type)
DESC : This function is c++ implementation of
       cormen's quick sort algorithm.
       It sorts data on the basis of target type.
       Its an oveloaded funtion.

I/P  : int p, int r - indices.
       int type - target type, population or city name.
O/P  : N/A
*/
void CensusData::quickSort(int p, int r, int type)
{
  if(p < r)
  {
    int q = partition(p,r,type);
    quickSort(p,q-1,type);
    quickSort(q+1,r,type);
  }
}

/*
FUNC : int CensusData::partition(int p, int r, int type)
DESC : This function is used to call pivotSwap()
       which generates random number between p and r
       and exchanges the data in original vector. Then
       the partition method for cormen's quick sort
       algorithm is called.

I/P  : int p, int r - indices.
       int type - target type, population or city name.
O/P  : int - Index for the pivot
*/
int CensusData::partition(int p, int r, int type)
{
  pivotSwap(p,r);
  return quickPartition(p,r,type);
}

/*
void CensusData::pivotSwap(int &p, int &r)
DESC : This function is used to generate a random
       index number between p and r to get pivot q
       and then swap the data at indices q and r.

I/P  : int &p, int &r - indices.
O/P  : N/A
*/
void CensusData::pivotSwap(int &p, int &r)
{
  std::uniform_int_distribution<int> distribution(p,r);
  int x = distribution(generator);
  Record *oldPivot;
  oldPivot = data[r];
  data[r] = data[x];
  data[x] = oldPivot;
}


/*
FUNC : int CensusData::quickPartition(int p, int r, int type)
DESC : This function is c++ implementaion of cormen's
       method for partition for quick sort.

I/P  : int p, int r - indices.
       int type - target type, population or city name.
O/P  : int - Index for the pivot
*/
int CensusData::quickPartition(int p, int r, int type)
{
  Record *x = data[r];
  int i = p - 1;
  if(type == 0)
  {
    for(int j = p; j < r; j++)
    {
      if(data[j]->population <= x->population)
      {
        i = i + 1;
        Record *temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }
    Record *temp = data[i+1];
    data[i+1] = data[r];
    data[r] = temp;
  }
  else if(type == 1)
  {
    for(int j = p; j < r; j++)
    {
      if(*(data[j])->city <= *(x)->city)
      {
        i = i + 1;
        Record *temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }
    Record *temp = data[i+1];
    data[i+1] = data[r];
    data[r] = temp;
  }
  return i + 1;
}
