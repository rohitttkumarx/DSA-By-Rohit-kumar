
#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

#define Max 100

char stack[Max];
int top=-1;

void push(char value){
	stack[++top]=value;
}

char pop(){
	return stack[top--];
}

int precedence(char op){
	if(op=='^')
		return 3;
	if(op=='*' || op=='/' || op=='%')
		return 2;
	if(op=='+' || op=='-')
		return 1;
	return 0;
}

int main(){
	char infix[Max],postfix[Max];
	int j=0;
	cout<<"Name:Rohit Kumar"<<endl;
	cout<<"URN:2514169"<<endl;
	cout<<"CRN:2515244"<<endl;

	cout<<"Enter infix expression: ";
	cin>>infix;

	for(int i=0;infix[i]!='\0';i++){
		char ch=infix[i];

		if(isalnum(ch)){
			postfix[j++]=ch;
		}
		else if(ch=='('){
			push(ch);
		}
		else if(ch==')'){
			while(top!=-1 && stack[top]!='('){
				postfix[j++]=pop();
			}
			if(top!=-1)
				pop();
		}
		else{
			while(top!=-1 && stack[top]!='(' &&
			(precedence(stack[top])>precedence(ch) ||
			(precedence(stack[top])==precedence(ch) && ch!='^'))){
				postfix[j++]=pop();
			}
			push(ch);
		}
	}

	while(top!=-1){
		postfix[j++]=pop();
	}

	postfix[j]='\0';

	cout<<"Postfix expression: "<<postfix<<endl;

	return 0;
}
