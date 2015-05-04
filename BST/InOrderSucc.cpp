#include"BST.h"

bstNode* ISucc(bstNode* pRoot,bstNode* pNode)
{
	if(pNode->right)
		return getMin(pNode->right);
	bstNode* pSucc = NULL;
	while(pRoot)
	{
		if(pRoot->data > pNode->data)
		{
			pSucc = pRoot;
			pRoot = pRoot->left;
			
		}
		else if(pRoot->data < pNode->data)
		{
			pRoot = pRoot->right;
		}
		else
		{
			break;
		}			
	}
	return pSucc;
}