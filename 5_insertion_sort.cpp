// This program implements insertion sort
#include<stdlib.h>
#include<iostream>
using namespace std;

// Performs insertion sort
// Takes an array and its length as arguments
void insertion_sort(int *array, int n){
	// Place each element at the end of the sorted sub-list
	// into the list (first element is implicitly sorted)
	int temp;
	for(int i=1;i<n;i++){
		cout<<"Inserting index "<< i<< endl;

		// Save the ith element because shifting overwrites it
		temp = array[i];
		// Ammount to shift elements by
		int j=i-1;
		// Shift over elements until be find insertion point
		while((j>=0)&&(array[j]>temp)){
			array[j+1]=array[j];
			j=j-1;
		}
		// ... an insert the value at that spot
		cout <<"Inserting at position "<<j+1<<endl<<endl;
		array[j+1]=temp;
	}
}

int main(){
	// Create an array of size n
	int n=7;
	int array[n];
	// Initialize the array with random values
	for(int i=0; i<n; i++){
		array[i] = rand()%100;
	}
	// Sort the array
	insertion_sort(array,n);

	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}

	return 0;
}
