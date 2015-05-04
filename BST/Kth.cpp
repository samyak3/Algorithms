#include"BST.h"

void UpdateLowerValue(bstNode* pRoot)
{
	if(pRoot == NULL)
		return;
	UpdateLowerValue(pRoot->left);
	
	pRoot->nLowerValue = GetTreeSize(pRoot->left);
		
	UpdateLowerValue(pRoot->right);
}
int Kth(bstNode* pRoot,int K)
{
	if(pRoot == NULL)
		return -1;
	UpdateLowerValue(pRoot);
	while(pRoot)
	{
		if(pRoot->nLowerValue == K -1)
		{
			return pRoot->data;
		}
		else if(pRoot->nLowerValue > K -1)
		{
			pRoot=pRoot->left;
		}
		else
		{
			K = K - pRoot->nLowerValue -1 ;
			pRoot=pRoot->right;			
		}
	}
}