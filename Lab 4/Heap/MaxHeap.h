#ifndef __MAXHEAP__H__
#define __MAXHEAP__H__

enum Error_code {success,fail,rangeerror,overflow,underflow,
				not_present,dupplicated,found};
const int max_length = 30;
//---------------------------------------------------------				
class Heap
{
public:
	Heap();
	Error_code insertHeap(int dataIn);
	Error_code deleteHeap(int &dataOut);
	Error_code buildHeap(int listData[], int size);
	bool full();
	bool empty();
	int size();
	void clear();
	void printHeap();
private:
	int count;
	int data[max_length];
	void swap(int low, int high);
	void ReheapUp(int position);
	void ReheapDown(int position, int lastPosition);
};
				
#endif //__MAXHEAP__H__
