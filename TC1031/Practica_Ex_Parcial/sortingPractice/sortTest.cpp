#include <ctime>
#include <iostream>
#include "sortTest.h"

using namespace std;

SortTest::SortTest() {
    size = 20;
    data = nullptr;
    srand(time(0));
}

SortTest::~SortTest() {
    releaseArray();
}

bool SortTest::createArray() {
    if(data)
        return false;

    data = new(nothrow) int[size];
    if(!data)
        return false;

    for(unsigned int i = 0; i < size; i++)
        data[i] = 0;
    generateRandomNumbers();
    return true;
}

void SortTest::releaseArray() {
    if(data) {
        delete [] data;
        data = nullptr;
        size = 0;
    }
}

void SortTest::setSize(unsigned int size){
    releaseArray();
    this->size = size;
    createArray();
}

void SortTest::generateRandomNumbers() {
    unsigned int i = 0;

    if(!data)
        return;

    for(i = 0; i < size; i++)
        data[i] = rand() % 100;
}

void SortTest::printData() {
    unsigned int i = 0;

    for(i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

void SortTest::bubbleSort(){
    for(int i = 0; i < size -1; i++){
        for(int j = 0; j < size - i -1; j++){
            if(data[j] > data[j+1]){
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

void SortTest::selectionSort(){
    for(int i = 0; i < size-1; i++){
        int min = i;
        for(int j = i+1; j < size; j++){
            if(data[j] < data[min]){
                min = j;
            }
        }
        int temp = data[min];
        data[min] = data[i];
        data[i] = temp;
    }
}

void SortTest::insertionSort(){
    for(int i = 1; i < size; i++){
        int j = i;
        while(j > 0 && data[j-1] < data[j]){
            int temp = data[j];
            data[j] = data[j-1];
            data[j-1] = temp;
            j--;
        }
    }
}
void SortTest::prepMergeSort(){
    if (size <= 1) return;
    int* save = mergeSort(data, size);
    data = save;
}

int* SortTest::mergeSort(int * array, int arrSize){
    if(arrSize <= 1){
        return array;
    }
    int subSize = arrSize/2;
    int* array1 = new(nothrow) int[arrSize-subSize];
    int* array2 = new(nothrow) int[subSize];
    for(int i = 0; i < arrSize-subSize; i++){
        array1[i] = array[i];
    }
    for(int i = 0; i < subSize; i++){
        array2[i] = array[i+arrSize - subSize];
    }

    delete [] array;

    int *temp1 = mergeSort(array1, arrSize-subSize);
    int* temp2 = mergeSort(array2, subSize);
    return merge(temp1, temp2, arrSize);
}

int* SortTest::merge(int* array1, int* array2, int arrSize){
    int* array3 = new(nothrow) int [arrSize];
    int counter1 = 0;
    int size1 = arrSize - arrSize/2;
    int counter2 = 0;
    int size2 = arrSize/2;
    int counter3 = 0;
    while(counter3 < arrSize){
        if(array1[counter1] <= array2[counter2]){
            array3[counter3] = array1[counter1];
            counter3++;
            counter1++;
        } else if(array1[counter1] > array2[counter2]){
            array3[counter3] = array2[counter2];
            counter3++;
            counter2++;
        }
        if(counter1 == size1 && arrSize != counter3){
            while(counter3 < arrSize){
                array3[counter3] = array2[counter2];
                counter3++;
                counter2++;
            }
        } else if(counter2 == size2 && arrSize != counter3){
            while(counter3 < arrSize){
                array3[counter3] = array1[counter1];
                counter3++;
                counter1++;
            }
        }
    }
    delete [] array1;
    delete [] array2;
    return array3;
}

void SortTest::prepQuickSort(){
    quickSort(0, size - 1);
}

void SortTest::quickSort(int start, int end){
    if(start >= end){
        return;
    }
    int pivotIndex = partition(start, end);
    quickSort(start, pivotIndex - 1);
    quickSort(pivotIndex + 1, end);
}

int SortTest::partition(int start, int end){
    int pivotIndex = end;
    bool ordered = false;
    int i = start;
    int j = end - 1;
    while(!ordered){
        while(i <= j && data[i] <= data[pivotIndex]){
            i++;
        }
        while(j >= i && data[j] >= data[pivotIndex]){
            j--;
        }
        if(j > i){
            int temp = data[j];
            data[j] = data[i];
            data[i] = temp;
            i++;
            j--;
        } else if(i >= j){
            ordered = true;
        }
    }
    ordered = false;
    
    int temp = data[i];
    data[i] = data[pivotIndex];
    data[pivotIndex] = temp;
    return i;
}