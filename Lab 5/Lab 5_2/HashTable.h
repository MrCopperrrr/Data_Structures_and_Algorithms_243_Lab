#ifndef __HASHTABLE__H__
#define __HASHTABLE__H__

const int OVERFLOW_SIZE = 30;

template <class Entry>
struct Record
{
	int key;
	Entry value;
};
//---------------------------------------------------------
template <class Item>
struct hashItem
{
	Record<Item> data;
	bool occupied;
};
//---------------------------------------------------------
template <class T>
class HashTable   
{   
public:
	HashTable();             
	HashTable(int num, int size); 
	~HashTable(); 
	int hashFunc(int key, int funcID);
	bool insert(Record<T> data, int funcID);
	bool search(int key, T& value, int funcID);
private:
	hashItem<T>* hashArray;
	hashItem<T> overBuck[OVERFLOW_SIZE];
	int numBucks;
	int sizeBuck;
	int moduloDivision(int key);
	int midSquare(int key);
	int pseudoRandom(int key);
};

#endif //__HASHTABLE__H__
