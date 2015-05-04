#include"Tree.h"
const int N = 7;
bool IsLeafNode(btNode* pNode)
{
	if(pNode && pNode->left == NULL && pNode->right == NULL)
		return true;
	else
		return false;
}

void PrintPath(int path[] , int length)
{
	for(int i = 0; i < length ; i++)
	{
		cout<<path[i]<<"\t";
	}
	cout<<endl;
}
void RootToLeafPath(btNode* pRoot,int path[],int length)
{
	if(pRoot == NULL)
	{
		return;
	}
	path[length]=pRoot->data;
	length++;
	if(IsLeafNode(pRoot))
	{
		PrintPath(path,length);
	}
	else
	{
		RootToLeafPath(pRoot->left,path,length);
		RootToLeafPath(pRoot->right,path,length);
	}
	
}