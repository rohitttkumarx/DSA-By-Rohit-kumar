#include <iostream>
using namespace std;

struct Node
{
	int coeff, x, y, z;
	Node* next;
};

Node* createNode(int c, int a, int b, int d)
{
	Node* temp = new Node;
	temp->coeff = c;
	temp->x = a;
	temp->y = b;
	temp->z = d;
	temp->next = NULL;
	return temp;
}

void insert(Node*& head, int c, int x, int y, int z)
{
	Node* temp = createNode(c, x, y, z);
	if (head == NULL)
	{
		head = temp;
		return;
	}
	Node* p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = temp;
}

void addTerm(Node*& sum, int c, int x, int y, int z)
{
	Node* p = sum;
	while (p != NULL)
	{
		if (p->x == x && p->y == y && p->z == z)
		{
			p->coeff += c;
			return;
		}
		p = p->next;
	}
	insert(sum, c, x, y, z);
}

Node* addPolynomials(Node* p1, Node* p2)
{
	Node* sum = NULL;
	while (p1 != NULL)
	{
		addTerm(sum, p1->coeff, p1->x, p1->y, p1->z);
		p1 = p1->next;
	}
	while (p2 != NULL)
	{
		addTerm(sum, p2->coeff, p2->x, p2->y, p2->z);
		p2 = p2->next;
	}
	return sum;
}

void display(Node* head)
{
	bool first = true;
	while (head != NULL)
	{
		if (head->coeff != 0)
		{
			if (!first && head->coeff > 0)
				cout << " + ";
			else if (!first)
				cout << " - ";
			else if (head->coeff < 0)
				cout << "-";

			int c = head->coeff < 0 ? -head->coeff : head->coeff;
			cout << c;
			if (head->x != 0)
				cout << "x^" << head->x;
			if (head->y != 0)
				cout << "y^" << head->y;
			if (head->z != 0)
				cout << "z^" << head->z;
			first = false;
		}
		head = head->next;
	}
	if (first)
		cout << "0";
	cout << '\n';
}

int main()
{
	Node *POLY1 = NULL, *POLY2 = NULL, *POLYSUM = NULL;
	int n, c, x, y, z;
	cout<<"Name:Rohit Kumar"<<endl;
	cout<<"URN:2514169"<<endl;
	cout<<"CRN:2515244"<<endl;
	cout << "Enter number of terms in POLY1: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c >> x >> y >> z;
		insert(POLY1, c, x, y, z);
	}

	cout << "Enter number of terms in POLY2: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c >> x >> y >> z;
		insert(POLY2, c, x, y, z);
	}

	POLYSUM = addPolynomials(POLY1, POLY2);

	cout << "POLY1 = ";
	display(POLY1);
	cout << "POLY2 = ";
	display(POLY2);
	cout << "POLYSUM = ";
	display(POLYSUM);

	return 0;
}