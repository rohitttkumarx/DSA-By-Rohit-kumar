
#include <iostream>
using namespace std;

// Name: Rohit Kumar
// URN: 2514169
// CRN: 2515240

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node* createNode(int value)
{
	Node *newNode = new Node;

	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

Node* insert(Node *root, int value)
{
	if (root == NULL)
	{
		return createNode(value);
	}

	if (value < root->data)
	{
		root->left = insert(root->left, value);
	}
	else if (value > root->data)
	{
		root->right = insert(root->right, value);
	}
	else
	{
		cout << "\nDuplicate elements are not allowed.";
	}

	return root;
}

void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void preorder(Node *root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}

Node* search(Node *root, int key)
{
	if (root == NULL || root->data == key)
	{
		return root;
	}

	if (key < root->data)
	{
		return search(root->left, key);
	}

	return search(root->right, key);
}

Node* findMin(Node *root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}

	return root;
}

Node* deleteNode(Node *root, int key)
{
	if (root == NULL)
	{
		return root;
	}

	if (key < root->data)
	{
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->data)
	{
		root->right = deleteNode(root->right, key);
	}
	else
	{
		if (root->left == NULL)
		{
			Node *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			Node *temp = root->left;
			delete root;
			return temp;
		}

		Node *temp = findMin(root->right);

		root->data = temp->data;

		root->right = deleteNode(root->right, temp->data);
	}

	return root;
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
		cout << "\n\n----- BINARY SEARCH TREE MENU -----";
		cout << "\n1. Insert";
		cout << "\n2. Inorder Traversal";
		cout << "\n3. Preorder Traversal";
		cout << "\n4. Postorder Traversal";
		cout << "\n5. Search";
		cout << "\n6. Delete";
		cout << "\n7. Exit";

		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{
			case 1:
				cout << "\nEnter value to insert: ";
				cin >> value;
				root = insert(root, value);
				break;

			case 2:
				if (root == NULL)
					cout << "\nBST is empty.";
				else
				{
					cout << "\nInorder Traversal: ";
					inorder(root);
				}
				break;

			case 3:
				if (root == NULL)
					cout << "\nBST is empty.";
				else
				{
					cout << "\nPreorder Traversal: ";
					preorder(root);
				}
				break;

			case 4:
				if (root == NULL)
					cout << "\nBST is empty.";
				else
				{
					cout << "\nPostorder Traversal: ";
					postorder(root);
				}
				break;

			case 5:
				cout << "\nEnter element to search: ";
				cin >> value;

				if (search(root, value) != NULL)
					cout << "\nElement found in BST.";
				else
					cout << "\nElement not found in BST.";
				break;

			case 6:
				cout << "\nEnter element to delete: ";
				cin >> value;

				if (search(root, value) != NULL)
				{
					root = deleteNode(root, value);
					cout << "\nElement deleted successfully.";
				}
				else
				{
					cout << "\nElement not found in BST.";
				}
				break;

			case 7:
				cout << "\nExiting program...";
				break;

			default:
				cout << "\nInvalid choice!";
		}

	} while (choice != 7);

	return 0;
}
