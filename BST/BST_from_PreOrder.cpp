#include"BST.h"
#include<stack>
bstNode* ConstructBstFromPreOrder(int pre[],int nSize)
{
	if(nSize <= 0)
		return NULL;
	bstNode* pRoot = getbtNode(pre[0]);
	
	stack<bstNode*>s;
	
	s.push(pRoot);
	
	for(int i = 1; i < nSize ; i++ )
	{
		bstNode* tNode = NULL;
	
		while(!s.empty() && pre[i] > s.top()->data)
		{
			tNode = s.top();
			s.pop();
		}
		if(tNode == NULL)
		{
			s.top()->left = getbtNode(pre[i]);
			s.push(s.top()->left);
		}
		else
		{
			tNode->right = getbtNode(pre[i]);
			s.push(tNode->right);
		}
	}
	return pRoot;
}