#include<iostream>
using namespace std;
typedef struct node 
{
	struct node* left;
	struct node* right;
	int data;
}btNode;

btNode* gebtNode(int data);

void AddNode(btNode** ppRoot, int data );

void Inorder(btNode* pRoot);

void Preorder(btNode* pRoot);

void Postorder(btNode* pRoot);

void LOrder(btNode* pRoot);

int GetTreeSize(btNode* pRoot);

int GetTreeHeight(btNode* pRoot);

void DeleteTree(btNode** pRoot);

void MirrorTree(btNode* pRoot);

int MaxTreeElement(btNode* pRoot);

void RootToLeafPath(btNode* pRoot,int path[],int length);

bool IsLeafNode(btNode* pNode);

int NumberOfLeafNodes(btNode* pRoot);

bool GetAncestors(btNode* pRoot,int child);

int GetTreeSum(btNode* pRoot);

bool IsSumTree(btNode* pRoot);

btNode* LCA(btNode* pRoot,int n1,int n2);

bool hasPathSum(btNode* pRoot,int Sum);

bool IsSubTree(btNode* pRootMain,btNode* pRootSub);