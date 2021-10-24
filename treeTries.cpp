// kthMaxinBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node
{
public:
	Node();
	~Node();
	Node* left = NULL;
	Node* right = NULL;

	int Data;

};

Node::Node()
{

}

Node::~Node()
{
}

void PrintBSTInOrder(Node* root)
{
	if (root == NULL)
		return;
	if (root->left != NULL)
		PrintBSTInOrder(root->left);
	std::cout << root->Data << "\t";
	if (root->right != NULL)
		PrintBSTInOrder(root->right);
}

void PrintBSTPostOrder(Node* root)
{
	if (root == NULL)
		return;
	if (root->right != NULL)
		PrintBSTPostOrder(root->right);
	std::cout << root->Data << "\t";
	if (root->left != NULL)
		PrintBSTPostOrder(root->left);
}
static int countElement = 0;
void FindKthMaxElement(Node* root, int k)
{
	if (root == NULL)
		return;
	
	if (root->right != NULL)
		FindKthMaxElement(root->right,k);
	countElement++;
	if (countElement == k)
	{
		std::cout << root->Data;
		return;
	}
		
	if (root->left != NULL)
		FindKthMaxElement(root->left, k);
}

int main()
{
	Node *root = new Node();
	root->Data = 3;

	Node* l1 = new Node();
	l1->Data = 2;
	root->left = l1;

	Node* l2 = new Node();
	l2->Data = 1;
	l1->left = l2;

	Node* r1 = new Node();
	r1->Data = 4;
	root->right = r1;


	Node* r2 = new Node();
	r2->Data = 7;
	r1->right = r2;

	Node* r3 = new Node();
	r3->Data = 10;
	r2->right = r3;

	Node* r4 = new Node();
	r4->Data = 5;
	r2->left = r4;

	std::cout << "In Order" << std::endl;
	PrintBSTInOrder(root);
	std::cout << std::endl;
	std::cout << "Post Order" << std::endl;
	PrintBSTPostOrder(root);
	std::cout << std::endl;
	
	FindKthMaxElement(root, 7);
	FindKthMaxElement(root, 1);
}
