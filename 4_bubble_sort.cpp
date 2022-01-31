// This program implements bubble sort
#include<stdlib.h>
#include<iostream>
using namespace std;
// Swaps to elemetns in memory
// Takes memory locations a adn b as arguments
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Performs bubble sort
// Takes an array and its length as arguments
void bubble_sort(int *array, int n){
	// Skips trivial last iteration
	for(int i=0;i<n-1;i++){
		// Propagate largest remaining element to the top
		// Remove 'i' sorted elements each iteration
		for(int j=0;j<n-1-i;j++){
			if(array[j]>array[j+1]){
				cout<<"Swapping index "<<j<<" and " << j + 1 <<endl;
				swap(&array[j],&array[j+1]);
			}
		}
	}
}

int main(){
	// Allocate an array of size n
	int n = 7;
	int array[n];
	// Initialize array with random numbers
	for(int i=0; i<n; i++){
		array[i] = rand()%100;
	}
	// Sort the array
	bubble_sort(array,n);
	
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	return 0;
}
