#include"Tree.h"
#include<stack>
stack<int>s;
void RootToLeafPath(btNode* pRoot)
{
	if(pRoot->left == NULL)
	{
		return;
	}
	Inorder(pRoot->left);
	cout<<pRoot->data<<"\t";
	Inorder(pRoot->right);
}