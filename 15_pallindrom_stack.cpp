
#include<iostream>
using namespace std;
#define Max 100

int stack[Max];
int top=-1;

void push(int value){
	if(top==Max-1){
		cout<<"Stack Overflow";
		exit(0);
	}
	stack[++top]=value;
}

int pop(){
	return stack[top--];
}

int main(){
	int num,temp,digit,reverse=0;
	int arr[Max],i=0;

	cout<<"Name: Rohit Kumar"<<endl;
	cout<<"URN: 2514169"<<endl;
	cout<<"CRN: 2515244"<<endl;
	cout<<"Enter a number: ";
	cin>>num;

	if(num<0){
		cout<<"Not Palindrome";
		return 0;
	}

	temp=num;

	while(temp>0){
		arr[i++]=temp%10;
		temp/=10;
	}

	for(int j=i-1;j>=0;j--){
		push(arr[j]);
	}

	while(top!=-1){
		reverse=reverse*10+pop();
	}

	if(num==reverse){
		cout<<"Palindrome";
	}
	else{
		cout<<"Not Palindrome";
	}

	return 0;
}
