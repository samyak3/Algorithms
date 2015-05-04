#include"BST.h"
bstNode** GetMinNode(bstNode** ppRoot)
{
	bstNode* pRootCurrent = *ppRoot;
	if(pRootCurrent == NULL)
		return NULL;
	bstNode* next = pRootCurrent->left;
	while(next)
	{
		pRootCurrent = next;
		next = next->left;
	}
	return &pRootCurrent;
}
bool IsLeafNode(bstNode* pRoot)
{
	if(pRoot->left == NULL && pRoot->right == NULL)
	{
		return true;
	}
	return false;
}
void DeleteNode(bstNode** ppRoot,int data)
{
	bstNode* pRoot = *ppRoot;
	if(pRoot == NULL)
		return;
	if(pRoot->data == data)
	{
		if(IsLeafNode(pRoot))
		{
			delete pRoot;
			*ppRoot = NULL;
			return;
		}
		if(pRoot->left == NULL || pRoot->right == NULL)
		{
			if(pRoot->left == NULL)
			{				
				*ppRoot =pRoot->right;
				delete pRoot;
				pRoot = NULL;
				return;
			}
			else
			{
				*ppRoot =pRoot->left;
				delete pRoot;
				pRoot = NULL;
				return;
			}
		}
		if(pRoot->left && pRoot->right)
		{
			bstNode** ppSub = GetMinNode(&(pRoot->right));
			bstNode* pSub = *ppSub;
			pRoot->data = pSub->data;
			cout<<endl<<"Replacing with "<<pRoot->data<<endl;
			DeleteNode(&(pRoot->right),pSub->data);
		}
	}
	else
	{
		if(pRoot->data > data)
		{
			DeleteNode(&(pRoot->left),data);
		}
		else
		{
			DeleteNode(&(pRoot->right),data);
		}		
	}
}