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
	std::cout << root->Data << std::endl;
	if (root->right != NULL)
		PrintBSTInOrder(root->right);
}

void PrintBSTPostOrder(Node* root)
{
	if (root == NULL)
		return;
	if (root->right != NULL)
		PrintBSTPostOrder(root->right);
	std::cout << root->Data << std::endl;
	if (root->left != NULL)
		PrintBSTPostOrder(root->left);
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
	r2->Data = 5;
	r1->right = r2;

	PrintBSTInOrder(root);
	PrintBSTPostOrder(root);

}
