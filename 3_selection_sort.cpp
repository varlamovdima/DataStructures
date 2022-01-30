// This program implements selection sort in C++

#include<stdlib.h>
#include<iostream>
using namespace std;

using namespace std;

// Swaps twp values in memory
// Takes location 'a' and 'b' as arguments
void swap(int *a, int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

void print_array(int *array, int n){
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

// Performs insertion sort on 'array'
// Takes an array, and its length as arguments
void selection_sort(int *array, int n){
	// Keep track the key and value of current minimum
	int min_key;
	// Skip trivial last iteration (only 1 element left to sort)
	for(int i=0;i<n-1;i++){
		// Set current index to be minimum
		min_key=i;
		// Loop over remaining elements
		for(int j=i+1; j<n; j++){
			if(array[j]<array[min_key]){
				min_key = j;
			}
		}
		// Swap for the min element
		cout <<"Swapping index "<<i<<" with index "<<min_key<<endl;
		
		swap(&array[i],&array[min_key]);
	}
	print_array(array,n);
}

int main() {
	// Create an array of size N
	int n = 7;
	int array[n];

	// Fill our array with random number
	for(int i=0;i<n;i++){
		array[i]=rand()%100;
	}

	// Sort the array
	selection_sort(array,n);

	return 0;
}
