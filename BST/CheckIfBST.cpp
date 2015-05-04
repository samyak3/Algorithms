#include"BST.h"
bool IsBST(bstNode* pRoot,int lbound , int ubound)
{
	if(pRoot==NULL)
	{
		return true;
	}
	bool b1 = true;
	if(pRoot->left)
	{
		if(pRoot->data < pRoot->left->data)
		b1 = false;
	}
	bool b2 = false;
	if(pRoot->data > lbound)
	{
		b2 = true;
	}
	bool b3 = false;
	if(pRoot->data < ubound)
	{
		b3 = true;
	}
	bool b4 = true;
	if(pRoot->right)
	{
		if(pRoot->data > pRoot->right->data)
		b4 = false;
	}
	return(b1 && b2 && b3 && b4 && IsBST(pRoot->left,lbound,pRoot->data) && IsBST(pRoot->right,pRoot->data,ubound));
	/*
	return (
			(pRoot->data > (pRoot->left ? pRoot->left->data : 0) )
			&& (pRoot->data > lbound)
			&& (pRoot->data < ubound)
			&& (pRoot->data < (pRoot->right ? pRoot->right->data : 1000) )
			&& IsBST(pRoot->left,lbound,pRoot->data)
			&& IsBST(pRoot->right,pRoot->data,ubound)
			)*/
}