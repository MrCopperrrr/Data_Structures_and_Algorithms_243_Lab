#ifndef __HASHTABLE__CPP__
#define __HASHTABLE__CPP__

#include "HashTable.h"
#include <iostream.h>

template <class T>
HashTable<T>::HashTable()
{
	numBucks = 11; // should be a prime number
	sizeBuck = 3;
	int hashSize = numBucks * sizeBuck;
	hashArray = new hashItem<T>[hashSize];
	for(int i = 0; i < hashSize; i++) hashArray[i].occupied = false;
	for(int i = 0; i < OVERFLOW_SIZE; i++) overBuck[i].occupied = false;
}
//---------------------------------------------------------
template <class T>
HashTable<T>::HashTable(int num, int size)
{
	numBucks = num; 
	sizeBuck = size;
	int hashSize = numBucks * sizeBuck;
	hashArray = new hashItem<T>[hashSize];
	for(int i = 0; i < hashSize; i++) hashArray[i].occupied = false;
	for(int i = 0; i < OVERFLOW_SIZE; i++) overBuck[i].occupied = false;
}
//---------------------------------------------------------
template <class T>
HashTable<T>::~HashTable()
{
	delete [] hashArray;
	cout << "Destructor called\n";
}
//---------------------------------------------------------
template <class T>
int HashTable<T>::hashFunc(int key, int funcID)
{
	if(funcID == 0) return moduloDivision(key);
	else if(funcID == 1) return midSquare(key);
	else if(funcID == 2) return pseudoRandom(key);
	else return -1;
}
//---------------------------------------------------------
template <class T>
int HashTable<T>::moduloDivision(int key)
{
	if(key < 0) key = - key;
	return key % numBucks;
}
//---------------------------------------------------------
template <class T>
int HashTable<T>::midSquare(int key)
{
	// write your code here
	return -1;
}
//---------------------------------------------------------
template <class T>
int HashTable<T>::pseudoRandom(int key)
{	
	// write your code here
	return -1; 
}
//---------------------------------------------------------
template <class T>
bool HashTable<T>::insert(Record<T> data, int funcID)
{
	int hashVal = hashFunc(data.key, funcID);
	int location = hashVal * sizeBuck;
	if(hashArray[location].occupied == false) // insert into the first slot of bucket
	{
		hashArray[location].data = data;
		hashArray[location].occupied = true;
		cout << "Successful\n";
		return true;
	}
	return false;
}
//---------------------------------------------------------
template <class T>
bool HashTable<T>::search(int key, T& value, int funcID)
{
	int hashVal = hashFunc(key, funcID);
	int location = hashVal * sizeBuck;
	if(hashArray[location].occupied == true && hashArray[location].data.key == key) // search for the first slot of bucket
	{
		value = hashArray[index].data.value;
		cout << "Exist\n";
		return true;
	}		
	cout << "NOT exist\n";
	return false;
}

#endif //__HASHTABLE__CPP__
