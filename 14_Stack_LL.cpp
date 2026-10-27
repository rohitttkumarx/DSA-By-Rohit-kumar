
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* top = NULL;

void push(int value){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = top;
	top = newNode;
	cout<<"Element pushed successfully\n";
}

void pop(){
	if(top == NULL){
		cout<<"Stack Underflow!\n";
		return;
	}
	Node* temp = top;
	cout<<"Element "<<top->data<<" popped successfully\n";
	top = top->next;
	delete temp;
}

void display(){
	if(top == NULL){
		cout<<"Stack is empty\n";
		return;
	}
	Node* temp = top;
	cout<<"Stack elements are:\n";
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

int main(){
	int choice, value;
	cout<<"Name:Rohit Kumar"<<endl;
	cout<<"URN:2514169"<<endl;
	cout<<"CRN:2515244"<<endl;
	do{
		cout<<"\n--- Stack Menu ---\n";
		cout<<"1. Push an Element\n";
		cout<<"2. Pop an Element\n";
		cout<<"3. Display Stack\n";
		cout<<"4. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"Enter element: ";
				cin>>value;
				push(value);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				cout<<"Exiting program\n";
				break;
			default:
				cout<<"Invalid choice!\n";
		}
	}while(choice != 4);

	return 0;
}
