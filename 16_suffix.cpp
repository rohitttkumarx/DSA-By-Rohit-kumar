
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

#define Max 100

int stack[Max];
int top=-1;

void push(int value){
	if(top==Max-1){
		cout<<"Stack overflow";
		exit(0);
	}
	stack[++top]=value;
}

int pop(){
	if(top==-1){
		cout<<"Invalid postfix expression";
		exit(0);
	}
	return stack[top--];
}

int main(){
	char exp[Max];
	int a,b,result;

	cout<<"Name: Rohit Kumar"<<endl;
	cout<<"URN: 2514169"<<endl;
	cout<<"CRN: 2515244"<<endl;
	cout<<"Enter postfix expression: ";
	cin>>exp;

	for(int i=0;exp[i]!='\0';i++){
		if(exp[i]>='0' && exp[i]<='9'){
			push(exp[i]-'0');
		}
		else{
			b=pop();
			a=pop();

			switch(exp[i]){
				case '+': result=a+b; break;
				case '-': result=a-b; break;
				case '*': result=a*b; break;
				case '/':
					if(b==0){
						cout<<"Division by zero";
						return 0;
					}
					result=a/b;
					break;
				case '%':
					if(b==0){
						cout<<"Modulo by zero";
						return 0;
					}
					result=a%b;
					break;
				case '^': result=(int)pow(a,b); break;
				default:
					cout<<"Invalid operator";
					return 0;
			}
			push(result);
		}
	}

	if(top!=0){
		cout<<"Invalid postfix expression";
		return 0;
	}

	cout<<"Result: "<<pop()<<endl;

	return 0;
}
