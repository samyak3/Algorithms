#include"BST.h"

bstNode* LCA(bstNode* pRoot,int n1 , int n2)
{
	if(pRoot == NULL)
		return NULL;
	
	if(n1 > pRoot->data && n2 >pRoot->data )
		return LCA(pRoot->right,n1,n2);
	
	if(n1 < pRoot->data && n2 < pRoot->data )
		return LCA(pRoot->left,n1,n2);
	
	return pRoot;
}