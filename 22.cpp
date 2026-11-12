
#include <iostream>
using namespace std;

// Name: Rohit Kumar
// URN: 2514169
// CRN: 2515240

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

bool isEmpty()
{
	return front == -1;
}

bool isFull()
{
	return (rear + 1) % MAX == front;
}

void insert()
{
	int item;

	if (isFull())
	{
		cout << "\nCircular Queue Overflow!";
	}
	else
	{
		cout << "\nEnter element to insert: ";
		cin >> item;

		if (front == -1)
		{
			front = 0;
		}

		rear = (rear + 1) % MAX;
		queue[rear] = item;

		cout << "\nElement inserted successfully.";
	}
}

void deleteElement()
{
	if (isEmpty())
	{
		cout << "\nCircular Queue Underflow!";
	}
	else
	{
		cout << "\nDeleted element: " << queue[front];

		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = (front + 1) % MAX;
		}
	}
}

void display()
{
	if (isEmpty())
	{
		cout << "\nCircular Queue is empty.";
	}
	else
	{
		cout << "\nCircular Queue elements are: ";

		int i = front;

		while (true)
		{
			cout << queue[i] << " ";

			if (i == rear)
			{
				break;
			}

			i = (i + 1) % MAX;
		}
	}
}

void checkStatus()
{
	if (isEmpty())
	{
		cout << "\nCircular Queue is in Underflow condition.";
	}
	else if (isFull())
	{
		cout << "\nCircular Queue is in Overflow condition.";
	}
	else
	{
		cout << "\nCircular Queue is neither Full nor Empty.";
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
		cout << "\n\n----- CIRCULAR QUEUE MENU -----";
		cout << "\n1. Check Overflow and Underflow";
		cout << "\n2. Insert Element";
		cout << "\n3. Delete Element";
		cout << "\n4. Display Queue";
		cout << "\n5. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{
			case 1:
				checkStatus();
				break;

			case 2:
				insert();
				break;

			case 3:
				deleteElement();
				break;

			case 4:
				display();
				break;

			case 5:
				cout << "\nExiting program...";
				break;

			default:
				cout << "\nInvalid choice!";
		}

	} while (choice != 5);

	return 0;
}
