#include <iostream>
#include <vector>
#include <algorithm>
#include "SortAlgorithms.h"

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> original = {64, 34, 25, 12, 22, 11, 90};

    std::vector<int> arr;

    std::cout << "Original array: ";
    printArray(original);

    arr = original;
    bubbleSort(arr);
    std::cout << "Bubble Sort:    ";
    printArray(arr);

    arr = original;
    selectionSort(arr);
    std::cout << "Selection Sort: ";
    printArray(arr);

    arr = original;
    insertionSort(arr);
    std::cout << "Insertion Sort: ";
    printArray(arr);

    arr = original;
    heapSort(arr);
    std::cout << "Heap Sort:      ";
    printArray(arr);

    arr = original;
    mergeSort(arr);
    std::cout << "Merge Sort:     ";
    printArray(arr);

    arr = original;
    quickSort(arr);
    std::cout << "Quick Sort:     ";
    printArray(arr);

    return 0;
}
