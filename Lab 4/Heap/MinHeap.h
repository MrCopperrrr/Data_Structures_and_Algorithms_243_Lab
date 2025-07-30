#ifndef __MINHEAP__H__
#define __MINHEAP__H__

#include "MaxHeap.h"

class MinHeap
{
public:
    MinHeap();
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

#endif //__MINHEAP__H__
