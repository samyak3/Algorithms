#include"Tree.h"
btNode* LCA(btNode* pRoot,int n1 , int n2)
{
	if(pRoot == NULL)
	{
		return NULL;
	}
	if(n1 == pRoot->data || n2 == pRoot->data)
	{
		return pRoot;
	}
	btNode* lA = LCA(pRoot->left,n1,n2);
	btNode* rA = LCA(pRoot->right,n1,n2);
	if(lA && rA)
	{
		return pRoot;
	}
	else
	{
		return lA ? lA : rA;
	}
}