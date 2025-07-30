#include <iostream>
#include "MinHeap.h"
using namespace std;

MinHeap::MinHeap() {
    count = 0;
}

void MinHeap::ReheapUp(int position) {
    if(position > 0) {
        int parent = (position - 1) / 2;
        if(data[position] < data[parent]) {
            swap(position, parent);
            ReheapUp(parent);
        }
    }
}

void MinHeap::ReheapDown(int position, int lastPosition) {
    int left = 2 * position + 1;
    int right = 2 * position + 2;
    int minPos = position;
    if(left <= lastPosition && data[left] < data[minPos])
        minPos = left;
    if(right <= lastPosition && data[right] < data[minPos])
        minPos = right;
    if(minPos != position) {
        swap(position, minPos);
        ReheapDown(minPos, lastPosition);
    }
}

void MinHeap::swap(int low, int high) {
    int temp = data[low];
    data[low] = data[high];
    data[high] = temp;
}

bool MinHeap::full() {
    return (count == max_length);
}

bool MinHeap::empty() {
    return (count == 0);
}

int MinHeap::size() {
    return count;
}

void MinHeap::clear() {
    count = 0;
}

Error_code MinHeap::insertHeap(int dataIn) {
    if(full()) return overflow;
    data[count] = dataIn;
    ReheapUp(count);
    count++;
    return success;
}

Error_code MinHeap::deleteHeap(int &dataOut) {
    if(empty()) return underflow;
    dataOut = data[0];
    data[0] = data[count-1];
    count--;
    ReheapDown(0, count-1);
    return success;
}

Error_code MinHeap::buildHeap(int listData[], int size) {
    count = 0;
    while(!full() && count < size) {
        data[count] = listData[count];
        ReheapUp(count);
        count++;
    }
    if(count < size) return overflow;
    else return success;
}

void MinHeap::printHeap() {
    for(int i = 0; i < count; i++)
        cout << data[i] << " ";
    cout << endl;
}
