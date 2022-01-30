// This program implements a simple stack
#include<iostream>
#include <cstdlib>
using namespace std;

class Stack {
	private:
		int *array;
		int top_of_stack;
		int size;
	public:
		// Give it a default size is case the user forgets
		Stack(int s=10){
			// Update the stack size
			size = s;
			// Allocate the stack
			array = new int[size];
			// Set the top of stack to invalid value
			top_of_stack = -1;
		}

		// Add a new item to the stack
		void push(int d){
			// Check if the stack is full
			// If full, exit with failure
			// Otherwise push new item
			if(is_full()){
				cout<<"Error: Stack Overflow"<<endl;
				exit(EXIT_FAILURE);
			}else{
				// Increment top of the stack then store value at new position
				array[++top_of_stack] = d;
			}
			cout<<"Push on to stack"<<endl;
			print_stack();
		}
		// Remove an item from the stack
		void pop(){
			// Check if stack is empty
			// If empty, exit with failure
			// Otherwise pop off top of stack
			if(is_empty()){
				cout<<"Error: Stack Underflow"<<endl;
				exit(EXIT_FAILURE);
			}else{
				// Clear element at top stack then decrement top_of_stack
				array[top_of_stack--]=0;
			}
			cout<<"Pop off top of stack"<<endl;
			print_stack();
		}
		// Look at top of stack
		int peek(){
			// Check if stack is empty
			// If empty, exit with failure
			// Otherwise return top of stack value
			if(is_empty()){
				cout<<"Error: Stack Empty!";
				exit(EXIT_FAILURE);
			}else{
				return array[top_of_stack];
			}
		}
		// Clear the stack
		void clear(){
			cout<<"Dumping stack contents"<<endl;
			while(!is_empty()){
				pop();
			}
		}
		// Print the stack contents
		void print_stack(){
			cout<<"Stack contents" <<endl;
			cout<<"|\t\t|"<<endl;
			cout<<"|---------------|"<<endl;
			for(int i=top_of_stack;i>=0;i--){
				cout<<"|\t" <<array[i]<<"\t|"<<endl;
				cout<<"|---------------|"<<endl;
			}
		}
	private:
		// Check if stask is full (avoid overflow)
		bool is_full(){
			// Last stack element should be at max size -1
			return top_of_stack == size - 1;
		}
		// Check if stack is empty (avoid underflow)
		bool is_empty(){
			// Empty stack is at index - 1
			return top_of_stack==-1;
		}
};

int main(){
	// Create a new stack
	Stack simple_stack;
	// Add some elements to the stack
	for(int i=0;i<5;i++){
		simple_stack.push(i);
	}
	// Remove some elements from the stack
	for(int i=0;i<2;i++){
		simple_stack.pop();
	}
	// Clear the rest of the entries
	simple_stack.clear();

	return 0;
}

