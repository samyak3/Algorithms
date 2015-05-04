#include"Tree.h"
void DeleteTree(btNode** ppRoot)
{
	btNode* pRoot = *ppRoot;
	if(pRoot)
	{
		DeleteTree(&(pRoot->left));
		DeleteTree(&(pRoot->right));
		delete pRoot;
		*ppRoot = NULL;
	}
}