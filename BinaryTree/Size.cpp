#include"Tree.h"
int GetTreeSize(btNode* pRoot)
{
	if(pRoot == NULL)
		return 0;
	else
		return 1 + GetTreeSize(pRoot->left) + GetTreeSize(pRoot->right);
}