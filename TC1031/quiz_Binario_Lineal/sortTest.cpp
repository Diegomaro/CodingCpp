#include <iostream>
#include "sortTest.h"

using namespace std;

SortTest::SortTest() {
	size = 0;
	data = nullptr;
}

SortTest::~SortTest() {
	releaseData();
}


bool SortTest::setSize(unsigned int nSize) {
	releaseData();

	data = new(nothrow) int[nSize];
	if(!data) {
		return false;
	}
	size = nSize;
	return true;
}

void SortTest::releaseData() {
	if(data) {
		delete [] data;
		data = nullptr;
		size = 0;
	}
}

void SortTest::generateRandomNumbers() {
	for(unsigned int i = 0; i < size; i++)
		data[i] = rand() % 1000000;
}

void SortTest::printData() {
	for(unsigned i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}

bool SortTest::checkSort(){
	int temp = data[0];
	for(int i = 1; i < size; i++){
		if(temp > data[i]){
			temp = data[i];
			return false;
		}
	}
	return true;
}

void SortTest::bubbleSort() {
	unsigned int i, j;

	for(i = 0; i < size; i++) {
		for(j = 0; j < size - i - 1; j++) {
			if(data[j] > data[j + 1]) {
				int tmp = 0;

				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}

void SortTest::insertionSort() {
	int actual = 0, j = 0;

	for (unsigned i = 1; i < size; i++) {
		actual = data[i];
		j = i - 1;

		while (j >= 0 && data[j] > actual) {
			data[j + 1] = data[j];
			j = j - 1;
		}
		data[j + 1] = actual;
	}
}

void SortTest::selectionSort() {
	unsigned int i, j, minIndex;

	for (i = 0; i < size - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < size; j++) {
			if (data[j] < data[minIndex])
				minIndex = j;
		}
		
		if (minIndex != i) {
			int tmp = data[i];
			data[i] = data[minIndex];
			data[minIndex] = tmp;
		}
	}
}

bool SortTest::mergeSort() {
	// Get started, full array
	if(!size)
		return false;

	return mergeSortExecute(0, size - 1);
}

bool SortTest::mergeSortExecute(int start, int end) {
	int middle = 0;

	// base case
	if (start >= end)
		return true;

	middle = start + (end - start) / 2;

	if(!mergeSortExecute(start, middle)) // Sort the left half
		return false;
	if(!mergeSortExecute(middle + 1, end)) // Sort the right half
		return false;
	if(!merge(start, middle, end)) // Merge the sorted halves
		return false;
	return true;
}

bool SortTest::merge(int left, int middle, int right) {
	int *leftArr = nullptr, *rightArr = nullptr;
	int sizeLeft = middle - left + 1;
	int sizeRight = right - middle;

	// Create temp arrays
	leftArr = new(nothrow) int[sizeLeft];
	if(!leftArr) {
		return false;
	}
	rightArr = new(nothrow) int[sizeRight];
	if(!rightArr) {
		delete [] leftArr;
		return false;
	}

	// Copy data to temporary arrays leftArr[] and rightArr[]
	for (int i = 0; i < sizeLeft; i++)
		leftArr[i] = data[left + i];
	for (int j = 0; j < sizeRight; j++)
		rightArr[j] = data[middle + 1 + j];

	int i = 0, j = 0, k = left;

	// Merge the two sorted arrays back into data[]
	while (i < sizeLeft && j < sizeRight) {
		if (leftArr[i] <= rightArr[j]) {
			data[k] = leftArr[i];
			i++;
		} else {
			data[k] = rightArr[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of leftArr[], if any
	while (i < sizeLeft) {
		data[k] = leftArr[i];
		i++;
		k++;
	}

	// Copy the remaining elements of rightArr[], if any
	while (j < sizeRight) {
		data[k] = rightArr[j];
		j++;
		k++;
	}

	delete [] leftArr;
	delete [] rightArr;
	leftArr = nullptr;
	rightArr = nullptr;

	return true;
}

void SortTest::quickSort() {
	if(!size)
		return;

	quickSortExecute(0, size - 1);
}

void SortTest::quickSortExecute(long int start, long int end) {
	if(end <= start)
		return; //caso base

	long int pivotIndex = partition(start, end);
	quickSortExecute(start, pivotIndex - 1);
	quickSortExecute(pivotIndex + 1, end);
}

long int SortTest::partition(long int start, long int end) {
	long int pivotIdx = start + rand() % (end - start + 1);
    int temp = data[end];
    data[end] = data[pivotIdx];
    data[pivotIdx] = temp;

	int pivotvalue = data[end];
	long int leftWall = start - 1;

	for(long int i = start; i < end; i++) {
		if(data[i] < pivotvalue) {
			leftWall++;
			temp = data[leftWall];
			data[leftWall] = data[i];
			data[i] = temp;
		}
	}

	leftWall++;
	temp = data[leftWall];
	data[leftWall] = data[end];
	data[end] = temp;

	return leftWall;
}

int SortTest::linearSearch(int x){
	for(int i = 0; i < size; i++){
		if(data[i]==x){
			return i;
		}
	}
	return -1;
}

int SortTest::binarySearch(int x){
	int left = 0;
	int right = size -1;
	while(left < right){
		int middle = left + (right - left) / 2;
		if(data[middle] == x){
			return middle;
		} else if(data[middle] > x){
			right = middle-1;
		} else{
			left = middle+1;
		}
	}
	return -1;
}