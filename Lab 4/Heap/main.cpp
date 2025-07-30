#include <iostream>
#include "MaxHeap.h"
#include <vector>
using namespace std;

int main() {
    //2.4
    Heap heap24;
    int numbers[] = {71, 1, 4, 13, 87, 91, 72, 33, 19, 60, 59, 21, 17};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    for(int i = 0; i < n; ++i) {
        cout << "Insert " << numbers[i] << ": ";
        heap24.insertHeap(numbers[i]);
        heap24.printHeap();
    }


    Heap heap25;
    vector<int> inputVec;
    int x;
    cout << "Enter number: ";
    while (cin >> x && x != 0) {
        inputVec.push_back(x);
    }
    int arr[30];
    int size = inputVec.size();
    for (int i = 0; i < size; ++i) arr[i] = inputVec[i];
    heap25.buildHeap(arr, size);
    cout << "Heap: ";
    heap25.printHeap();
    return 0;
}
