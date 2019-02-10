//  stack with queue

#include<iostream>

using namespace std;

class node{
	public:
		
	//Data
	int data;
	//Pointer to the next Node
	node * next;
	//constructor the makes the ptr to null
	node(){
		next=NULL;
	}
};
class linkedlist{
	//head +circles with each other
	public:
	//Head-> Circle(node) type ptr
	node* head;
	node* tail;
	//construct
	linkedlist(){
		head=NULL;
		tail=NULL;
	}
	//Circles inside linked with each other
	//rules hoe circles will be linked
	//insert
	void insert(int value){
		//if first node is added
		node * temp=new node;//new helps to creates an object of node type in heap and returns its adress which  is stored in pointer
		temp->data=value;//using here
		//1st node only
		if (head==NULL){
			head=temp;
		}
		//any other temp only
		else{
			tail->next=temp;
		}
		tail = temp;
		
		
	}
	void insertAT(int pos,int value){
		//reach the place before pos
		node* current=head;
	if(pos!=1){
		int i=1;
		while(i<pos-1){
			i++;
			current=current->next;
		}
		//create a node
		node * temp= new node;
		temp->data=value;
		//moving ptrs
		temp->next=current->next;
		current->next=temp;
		//update the code for 1ast position
	}
	else{
		//create a node
		node * temp=new node;
		temp->data=value;//assign value
		//link it to the value of head
		temp->next=current;
		//make temp head;
		head=temp;	
	}
		
	}
	//deletion of last element
	void delet(){
		//store the tail in temp
		node * temp = tail;
		// before tail has to point to null
		node * current=head;
		while(current->next !=tail){
		current =current->next;		
		}
		current->next=NULL;
		//update tail
		tail=current;
		delete temp;
	}
	//delete at a given position
		void deletAt(int pos){
			//take one node at the desired position-1
			node *current=head;
				int i=1;
			while(i<pos-1){
				i++;
				current=current->next;
			}
			// crate pointer for the file to be deleted
			node * temp=current->next;
			//assign link of the previous element to the next of next element
			current->next=temp->next;
			//deletion
			delete temp;
			
			
		
	}
	//display
	void display(){
		node * current=head;
		while(current !=NULL){
			cout<< current ->data<<"->";	
			current =current->next;	
		}
		cout<<"Null"<<endl;
		
		
		
	}
	void countItems(){
		node * current=head;
		int i=0;
		while(current !=NULL){	
			current =current->next;	
			i++;
		}
		cout<<"the number of elemwnts in the linked list is-"<<i<<endl;
	}
};
class Queue{
	public:
		//variables
		node * end;
		node * front;
		linkedlist l1;
		//contructor
		Queue(){
			front=l1.tail;
			end=l1.head;
		}
		//Enqueue function
		void Enqueue(int value){
			l1.insertAT(1,value);
			end=l1.head;
			front=l1.tail;
		}
		//Dequeue function
		void Dequeue(){
			l1.delet();
			front=l1.tail;
		}
		//front displaying function
		void frontdisplay(){
			cout<<"the front is->"<<front->data<<endl;
		}
		int frontdata(){
			return front->data;
		}
		//enddisplaying function
		void enddisplay(){
			cout<<"the end is->"<<end->data<<endl;
		}
		//isempty function
		bool isEmpty(){
			if(front==NULL) return true;
			else return false;
	}
		int size(){
			
		return l1.countItems();
		
	}
};
class mystack {
	private:
		Queue q1;
		int stsize;
	public:
		mystack(){
			stsize=0;
		}
		void push(int value){
			q1.Enqueue(value);
			stsize++;
			for(int h=1;h<=(q1.size())-1;h++){
				int data=q1.front->data;
				q1.Dequeue();
				q1.Enqueue(data);
			}
		}
		void pop(){
			q1.Dequeue();
			stsize--;
		}
		void top(){
			cout<<"the top is->"<<q1.frontdata()<<endl;
		}
		bool isempty(){
			return q1.isEmpty();
		}
		int size(){
			return stsize;
		}
};
int main(){
	mystack s1;
	for(int i=0;i<5;i++){
		s1.push(i);
	}
	s1.pop();
	//s1.pop();
	int x=s1.size();
	cout<<"the size is ->"<<x<<endl;
	s1.top();
	for (int h=0;h<5;h++)
	{
		s1.pop();	}
	
	
	return 0;
}
