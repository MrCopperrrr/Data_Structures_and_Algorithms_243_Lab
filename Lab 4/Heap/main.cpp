#include <iostream>
#include "MaxHeap.h"
using namespace std;

int main() {
    //2.4
    Heap heap;
    int numbers[] = {71, 1, 4, 13, 87, 91, 72, 33, 19, 60, 59, 21, 17};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    for(int i = 0; i < n; ++i) {
        cout << "Insert " << numbers[i] << ": ";
        heap.insertHeap(numbers[i]);
        heap.printHeap();
    }
    return 0;
}