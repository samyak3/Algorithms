#include<iostream>
using namespace std;
typedef struct node 
{
	struct node* left;
	struct node* right;
	int nLowerValue;
	int data;
}bstNode;

bstNode* getbtNode(int data);

bstNode* getMin(bstNode* p);

bstNode* getMax(bstNode* p);

int GetTreeSize(bstNode* pRoot);

void UpdateLowerValue(bstNode*);

void AddNode(bstNode** ppRoot, int data );

void Inorder(bstNode* pRoot);

void Preorder(bstNode* pRoot);

void Postorder(bstNode* pRoot);

void DeleteNode(bstNode** pRoot,int data);

bstNode** GetMinNode(bstNode**);

bool IsBST(bstNode* pRoot,  int lbound =0,int ubound = 1000);

bstNode* LCA(bstNode* pRoot,int n1,int n2);

bstNode* ISucc(bstNode*,bstNode*);

int Kth(bstNode* pRoot,int K);

bstNode* ConstructBstFromPreOrder(int pre[] ,int size);