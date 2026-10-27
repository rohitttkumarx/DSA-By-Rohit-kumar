#include<iostream>
using namespace std;
#define max 100
int stack[max];
int top=-1;
void push(int value){
	if(top==max-1){
		cout<<"Stack overflow!";
	}
	else{
		stack[++top]=value;
		cout<<"Element pushed successfully";
	}
}
void pop(){
	if(top==-1){
		cout<<"Stack undeflow!";
	
	}
	else{
		cout<<"Element "<<stack[top]<<"poped successfully";
		top--;
	}
}
void dispay(){
	if(top==-1){
		cout<<"Stack is empty!";
	}
	else{
		cout<<"Elements"<<endl;
		for(int i=top;i>=0;i--){
			cout<<stack[i]<<endl;
		}
	}
}
int main(){
	int choice,value;
	cout<<"Name:Rohit Kumar"<<endl;
	cout<<"URN:2514169"<<endl;
	cout<<"CRN:2515244"<<endl;
	while(true){
		cout<<"1. Push an element to stack"<<endl;
		cout<<"2.Pop element from stack"<<endl;
		cout<<"3.Display element of stack"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
			cout<<"Enter element to push:";
			cin>>value;
			push(value);
			break;
			case 2:
				pop();
				break;
			case 3:
			dispay();
			break;
			case 4:
			cout<<"Exiting programming !!"<<endl;
			return 0;
			break;
			default:
			cout<<"Invalid !"<<endl;
			break;
		}
	}
	return 0;
}