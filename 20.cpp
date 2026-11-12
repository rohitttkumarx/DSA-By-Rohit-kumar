
#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert()
{
	int item;

	if (rear == MAX - 1)
	{
		cout << "\nQueue Overflow!";
	}
	else
	{
		cout << "\nEnter element to insert: ";
		cin >> item;

		if (front == -1)
		{
			front = 0;
		}

		rear++;
		queue[rear] = item;

		cout << "\nElement inserted successfully.";
	}
}

void deleteElement()
{
	if (front == -1 || front > rear)
	{
		cout << "\nQueue Underflow!";
	}
	else
	{
		cout << "\nDeleted element: " << queue[front];
		front++;

		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
	}
}

void display()
{
	if (front == -1)
	{
		cout << "\nQueue is empty.";
	}
	else
	{
		cout << "\nQueue elements are: ";

		for (int i = front; i <= rear; i++)
		{
			cout << queue[i] << " ";
		}
	}
}

int main()
{
	int choice;
	cout<<"Name:Rohit Kumar"<<endl;
	cout<<"URN:2514169"<<endl;
	cout<<"CRN:2515244"<<endl;

	do
	{
		cout << "\n\n----- LINEAR QUEUE MENU -----";
		cout << "\n1. Insert";
		cout << "\n2. Delete";
		cout << "\n3. Display";
		cout << "\n4. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{
			case 1:
				insert();
				break;

			case 2:
				deleteElement();
				break;

			case 3:
				display();
				break;

			case 4:
				cout << "\nExiting program...";
				break;

			default:
				cout << "\nInvalid choice!";
		}

	} while (choice != 4);

	return 0;
}
