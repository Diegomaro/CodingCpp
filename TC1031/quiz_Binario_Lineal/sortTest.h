#pragma once

class SortTest {
public:
	SortTest();
	~SortTest();
	void generateRandomNumbers();
	void printData();
	bool setSize(unsigned int nSize);
	unsigned int getSize() { return size; }

	bool checkSort();
	void bubbleSort();
	void insertionSort();
	void selectionSort();
	bool mergeSort();
	void quickSort();
	int linearSearch(int x);
	int binarySearch(int x);

private:
	bool mergeSortExecute(int left, int right); // Internal function for executing Merge sort
	bool merge(int left, int middle, int right); // Helper function to merge two sorted subarrays
	void releaseData();

	void quickSortExecute(long int start, long int end); // Internal for quicksort
	long int partition(long int start, long int end); // Internal for quicksort

	int  *data;
	unsigned int size;
};