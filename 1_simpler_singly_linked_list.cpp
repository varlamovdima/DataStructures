// This program contains simple implementation of singly linked list
// Two methods are implemented: 
// - add node at the end of the list
// - delete node at the end of the list 
#include<iostream>
#include<cstddef>
#include<assert.h>
using namespace std;
// Simple node of the list
// Contains data, and a pointer to the next node
struct Node {
	int data;
	Node *next;
	Node(int d){
		data=d;
		next = NULL;
	}
};

class LinkedList {
	private:
		// Pointer to list head
		Node *head;
	public:
		// Constructor initiializing NULL pointers
		LinkedList(){
			head = NULL;
		}

		// Append new node to the end of the list
		void add_node(int d){
			// Create new node with value 'd'
			Node *new_node = new Node(d);

			// Create temp for walking the list
			Node *temp = head;

			// Handle case of empty list
			// Otherwise perform normal insertion
			if(temp == NULL){
				head = new_node;
			}else{
				// Walk the list until the next node is NULL
				while(temp->next!=NULL){
					temp = temp->next;
				}
				// Assign previous tail's 'next' to be our new node
				temp->next = new_node;
			}
			cout<<"Add node with data: "<<d<<endl;
			print_list();
		}

		// Remove node at the end of the list
		void delete_node(){
			assert(head!=NULL);
			Node *temp = head;
			Node *prev = NULL;

			while(temp->next!=NULL){
				prev = temp;
				temp=temp->next;
			}

			// Handle case where there is only 1 list item
			// Otherwise normal tail delete
			if(prev == NULL){
				head = NULL;
			}else{
				prev->next = temp->next;
			}
			delete temp;
			cout<<"Delete tail node"<<endl;
			print_list();
		}

		// Print out the list
		void print_list(){
			Node *temp = head;
			cout<<"List\t";
			while(temp!=NULL){
				cout<<temp->data<<'\t';
				temp = temp->next;
			}
			cout<<endl;

		}
};

int main(){
	// Create a new linked list
	LinkedList ll;

	// Insert a few nodes, alternation at head and tail
	for(int i=0;i<5;i++){
		// Insert a t tail on even numbers
		ll.add_node(i*i);
	}

	for(int i=0;i<5;i++){
		ll.delete_node();
	}

	return 0;
}

