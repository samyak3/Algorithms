#if 1
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct node
{
	int data;
	int height;
	node* left;
	node* right;
	node()
	{
		height = 1;
		left = 0;
		right = 0;
	}
};

node* GetNode(int data)
{
	node* pNode = new node;
	pNode->data = data;
	return pNode;
}
int GetHeight(node* pNode)
{
	if (pNode)
		return pNode->height;
	return 0;
}
int GetBalance(node* pNode)
{
	if (pNode == 0)
		return 0;
	return GetHeight(pNode->left) - GetHeight(pNode->right);
}

node* LeftRotate(node* pNode)
{
	node* rightChild = pNode->right;
	node* leftChildOfRightChild = rightChild->left;

	rightChild->left = pNode;
	pNode->right = leftChildOfRightChild;

	pNode->height = 1 + max(GetHeight(pNode->left), GetHeight(pNode->right));
	rightChild->height = 1 + max(GetHeight(rightChild->left), GetHeight(rightChild->right));

	return rightChild;
}
node* RightRotate(node* pNode)
{
	node* leftChild = pNode->left;
	node* RightChildOfleftChild = leftChild->right;

	leftChild->right = pNode;
	pNode->left = RightChildOfleftChild;

	pNode->height = 1 + max(GetHeight(pNode->left), GetHeight(pNode->right));
	leftChild->height = 1 + max(GetHeight(leftChild->left), GetHeight(leftChild->right));

	return leftChild;
}

node* insert(node* pNode, int key)
{
	if (pNode == NULL)
		return GetNode(key);
	else if (pNode->data > key)
	{
		pNode->left = insert(pNode->left, key);
	}
	else
	{
		pNode->right = insert(pNode->right, key);
	}

	pNode->height = 1 + max(GetHeight(pNode->left), GetHeight(pNode->right));

	int balance = GetHeight(pNode->left) - GetHeight(pNode->right);

	if (balance > 1 && pNode->left->data > key) //LL case
	{
		return RightRotate(pNode);

	}
	else if (balance > 1 && pNode->left->data < key)//LR Case
	{
		pNode->left = LeftRotate(pNode->left);
		return RightRotate(pNode);
	}
	else if (balance < -1 && pNode->right->data < key)//RR Case
	{
		return LeftRotate(pNode);
	}
	else if (balance < -1 && pNode->right->data > key)//RL Case
	{
		pNode->right = RightRotate(pNode->right);
		return LeftRotate(pNode);
	}
	else
	{
		return pNode;
	}
}
void preorder(node* root)
{
	if (root)
	{
		//cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
int main()
{
	node* root = 0;

	for (int i = 1; i <= 128; i++)
	{
		root = insert(root, i);
	}
	cout << "Height of AVL is " << root->height << endl;
#if 0
	root = insert(root, 10);
	//cout << "Root data after inserting 10 :: " << root->data << endl;

	root = insert(root, 20);
	//cout << "Root data after inserting 20 :: " << root->data << endl;

	root = insert(root, 30);
	//cout << "Root data after inserting 30 :: " << root->data << endl; 

	root = insert(root, 40);
	//cout << "Root data after inserting 40 :: " << root->data << endl;

	root = insert(root, 50);
	//cout << "Root data after inserting 50 :: " << root->data << endl;

	root = insert(root, 25);
	//cout << "Root data after inserting 25 :: " << root->data << endl;

	preorder(root);
#endif
	return 0;
}
#endif