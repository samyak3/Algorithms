#include"Tree.h"
bool hasPathSum(btNode* pRoot,int sum)
{
	if(pRoot == NULL)
	{
		return false;
	}
	else
	{
		int tsum = sum - pRoot->data;
		if(tsum == 0 && IsLeafNode(pRoot))
		{
			return true;
		}
		bool bSumLeft = hasPathSum(pRoot->left,tsum);
		bool bSumRight = hasPathSum(pRoot->right,tsum);
		if(bSumLeft || bSumRight)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}