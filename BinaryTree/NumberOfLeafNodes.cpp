#include"Tree.h"
int NumberOfLeafNodes(btNode* pRoot)
{
	if(pRoot == NULL)
		return 0;
	if(IsLeafNode(pRoot))
	{
		return 1;
	}
	else
	{
		return(NumberOfLeafNodes(pRoot->left)+NumberOfLeafNodes(pRoot->right));
	}
}