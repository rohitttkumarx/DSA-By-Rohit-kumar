
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
	int height;
};

int height(Node *root)
{
	if(root == NULL)
		return 0;
	return root->height;
}

int getBalance(Node *root)
{
	if(root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

Node* createNode(int value)
{
	Node *newNode = new Node;
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}

Node* rightRotate(Node *y)
{
	Node *x = y->left;
	Node *t2 = x->right;

	x->right = y;
	y->left = t2;

	y->height = 1 + max(height(y->left), height(y->right));
	x->height = 1 + max(height(x->left), height(x->right));

	return x;
}

Node* leftRotate(Node *x)
{
	Node *y = x->right;
	Node *t2 = y->left;

	y->left = x;
	x->right = t2;

	x->height = 1 + max(height(x->left), height(x->right));
	y->height = 1 + max(height(y->left), height(y->right));

	return y;
}

Node* insert(Node *root, int value)
{
	if(root == NULL)
		return createNode(value);

	if(value < root->data)
		root->left = insert(root->left, value);
	else if(value > root->data)
		root->right = insert(root->right, value);
	else
		return root;

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = getBalance(root);

	if(balance > 1 && value < root->left->data)
		return rightRotate(root);

	if(balance < -1 && value > root->right->data)
		return leftRotate(root);

	if(balance > 1 && value > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if(balance < -1 && value < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

Node* search(Node *root, int value)
{
	if(root == NULL || root->data == value)
		return root;

	if(value < root->data)
		return search(root->left, value);

	return search(root->right, value);
}

Node* minValueNode(Node *root)
{
	Node *current = root;

	while(current->left != NULL)
		current = current->left;

	return current;
}

Node* deleteNode(Node *root, int value)
{
	if(root == NULL)
		return root;

	if(value < root->data)
		root->left = deleteNode(root->left, value);
	else if(value > root->data)
		root->right = deleteNode(root->right, value);
	else
	{
		if(root->left == NULL || root->right == NULL)
		{
			Node *temp = root->left ? root->left : root->right;

			if(temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;

			delete temp;
		}
		else
		{
			Node *temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}

	if(root == NULL)
		return root;

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = getBalance(root);

	if(balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	if(balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if(balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	if(balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void inorder(Node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

int main()
{
	Node *root = NULL;
	int choice, value;
	cout<<"Name:Rohit Kumar"<<endl;
	cout<<"URN:2514169"<<endl;
	cout<<"CRN:2515244"<<endl;

	do
	{
		cout << "\n\n----- AVL TREE MENU -----";
		cout << "\n1. Insertion";
		cout << "\n2. Search";
		cout << "\n3. Deletion";
		cout << "\n4. Display";
		cout << "\n5. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch(choice)
		{
			case 1:
				cout << "Enter value to insert: ";
				cin >> value;
				root = insert(root, value);
				cout << "Element inserted successfully.";
				break;

			case 2:
				cout << "Enter element to search: ";
				cin >> value;
				if(search(root, value) != NULL)
					cout << "Element found in AVL Tree.";
				else
					cout << "Element not found.";
				break;

			case 3:
				cout << "Enter value to delete: ";
				cin >> value;
				if(search(root, value) != NULL)
				{
					root = deleteNode(root, value);
					cout << "Element deleted successfully.";
				}
				else
					cout << "Element not found.";
				break;

			case 4:
				cout << "Inorder Traversal: ";
				inorder(root);
				break;

			case 5:
				cout << "Exiting program.";
				break;

			default:
				cout << "Invalid choice!";
		}

	} while(choice != 5);

	return 0;
}
