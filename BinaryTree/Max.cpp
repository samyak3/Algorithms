#include"Tree.h"

int MaxTreeElement(btNode* pRoot)
{
	if(pRoot)
	{
		return max(pRoot->data,max(MaxTreeElement(pRoot->left),MaxTreeElement(pRoot->right)));
	}
	else
		return -1;
}