//Doubly Linked List

//including libraries
#include<iostream>
using namespace std;

//making class Node
class Node{
	//data
	public:
	int data;
	//pointers to the next and previous nodes
	Node *next;
	Node *prev;
	//Constuctor to initialize NULL value to pointers
	public:
	Node(){
		next=NULL;
		prev=NULL;
	}
};

//Creating class linked list to perform all functions
class DlinkedList{
	//making head and tail pointer of Node type
	public:
	Node *head;
	Node *tail;
	//constructor to initialize head and tail pointers
	public:
	DlinkedList(){
		head=NULL;
		tail=NULL;
	}
	
	//function insert to add new elements to the end of the linked list
	void insert(int value){
		//creating a new node 
		Node *temp=new Node;
		//filling data in the new node
		temp->data=value;
		//for the first node only
		if(head==NULL){
			head=temp;
		}
		//for all other nodes
		else{
			//creating new pointer to reach upto the required node
			Node *current=head;
			while(current->next !=NULL){
				current=current->next;
			}
			//creating forward and backward links between the nodes
			current->next=temp;
			temp->prev=current;
		}
	}

	//writing insert at function to insert node at specific position
	void insertAt(int pos, int value){
		//creating pointer to reach upto the required node
		Node *current=head;
		int i=1;
		while(i<pos-1){
			i++;
			current=current->next;
		}
		//checking if the value of out of bounds
		if(current==NULL || current->next==NULL)
			cout<<"Linked List does not have that many elements."<<endl;
		//creating new node to insert
		Node *temp=new Node;
		temp->data=value; //assigning data to new node
		temp->next=current->next; //linking temp to the forward node
		temp->prev=current; //linking temp to the backward node
		current->next=temp; //linking backward nodeto temp
		temp->next->prev=temp; //linking forward node to temp
	}

	//writing function to delete element from the end of the linked list
	void del(){
		//creating pointer of node type to reach upto 2nd lst element
		Node *current=head;
		while(current->next->next !=NULL){
			current=current->next;
		}
		current->next->prev=NULL; //deleting link of last node from 2nd last node
		//creating pointer of node type to store address of last node
		Node *temp=current->next;
		current->next=NULL; //deleting link of 2nd last node from last node
		//deleting last node
		delete temp;
	}
	
	//writing function to delete node from  particular position
	void delAt(int pos){
		//creating pointer to reach upto the required node
		Node *current=head;
		int i=1;
		while(i<pos-1){
			i++;
			current=current->next;
		}
		//creating pointer of node type to store the data of node to be deleted
		Node *temp=current->next;
		//linking the nodes just before and after the node to be deleted
		current->next=temp->next;
		temp->next->prev=current;
		//removing the links of the node to be deleted
		temp->next=NULL;
		temp->prev=NULL;
		//deleting the node
		delete temp;
	}

	//writing function to count the number of items in linked list
	int countItems(){
		//counter variable
		int c=0;
		//pointer of Node type to move through the linked list
		Node *current=head;
		//loop to move through the linked list
		while(current!=NULL){
			c++;
			current=current->next;
		}
		//returning the value
		return c;
	}

	//Display
	void display(){
		Node *current=head;
		while(current!=NULL){
			cout<<current->data<<"->";
			current=current->next;
		}
		cout<<"NULL";
		cout<<endl;
		cout<<endl;
	}

};

//writing main function to call all the functions
int main(){
	//creating object
	DlinkedList l1;
	//Inserting elements in the linked list and displaying
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	cout<<endl;
	cout<<"Original Linked List."<<endl;
	l1.display();
	//Counting the number of elements in the original linked List and displaying
	int cn=l1.countItems();
	cout<<"Number of elements in original Linked List = "<<cn<<endl;
	cout<<endl;
	//Deleting last element and displaying
	l1.del();
	cout<<"Linked List after deleting last element."<<endl;
	l1.display();
	//Inserting an element at the 3rd position and displaying
	l1.insertAt(3, 12);
	cout<<"Linked List after inserting 12 at the 3rd position."<<endl;
	l1.display();
	//Deleting node from 2nd position and displaying
	l1.delAt(2);
	cout<<"Linked list after deleting element from 2nd position."<<endl;
	l1.display();
	return 0;
}

		
			
