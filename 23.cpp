
#include <iostream>
using namespace std;

// Name: Rohit Kumar
// URN: 2514169
// CRN: 2515240

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

bool isEmpty()
{
	return front == -1;
}

bool isFull()
{
	return (front == 0 && rear == MAX - 1) ||
	       (front == rear + 1);
}

void insert()
{
	int item;

	if (isFull())
	{
		cout << "\nDeque Overflow!";
		return;
	}

	cout << "\nEnter element to insert: ";
	cin >> item;

	if (isEmpty())
	{
		front = rear = 0;
	}
	else if (front == 0)
	{
		front = MAX - 1;
	}
	else
	{
		front--;
	}

	deque[front] = item;

	cout << "\nElement inserted successfully.";
}

void deleteElement()
{
	if (isEmpty())
	{
		cout << "\nDeque Underflow!";
		return;
	}

	cout << "\nDeleted element: " << deque[front];

	if (front == rear)
	{
		front = rear = -1;
	}
	else if (front == MAX - 1)
	{
		front = 0;
	}
	else
	{
		front++;
	}
}

void display()
{
	if (isEmpty())
	{
		cout << "\nDeque is empty.";
		return;
	}

	cout << "\nDeque elements are: ";

	int i = front;

	while (true)
	{
		cout << deque[i] << " ";

		if (i == rear)
		{
			break;
		}

		i = (i + 1) % MAX;
	}
}

void checkStatus()
{
	if (isEmpty())
	{
		cout << "\nDeque is in Underflow condition.";
	}
	else if (isFull())
	{
		cout << "\nDeque is in Overflow condition.";
	}
	else
	{
		cout << "\nDeque is neither Full nor Empty.";
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
		cout << "\n\n----- DEQUE MENU -----";
		cout << "\n1. Check Overflow and Underflow";
		cout << "\n2. Insert Element";
		cout << "\n3. Delete Element";
		cout << "\n4. Display Deque";
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
