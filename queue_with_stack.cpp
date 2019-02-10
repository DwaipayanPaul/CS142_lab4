// queue with stack

#include<iostream>

using namespace std;

class node{
	public:
		
		int data;
		node* next;
		node(){
			next=NULL;
		}
};

class list{
	public:
		node* head;
		//default constructor
		list(){
			head=NULL;
		}
	
		void insert(int input){
			node* curr=head;
			node* temp=new node; 
			//input 
			temp->data=input;
			if(head==NULL){
				head=temp;
			}
			else{
				while(curr->next!=NULL){
				curr=curr->next;
			}
			temp->next=curr->next;
			curr->next=temp;
			}
		}
		
		//insret at
		void insAt(int input,int pos){
			node* temp=new node;
			temp->data=input;
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
			if(pos-1>i||pos<1){
				cout<<"check input"<<endl;
			}
			
			else if(pos==1){
				temp->next=head;
				head=temp;
			}
			
			else{
				//reach the position
				node* current=head;
				int i=1;
				while(i<pos-1){
					current=current->next;
					i++;
				}
				temp->next=current->next;
				current->next=temp;
			}
		}
		
		void del(){
			node* curr=head;
			node* temp=new node;
			//no element
			if(head==NULL){
				cout<<"Nothing to delete\n";
			}
			//only one element
			else if(head->next==NULL){
				temp=head;
				head=NULL;
				delete temp;
			}
			//more than one element
			else{
				while(curr->next->next!=NULL){
					curr=curr->next;
				}
				temp=curr->next;
				curr->next=NULL;
				delete temp;
			}
		}
		
		//deleteAt
		void delAt(int pos){
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
			}//now i stores the number of notes
			
			if (pos>i||pos<1){
				cout<<"position out of scope\n";
			}
			else if(pos==1){
				node* temp=new node;
				temp=head;
				head=head->next;
				delete temp;
			}
			
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
		
		void count(){
			node* current=head;
			if(head==NULL){
				cout<<"There are 0 elements\n";
			}
			else{
				int i=1;
				while(current->next!=NULL){
					i++;
					current=current->next;
				}
				cout<<"There are "<<i<<" elements\n";
			}
		}
		
		
		void display(){
			node* curr=head;
			if (head==NULL){
				cout<<"NULL"<<endl;
			}
			else{
				while(curr!=NULL){
					cout<<curr->data<<"->";
					curr=curr->next;
				}
				cout<<"NULL\n";
			}
		}
};


class st{
	public:
		node* top;
		list l1;
	          	//default constructor
		
		st(){
			top=l1.head;
		}
	        	//push
		
		void push(int input){
			l1.insAt(input,1);
			top=l1.head;
		}
	         	//pop
		void pop(){
			l1.delAt(1);
			top=l1.head;
		}
	          	//top
		void disp_t(){
			if (top==NULL){
				cout<<"There is no value in the stack to show.\n";
			}
			else{
				cout<<"The top element is "<<top->data<<endl;
			}
		}
		//bottom
		void disp_b(){
			if(top==NULL){
				cout<<"There is no value in the stack to show.\n";
			}
			else{
				node* current=l1.head;
				while (current->next!=NULL){
					current=current->next;
				}
				cout<<"The bottom element is "<<current->data<<endl;
			}
		}
		
		//is empty
		bool isEmpty(){
			if (top=NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
};

class qusta{
	public:
		st s1;
		int size;
		//default constructor
		qwst(){
			size=0;
		}
		//enq
		void enq(int input){
			
			if (!s1.isEmpty()){
				s1.push(input);
				size++;
				return;
			}
			int no=s1.top->data;   //stores the value during the loops of recursion
			s1.pop();
			
			enq(input);//recursion step
			
			s1.push(no);
		}
		//dq
		void dq(){
			s1.pop();
			size--;
		}
		//front
		void disp_f(){
			s1.disp_t();
		}
		//end
		void disp_e(){
			s1.disp_b();
		}
		
		//sizeOf
		void sizeOf(){
			cout<<"the size of the queue is "<<size<<endl;
		}
};

int main(){
	qusta q1;
	q1.dq();
	for(int i=1;i<5;i++){
		q1.enq(i);
	}	
	q1.dq();
	q1.disp_e();
	q1.disp_f();
	return 0;
}
