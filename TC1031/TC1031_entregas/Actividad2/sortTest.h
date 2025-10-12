#pragma once

class SortTest {
public:
    SortTest();
    ~SortTest();

    void setSize(int size);
    void generateRandomNumbers();
    void printData();

    bool createArray();
    void releaseArray();
    void bubbleSort();
    void insertionSort();
    void selectionSort();
    void  prepMergeSort();
    int* mergeSort(int* arr, int n);
    int* merge(int* arr1, int* arr2, int n, int n1, int n2);
    void prepQuickSort();
    void quickSort(int leftBorder, int rightBorder);

private:
    int *_data;
    unsigned int _size;
};