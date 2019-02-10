//queue with linked list

#include<iostream>

using namespace std;

class node{
	public:
		
	       //Data
	int data;
	     //Pointer to the next Node
	node * next;
	                     // constructor the makes the ptr to null
	node(){
		next=NULL;
	}
};
class linkedlist{
	
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
	
	   //insert
	void insert(int value){
		//if first node is added
		node * temp=new node;
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
		if(head->next==NULL)
			tail=head;
	}
		
	}
	//deletion of last element
	void delet(){
		//store the tail in temp
		node * temp = tail;
		// before tail has to point to null
		node * current=head;
		if(head==NULL){
			cout<<"Queue will get empty!! Program:Am i a joke to u?"<<endl;
		}
		else if(head->next==NULL){
				temp=head;
				head=NULL;
				delete temp;
			}
		
		else{
		
		while(current->next !=tail){
		current =current->next;		
		}
		current->next=NULL;
		//update tail
		tail=current;
		delete temp;
	}
}
	//delete at a given position
		void deletAt(int pos){
			node* current=head;
			int i;
			if (head==NULL){
				i=0;
			}
			else{
				i=1;
				while(current->next!=NULL){
					current=current->next;
					i++;
				}
			}
			
			//checking the position whether
			
			if (pos>i||pos<1){
				cout<<"please check your input"<<endl;
			}
			//for position 1
			else if(pos==1){
				node* temp=new node;
				temp=head;
				head=head->next;
				delete temp;
			}
			//for other positions
			else{
				node* current=head;
				int j=1;
				while(j<pos-1){
					j++;
					current=current->next;
				}//position reached
				node* temp=current->next;
				current->next=temp->next;
				delete temp;
			}
			
		
	}
	//display
	void display(){
		node * current=head;
		if(head==NULL){
			cout<<"Null"<<endl;
		}
		else{
		
		while(current !=NULL){
			cout<< current ->data<<"->";	
			current =current->next;	
		}
	
		cout<<"Null"<<endl;
	}
		
		
	
	}
	void countItems(){
		node * current=head;
		int j=0;
		while(current !=NULL){	
			current =current->next;	
			j++;
		}
		cout<<"The number of elements in the linked list is-"<<j<<endl;
	}
};


class queue{
	public:
	//front and end of a queue
	node* front;
	node* end;
	
	linkedlist l1;
	queue(){
		front=l1.tail;
		end=l1.head;
	}
	
	//Add at the front
	void enqueue(int value){
		
		l1.insertAT(1,value);
		front=l1.tail;
		end=l1.head;
		
	
		
	}
	
	//Remove last person
	void dequeue(){
		l1.delet();
		front=l1.tail;
		end=l1.head;
		
	}
	
	bool isEmpty(){
			if(front==NULL && front==end) 
			return true;
			else
			return false;}
			
	void size(){
		l1.countItems();
		front=l1.tail;
		end=l1.head;
		
	}
	void display(){
			if(front==NULL){
			cout<<"Queue is empty"<<endl;
			}
			else
			 l1.display();
			
		}
		
		};
	
	int main(){
	
	queue q1;
	for(int i=0;i<4;i++){
		q1.enqueue(i);
		
	}
		
	q1.display();
	q1.dequeue();	
	q1.display();
	q1.dequeue();	
	q1.display();
	q1.dequeue();	
	q1.display();
	q1.dequeue();	
	q1.display();
	q1.dequeue();	
	q1.display();
     	
	
	
	}
	
	

