// This file contains the implementation of a singly linked list
#include<iostream>
#include<cstddef>
#include<assert.h>
using namespace std;
// Simple node of the list
// Contains data, and a pointer to the next node
struct Node {
	int data;
	Node *next;
	// Constructor
	Node(int d){
		data = d;
		next = NULL;
	}
};

class LinkedList {
	private:
		// Pointer to list head
		Node *head;
	public:
		// Constructor initializing NULL pointer
		LinkedList(){
			head=NULL;
		}

		// Add node with data 'd' at head position
		void insert_head(int d){
			// Create a new node with data value 'd'
			Node *new_head = new Node(d);
			// Insert at the front of the list
			new_head->next = head;
			head = new_head;

			cout<<"Head insert with data: "<<d<<endl;
			print_list();
		}

		// Add node with data 'd' at position in the list 'p'
		void insert_position(int d, int p){
			// Create a new node with data value 'd'
			Node *new_node = new Node(d);

			if(head==NULL){
				if(p==0){
					head=new_node;
				}else{
					assert(head==NULL && p==0);
				}
			}else{
				// Walk the list to get to the entry point for new node
				Node *temp =head;
				Node *prev = NULL;
				for(int i=0;i<p;i++){
					// Check if insertion point is past potential new tail
					assert(temp!=NULL);
					// Updata previous node and current node
					prev = temp;
					temp = temp->next;
				}
				// Check if this is actually head insertion
				// Otherwise perform normal insertion
				if(prev == NULL){
					head = new_node;
					head->next = temp;
				}else{
					new_node->next = prev->next;
					prev->next = new_node;
				}
			}
			cout<<"Position "<<p<<" insert with data: "<<d<<endl;
			print_list();
		}

		// Add node with data 'd' at tail positon
		void insert_tail(int d){
			// Create new node with value 'd'
			Node *new_tail = new Node(d);

			// Handle case of empty list
			// Otherwise perform normal insertion
			if(head==NULL){
				head=new_tail;
			}else{
				Node *temp =head;
				// Create temp for walking the list
				while(temp->next!=NULL){
					temp = temp->next;
				}
				// Assign previuos tail's 'next' to be our new node
				temp->next = new_tail;
			}
			cout<<"Tail insert with data: "<<d<<endl;
			print_list();
		}

		// Delete node at head position
		void delete_head(){
			// Check if list is empty
			assert(head!=NULL);
			// Set head->next as new head and free old one
			Node *temp = head;
			head = temp->next;
			delete temp;
			cout<<"Head delete"<<endl;
			print_list();
		}

		// Delete node at position in the list 'p'
		void delete_position(int p){
			// Check if list is empty
			assert(head!=NULL);
			// Walk the list to the position for deletion
			Node *temp = head;
			Node *prev = NULL;
			for(int i=0;i<p;i++){
				// Check if deletion point is past the end of the list
				assert(temp!=NULL);
				prev = temp;
				temp = temp->next;
			}
			// Handle head deletion
			// Otherwisse normal deletion
			if(prev == NULL){
				head = temp->next;
			}else{
				prev->next = temp->next;
			}
			delete temp;
			cout<<"Position "<<p<< "delete"<<endl;
			print_list();
		}

		// Delete node at tail position
		void delete_tail(){
			// Check if list is empty
			assert(head!=NULL);

			// Walk the list and save the previuos and current Node
			Node *temp = head;
			Node *prev = NULL;
			while(temp->next !=NULL){
				prev =temp;
				temp = temp->next;
			}

			// Handle case where there is only 1 list item
			// Otherwise normal tail delete
			if(prev == NULL){
				head=NULL;
			}else{
				prev->next = temp->next;
			}
			delete temp;
			cout<<"Tail delete"<<endl;
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
	LinkedList ll;
	ll.insert_head(3);
	ll.insert_tail(5);
	ll.insert_position(6,1);

	return 0;
}
