#include"Tree.h"

int GetTreeHeight(btNode* pRoot)
{
	if(pRoot == NULL)
		return 0;
	else
		return 1 + max(GetTreeHeight(pRoot->left),GetTreeHeight(pRoot->right));
}