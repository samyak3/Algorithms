#include"Tree.h"
bool GetAncestors(btNode* pRoot,int data)
{
	if(pRoot == NULL)
		return false;
	if(pRoot->data == data)
		return true;
	if(GetAncestors(pRoot->left,data) || GetAncestors(pRoot->right,data))
	{
		cout<<pRoot->data<<"\t";
		return true;
	}
}