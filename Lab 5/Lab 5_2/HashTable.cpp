#ifndef __HASHTABLE__CPP__
#define __HASHTABLE__CPP__

#include "HashTable.h"
#include <iostream>

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
	// Mid-square method: square the key, extract middle digits
	if (key < 0) key = -key;
	long long squared = (long long)key * (long long)key;
	// Extract middle digits: for simplicity, get 2 or 3 digits from the middle
	int numDigits = 0;
	long long temp = squared;
	while (temp > 0) {
		temp /= 10;
		numDigits++;
	}
	int mid = numDigits / 2;
	int extractDigits = 2; // extract 2 digits from the middle
	long long divisor = 1;
	for (int i = 0; i < mid - extractDigits/2; i++) divisor *= 10;
	int midVal = (int)((squared / divisor) % (int)pow(10, extractDigits));
	return midVal % numBucks;
}
//---------------------------------------------------------
template <class T>
int HashTable<T>::pseudoRandom(int key)
{	
	// Simple linear congruential generator: (a*key + b) % numBucks
	// Choose two prime numbers for a and b
	const int a = 31; // prime
	const int b = 17; // prime
	if (key < 0) key = -key;
	int val = (a * key + b) % numBucks;
	return val;
}
//---------------------------------------------------------
template <class T>
bool HashTable<T>::insert(Record<T> data, int funcID)
{
	int hashVal = hashFunc(data.key, funcID);
	int location = hashVal * sizeBuck;
	// Try to insert into the bucket
	for (int i = 0; i < sizeBuck; i++) {
		int idx = location + i;
		if (!hashArray[idx].occupied) {
			hashArray[idx].data = data;
			hashArray[idx].occupied = true;
			cout << "Successful\n";
			return true;
		}
	}
	// If bucket is full, insert into overflow bucket
	for (int i = 0; i < OVERFLOW_SIZE; i++) {
		if (!overBuck[i].occupied) {
			overBuck[i].data = data;
			overBuck[i].occupied = true;
			cout << "Inserted in overflow bucket\n";
			return true;
		}
	}
	cout << "Failed: Overflow bucket full\n";
	return false;
}
//---------------------------------------------------------
template <class T>
bool HashTable<T>::search(int key, T& value, int funcID)
{
	int hashVal = hashFunc(key, funcID);
	int location = hashVal * sizeBuck;
	// Search in the bucket
	for (int i = 0; i < sizeBuck; i++) {
		int idx = location + i;
		if (hashArray[idx].occupied && hashArray[idx].data.key == key) {
			value = hashArray[idx].data.value;
			cout << "Exist\n";
			return true;
		}
		// If slot is empty, key cannot be in this bucket
		if (!hashArray[idx].occupied) {
			cout << "NOT exist\n";
			return false;
		}
	}
	// If bucket is full, search in overflow bucket
	for (int i = 0; i < OVERFLOW_SIZE; i++) {
		if (overBuck[i].occupied && overBuck[i].data.key == key) {
			value = overBuck[i].data.value;
			cout << "Exist (in overflow)\n";
			return true;
		}
	}
	cout << "NOT exist\n";
	return false;
}

#endif //__HASHTABLE__CPP__
