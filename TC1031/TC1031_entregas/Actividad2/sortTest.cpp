#include <ctime>
#include <iostream>
#include "sortTest.h"

using namespace std;

SortTest::SortTest() {
    _size = 20;
    _data = nullptr;
    srand(time(0));
}

SortTest::~SortTest() {
    releaseArray();
}

void SortTest::setSize(int size){
    _size = size;
}

bool SortTest::createArray() {
    if(_data)
        return false;

    _data = new(nothrow) int[_size];
    if(!_data)
        return false;

    for(unsigned int i = 0; i < _size; i++)
        _data[i] = 0;
    return true;
}

void SortTest::releaseArray() {
    if(_data) {
        delete [] _data;
        _data = nullptr;
    }
}

void SortTest::generateRandomNumbers() {
    unsigned int i = 0;

    if(!_data)
        return;

    for(i = 0; i < _size; i++)
        _data[i] = rand() % 1000000;
}

void SortTest::printData() {
    unsigned int i = 0;

    for(i = 0; i < _size; i++)
        cout << _data[i] << " ";
    cout << endl;
}

// Complejidad BigO, O(n²), estaba experimentando hacerlo con puros apuntadores, por eso quedo raro
void SortTest::bubbleSort(){
    if(_size==0){
        return;
    }
    int* ptr = nullptr;
    ptr = _data;
    int* boundPtr = _data + _size-1;
    int temp = 0;
    while (_data < boundPtr){
        while(ptr < boundPtr){
            if(*ptr > *(ptr+1)){
                temp = *ptr;
                *ptr = *(ptr+1);
                *(ptr+1) = temp;
            }
            ptr++;
        }
        ptr = _data;
        boundPtr--;
    }
}

// Complejidad BigO, O(n²)
void SortTest::insertionSort(){
    for(int i = 1; i < _size; i++){
        for(int j = i; j > 0; j--){
            if(_data[j] < _data[j-1]){
                int temp = _data[j];
                _data[j] = _data[j-1];
                _data[j-1] = temp;
            } else {
                j = 0;
            }
        }
    }
}

// Complejidad BigO, O(n²)
void SortTest::selectionSort(){
    int min = 0;
    for(int i = 0; i < _size; i++){
        min = i;
        for(int j = i+1; j < _size; j++){
            if(_data[j] < _data[min]) {
                min = j;
            }
        }
        int temp = _data[i];
        _data[i] = _data[min];
        _data[min] = temp;
    }
}

// Complejidad BigO, O(nlogn)
void SortTest::prepMergeSort(){
    _data = mergeSort(_data, _size);
}
int* SortTest::mergeSort(int* arr, int n){
    int n1 = 0;
    int n2 = 0;
    if(n<=1){
        return arr;
    }
    n1 = n/2;
    n2 = n-n1;
    
    int* arr1 = new(nothrow) int[n1];
    int* arr2 = new(nothrow) int[n2];
    if(!arr1 || !arr2){
        cout << "Not enough memory!" << endl;
        delete[] arr1;
        delete[] arr2;
        return arr;
    }
    for(int i = 0; i < n1; i ++){
        arr1[i] = arr[i];
    }
    for(int i = n1; i < n; i ++){
        arr2[i-n1] = arr[i];
    }
    arr1 = mergeSort(arr1, n1);
    arr2 = mergeSort(arr2, n2);
    int* merged = merge(arr1, arr2, n, n1, n2);
    if (!merged) {
        cout << "Not enough memory!" << endl;
        return arr;
    }
    return merged;
}

int* SortTest::merge(int* arr1, int* arr2, int n, int n1, int n2){
    int* arr3 = new(nothrow) int[n];
    if(!arr3){
        cout << "Not enough memory!" << endl;
        delete [] arr1;
        delete [] arr2;
        return nullptr;
    }

    int counter = 0;
    int counter1 = 0;
    int counter2 = 0;

    while(counter < n){
        if(arr1[counter1] > arr2[counter2]){
            arr3[counter] = arr2[counter2];
            counter++;
            counter2++;
            if((counter2 == n2) && (counter != n)) {
                while(counter < n){
                    arr3[counter] = arr1[counter1];
                    counter++;
                    counter1++;
                }
            }
        } else{
            arr3[counter] = arr1[counter1];
            counter++;
            counter1++;
            if((counter1 == n1) && (counter != n)) {
                while(counter < n){
                    arr3[counter] = arr2[counter2];
                    counter++;
                    counter2++;
                }
            }
        }
    }
    delete [] arr1;
    delete [] arr2;
    return arr3;
}

// Complejidad BigO, O(n²), promedio nlogn
void SortTest::prepQuickSort(){
    if(_size > 1){
        quickSort(0, _size-1);
    }
}
void SortTest::quickSort(int leftBorder, int rightBorder){
    if(leftBorder >= rightBorder){
        return;    
    }
    int pivot = rightBorder;
    bool partitionDone = false;

    while(!partitionDone){
        int left = pivot;
        int right = leftBorder-1;
        bool foundLeft = false;
        bool foundRight = false;
        int counter = leftBorder;
        while(!foundLeft && counter < pivot){
            if(_data[counter]>_data[pivot]){
                left = counter;
                foundLeft = true;
            }
            counter++;
        }
    
        counter = pivot-1;
        while(!foundRight && counter >= leftBorder){
            if(_data[counter] < _data[pivot]){
                right = counter;
                foundRight = true;
            }
            counter--;
        }
    
        if(foundRight && foundLeft && right>left){
            int temp = _data[left];
            _data[left] = _data[right];
            _data[right] = temp;
        } else {
            int temp = _data[pivot];
            _data[pivot] = _data[left];
            _data[left] = temp;
            pivot = left;
            partitionDone = true;
        }
    }
    quickSort(leftBorder, pivot-1);
    quickSort(pivot+1, rightBorder);
}