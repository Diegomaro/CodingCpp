#pragma once

//#define MAX_DATA 20

class SortTest {
public:
    SortTest();
    ~SortTest();
    void setSize(unsigned int size);
    void generateRandomNumbers();
    void printData();
    bool createArray();
    void releaseArray();
    void bubbleSort();
    void insertionSort();
    void selectionSort();
    void prepMergeSort();
    void prepQuickSort();
private:
    int *data;
    unsigned int size;
    int* mergeSort(int * array, int arrSize);
    int* merge(int* array1, int* array2, int arrSize);
    void quickSort(int start, int end);
    int partition(int start, int end);
};