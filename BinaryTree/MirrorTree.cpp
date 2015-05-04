#include"Tree.h"
void MirrorTree(btNode* pRoot)
{
	if(pRoot)
	{
		MirrorTree(pRoot->left);
		MirrorTree(pRoot->right);
		btNode* tempNode = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tempNode;
	}
}