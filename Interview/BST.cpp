/*
* BST.cpp
*
*  Created on: Mar 24, 2016
*      Author: Admin
*/

#define INORDER_TRAVERSAL
#define PREORDER_TRAVERSAL
#define POSTORDER_TRAVERSAL
#define INORDER_SUCCESSOR
#define INORDER_PREDECESSOR
#define ISBST
#define LOWEST_COMMON_ANCESTOR
#define KTH_SMALLEST_NODE
#define ITERATIVE_INORDER
#define COUNT_BST
#define TREE_TO_LIST
#define DELETE_NODE
#define ROOT_TO_LEAF_PATHS


#include<iostream>
#include<stack>
#include<vector>
using namespace std;

typedef struct bst
{
	int data;
	int leftSubTreeNodeCount;
	struct bst *left;
	struct bst *right;
}Node;

Node* pRoot = NULL;

Node* getNode(int val)
{
	Node* pNode = new Node;
	pNode->leftSubTreeNodeCount = 0;
	pNode->left = 0;
	pNode->right = 0;
	pNode->data = val;
	return pNode;
}

void insert(Node** ppRoot, int val);
void inorder(Node* pRoot);
void preorder(Node* pRoot);
void postorder(Node* pRoot);
Node* DeleteNode(Node** ppRoot, int val);
bool IsLeafNode(Node* pRoot);
Node* FindMinNode(Node* pRoot);
Node* FindMaxNode(Node* pRoot);
Node* InOrderSuccessor(Node* pRoot, int val);
Node* InOrderPredecessor(Node* pRoot, int val);
bool IsBST(Node* pRoot);
bool IsBSTUtil(Node* pRoot, int max, int min);
Node* LCA(Node* pRoot, int val1, int val2);
Node* FindKthSmallest(Node* pRoot, int K);
void iterative_inorder(Node* pRoot);
int CountBST(int nNodes);
void join(Node* pA, Node* pB);
Node* append(Node* pA, Node* pB);
Node* TreeToList(Node* pRoot);
void printList(Node* pHead);
void RootToLeafPaths(Node* pRoot);
void RootToLeafPathsUtil(Node* pRoot, vector<int>v);
bool IsLeafNode(Node* pRoot)
{
	if (pRoot->left == NULL && pRoot->right == NULL)
	{
		return true;
	}
	return false;
}

Node* FindMinNode(Node* pRoot)
{
	if (pRoot == NULL)
	{
		return NULL;
	}
	while (pRoot->left)
	{
		pRoot = pRoot->left;
	}
	return pRoot;
}
Node* FindMaxNode(Node* pRoot)
{
	if (pRoot == NULL)
	{
		return NULL;
	}
	while (pRoot->right)
	{
		pRoot = pRoot->right;
	}
	return pRoot;
}


int main()
{
	insert(&pRoot, 4);
	insert(&pRoot, 2);
	insert(&pRoot, 1);
	insert(&pRoot, 3);
	insert(&pRoot, 6);
	insert(&pRoot, 5);
	insert(&pRoot, 7);

#ifdef INORDER_TRAVERSAL
	cout << "Inorder traversal :: " << endl;
	inorder(pRoot);
	cout << endl << endl;
#endif

#ifdef PREORDER_TRAVERSAL
	cout << "preorder traversal :: " << endl;
	preorder(pRoot);
	cout << endl << endl;
#endif

#ifdef POSTORDER_TRAVERSAL
	cout << "postorder traversal :: " << endl;
	postorder(pRoot);
	cout << endl << endl;
#endif

#ifdef INORDER_SUCCESSOR
	int data = 1;
	Node* pSucc = InOrderSuccessor(pRoot, data);
	if (pSucc)
	{
		cout << "InOrderSuccessor of  " << data << " :: " << pSucc->data << endl;
	}
	else
	{
		cout << "These is no InOrderSuccessor of " << data << endl;
	}

	cout << endl << endl;

#endif

#ifdef INORDER_PREDECESSOR
	Node* pPre = InOrderPredecessor(pRoot, data);
	if (pPre)
	{
		cout << "InOrderPredecessor of  " << data << " :: " << pPre->data << endl;
	}
	else
	{
		cout << "These is no InOrderPredecessor of " << data << endl;
	}
	cout << endl << endl;

#endif

#ifdef ISBST
	if (IsBST(pRoot))
	{
		cout << "The binary tree is a BST " << endl;
	}
	else
	{
		cout << "The binary tree is not a BST " << endl;
	}
	cout << endl << endl;

#endif

#ifdef LOWEST_COMMON_ANCESTOR
	int val1 = 5;
	int val2 = 7;
	cout << "The LCA of " << val1 << " and " << val2 << " is ::" << LCA(pRoot, val1, val2)->data << endl;
	cout << endl << endl;
#endif


#ifdef KTH_SMALLEST_NODE
	int K = 6;

	cout << K << " smallest node is :: " << FindKthSmallest(pRoot, K)->data << endl;
	cout << endl << endl;
#endif

#ifdef ITERATIVE_INORDER
	cout << endl << "Iterative Inorder travrsal ::" << endl;
	iterative_inorder(pRoot);
	cout << endl << endl;
#endif

#ifdef COUNT_BST
	int nNodes = 3;
	cout << "Number of BST with " << nNodes << " are ::" << CountBST(nNodes) << endl;
	cout << endl << endl;
#endif


#ifdef ROOT_TO_LEAF_PATHS
	RootToLeafPaths(pRoot);
#endif

#ifdef DELETE_NODE
	DeleteNode(&pRoot, 6);
	cout << "Inorder traversal after Deletion :: " << endl;
	inorder(pRoot);
	cout << endl << endl;
#endif

#ifdef TREE_TO_LIST
	cout << "List :: " << endl;
	printList(TreeToList(pRoot));
	cout << endl;
#endif
	return 0;
}

void insert(Node** ppRoot, int value)
{
	if (*ppRoot == NULL)//If node is NULL
	{
		*ppRoot = getNode(value);
		return;
	}
	else
	{
		if ((*ppRoot)->data > value)
		{
			(*ppRoot)->leftSubTreeNodeCount++;
			insert(&((*ppRoot)->left), value);
		}
		else
		{
			insert(&((*ppRoot)->right), value);
		}
	}
}

void inorder(Node* pRoot)//left subtree -> root -> right subtree
{
	if (pRoot)
	{
		inorder(pRoot->left);
		cout << pRoot->data << " ";
		inorder(pRoot->right);
	}
}
void preorder(Node* pRoot)// root -> left subtree -> right subtree
{
	if (pRoot)
	{
		cout << pRoot->data << " ";
		preorder(pRoot->left);
		preorder(pRoot->right);
	}
}
void postorder(Node* pRoot)// left subtree -> right subtree -> root
{
	if (pRoot)
	{
		postorder(pRoot->left);
		postorder(pRoot->right);
		cout << pRoot->data << " ";
	}
}
Node* DeleteNode(Node** ppRoot, int val)
{
	if (*ppRoot == NULL)
	{
		return NULL;//Node to be deleted is NULL
	}
	else
	{
		if ((*ppRoot)->data == val)//Node to be deleted found
		{
			if (IsLeafNode(*ppRoot))//If node to be deleted is a leaf node
			{
				delete *ppRoot;
				*ppRoot = NULL;
				return NULL;
			}
			else
			{
				if ((*ppRoot)->right == NULL)//If right subtree is NULL
				{
					delete *ppRoot;
					*ppRoot = (*ppRoot)->left;
					return *ppRoot;
				}
				else
				{
					Node* pMinNode = FindMinNode((*ppRoot)->right);
					//replace the node data with inorder successor and delete the successor node
					(*ppRoot)->data = pMinNode->data;
					DeleteNode(&((*ppRoot)->right), pMinNode->data);
					return *ppRoot;
				}
			}
		}
		else
		{
			if ((*ppRoot)->data > val)
			{
				(*ppRoot)->left = DeleteNode(&((*ppRoot)->left), val);
				return *ppRoot;
			}
			else
			{
				(*ppRoot)->right = DeleteNode(&((*ppRoot)->right), val);
				return *ppRoot;
			}
		}
	}
}
Node* InOrderSuccessor(Node* pRoot, int val)
{
	if (pRoot == NULL)
	{
		return NULL;
	}
	else
	{
		if (pRoot->data < val)
		{
			return InOrderSuccessor(pRoot->right, val);
		}
		else if (pRoot->data > val)
		{
			Node* pParent = pRoot;
			Node* pSucc = InOrderSuccessor(pRoot->left, val);
			if (pSucc)
			{
				return pSucc;
			}
			else
			{
				return pParent;
			}
		}
		else
		{
			return FindMinNode(pRoot->right);
		}
	}
}
Node* InOrderPredecessor(Node* pRoot, int val)
{
	if (pRoot == NULL)
	{
		return NULL;
	}
	else
	{
		if (pRoot->data < val)
		{
			Node* pParent = pRoot;
			Node* pPre = InOrderPredecessor(pRoot->right, val);
			if (pPre)
			{
				return pPre;
			}
			else
			{
				return pParent;
			}
		}
		else if (pRoot->data > val)
		{
			return InOrderPredecessor(pRoot->left, val);
		}
		else
		{
			return FindMaxNode(pRoot->left);
		}
	}
}
bool IsBST(Node* pRoot)
{
	//when u process the left sub tree then the maximum value it can contain is should be lesser than the root value;
	//Similarly when u process the right  sub tree then the minimum value it can contain should be greater than the root value;
	return IsBSTUtil(pRoot, 99999, -1);
}
bool IsBSTUtil(Node* pRoot, int maxValue, int minValue)
{
	if (pRoot == NULL)
	{
		return true;
	}
	bool bWithinRange = false;
	if (pRoot->data > minValue && pRoot->data < maxValue)
	{
		bWithinRange = true;
	}
	return (bWithinRange && IsBSTUtil(pRoot->left, pRoot->data, minValue) && IsBSTUtil(pRoot->right, maxValue, pRoot->data));
}
Node* LCA(Node* pRoot, int val1, int val2)
{
	if ((pRoot)->data > val1 && (pRoot)->data > val2)
	{
		return LCA(pRoot->left, val1, val2);
	}
	if ((pRoot)->data < val1 && (pRoot)->data < val2)
	{
		return LCA(pRoot->right, val1, val2);
	}
	return pRoot;
}
Node* FindKthSmallest(Node* pRoot, int K)
{
	if (pRoot == NULL)
	{
		return NULL;
	}
	if (pRoot->leftSubTreeNodeCount + 1 == K)
	{
		return pRoot;
	}
	else if (pRoot->leftSubTreeNodeCount + 1 > K)
	{
		return FindKthSmallest(pRoot->left, K);
	}
	else
	{
		return FindKthSmallest(pRoot->right, K - (pRoot->leftSubTreeNodeCount + 1));
	}
}

void iterative_inorder(Node* pRoot)
{
	stack<Node*>s;
	s.push(pRoot);
	while (s.empty() == false)
	{
		if (pRoot->left)
		{
			pRoot = pRoot->left;
			s.push(pRoot);
		}
		else
		{
			Node* pTop = s.top();
			cout << pTop->data << " ";
			s.pop();
			if (pTop->right)
			{
				pRoot = pTop->right;
				s.push(pRoot);
			}
		}
	}
}

int CountBST(int nNodes)
{
	if (nNodes <= 1)
	{
		return 1;
	}
	int count = 0;
	for (int n = 1; n <= nNodes; n++)
	{
		int nLeftTreeNodes = n - 1;
		int nRightTreeNnodes = nNodes - n;
		count = count + CountBST(nLeftTreeNodes) * CountBST(nRightTreeNnodes);
	}
	return count;
}

void join(Node* pA, Node* pB)
{
	pA->right = pB;
	pB->left = pA;
}
Node* append(Node* pA, Node* pB)
{
	if (pA == NULL)
	{
		return pB;
	}
	if (pB == NULL)
	{
		return pA;
	}
	Node* pALast;
	Node* pBLast;
	pALast = pA->left;
	pBLast = pB->left;

	join(pALast, pB);
	join(pBLast, pA);
	return pA;
}
Node* TreeToList(Node* pRoot)
{
	if (pRoot == NULL)
	{
		return NULL;
	}
	Node* pLeftList;
	Node* pRightList;

	pLeftList = TreeToList(pRoot->left);
	pRightList = TreeToList(pRoot->right);

	pRoot->left = pRoot;
	pRoot->right = pRoot;
	pLeftList=append(pLeftList, pRoot);
	pLeftList=append(pLeftList, pRightList);

	return pLeftList;
}
void printList(Node* pHead)
{
	Node* cptr = pHead;
	while (1)
	{
		cout << cptr->data << " ";
		cptr = cptr->right;
		if (cptr == pHead)
			break;
	}
}
void RootToLeafPaths(Node* pRoot)
{
	vector<int>v;
	if (pRoot == NULL)
		return;
	cout << "Root to Leaf paths are :: " << endl;
	RootToLeafPathsUtil(pRoot, v);
}
void RootToLeafPathsUtil(Node* pRoot, vector<int>v)
{
	if (pRoot == NULL)
	{
		return;
	}
	v.push_back(pRoot->data);
	if (IsLeafNode(pRoot))
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}
	RootToLeafPathsUtil(pRoot->left, v);
	RootToLeafPathsUtil(pRoot->right, v);
}
