// This program implements quick sort
#include<iostream>
#include<stdlib.h>
using namespace std;

// Swap the contents of two pointers
void swap(int *a, int *b){
	int tmp = *a;
	*a=*b;
	*b=temp;
}

// Create a seub-array for elements"<=" and ">" the pivot
// Takes an array, left index, and pivot index as arguments
int partition(int *array, int left, int pivot){
	// Start with a sub-array that is empty
	int low = left - 1;
	
	// Compare all numbers before the pivot
	int high = pivot - 1;

	// Go over all elements in sub-array;
	for(int j=left; j<=high; j++){
		// Does this element go in the "<=" sub-array?
		if(array[j]<=array[pivot]){
			// Move over marker of sub-array
			low++;
			// Swap the element into position
			swap(&array[low], &array[j]);
		}
	}


