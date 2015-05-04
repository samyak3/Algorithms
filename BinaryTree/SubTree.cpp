#include"Tree.h"

bool IsSubTree(btNode* pRootMain, btNode* pRootSub)
{
	if(pRootSub == NULL)
	{
		return true;
	}
	if(pRootMain == NULL)
	{
		return false;
	}
	if(pRootMain->data == pRootSub->data && IsSubTree(pRootMain->left,pRootSub->left) && IsSubTree(pRootMain->right,pRootSub->right))
	{
		return true;
	}
	else
	{
		if(IsSubTree(pRootMain->left,pRootSub) || IsSubTree(pRootMain->right,pRootSub))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}



