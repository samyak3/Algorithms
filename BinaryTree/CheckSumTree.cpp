#include"Tree.h"
int GetTreeSum(btNode* pRoot)
{
	if(pRoot == NULL)
		return 0;
	
	if(IsLeafNode(pRoot))
	{		 
		return pRoot->data;
	}
	 int s = pRoot->data + GetTreeSum(pRoot->left)+GetTreeSum(pRoot->right);	
	return s;
}
bool IsSumTree(btNode* pRoot)
{
	
	if(pRoot == NULL || pRoot->left == NULL || pRoot->right == NULL)
		return true;
	return ((pRoot->data == (GetTreeSum(pRoot->left)+ GetTreeSum(pRoot->right)))
			&& IsSumTree(pRoot->left) && IsSumTree(pRoot->right));
}
