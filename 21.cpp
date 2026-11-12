
#include <iostream>
using namespace std;

// Name: Rohit Kumar
// URN: 2514169
// CRN: 2515240

struct Node
{
	int data;
	Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void insert()
{
	int item;

	Node *newNode = new Node;

	cout << "\nEnter element to insert: ";
	cin >> item;

	newNode->data = item;
	newNode->next = NULL;

	if (front == NULL)
	{
		front = rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}

	cout << "\nElement inserted successfully.";
}

void deleteElement()
{
	if (front == NULL)
	{
		cout << "\nQueue Underflow!";
	}
	else
	{
		Node *temp = front;

		cout << "\nDeleted element: " << front->data;

		front = front->next;

		if (front == NULL)
		{
			rear = NULL;
		}

		delete temp;
	}
}

void display()
{
	if (front == NULL)
	{
		cout << "\nQueue is empty.";
	}
	else
	{
		Node *temp = front;

		cout << "\nQueue elements are: ";

		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
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
		cout << "\n\n----- QUEUE MENU -----";
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

	while (front != NULL)
	{
		Node *temp = front;
		front = front->next;
		delete temp;
	}

	rear = NULL;

	return 0;
}
