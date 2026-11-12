
#include <iostream>
using namespace std;

// Name: Rohit Kumar
// URN: 2514169
// CRN: 2515240

#define MAX 5

struct Node
{
	int data;
	int priority;
};

Node queue[MAX];
int count = 0;

void insert()
{
	int item, p;

	if (count == MAX)
	{
		cout << "\nPriority Queue Overflow!";
		return;
	}

	cout << "\nEnter element: ";
	cin >> item;

	cout << "Enter priority (1 = Highest): ";
	cin >> p;

	int i = count - 1;

	while (i >= 0 && queue[i].priority > p)
	{
		queue[i + 1] = queue[i];
		i--;
	}

	queue[i + 1].data = item;
	queue[i + 1].priority = p;

	count++;

	cout << "\nElement inserted successfully.";
}

void deleteElement()
{
	if (count == 0)
	{
		cout << "\nPriority Queue Underflow!";
		return;
	}

	cout << "\nDeleted element: " << queue[0].data;
	cout << "\nPriority: " << queue[0].priority;

	for (int i = 0; i < count - 1; i++)
	{
		queue[i] = queue[i + 1];
	}

	count--;
}

void display()
{
	if (count == 0)
	{
		cout << "\nPriority Queue is empty.";
		return;
	}

	cout << "\nPriority Queue elements are:\n";
	cout << "Element\tPriority\n";

	for (int i = 0; i < count; i++)
	{
		cout << queue[i].data << "\t";
		cout << queue[i].priority << "\n";
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
		cout << "\n\n----- PRIORITY QUEUE MENU -----";
		cout << "\n1. Insert Element";
		cout << "\n2. Delete Element";
		cout << "\n3. Display Priority Queue";
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
