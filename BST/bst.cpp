#include"BST.h"

bstNode* pRoot = NULL;
bstNode* pRootSub = NULL;
bstNode* getbtNode(int data)
{
	bstNode* pNode = new bstNode;
	pNode->data = data;
	pNode->left = NULL;
	pNode->right = NULL;
	return pNode;
}
bstNode* getMin(bstNode* p)
{
	if(p == NULL)
	{
		return NULL;
	}
	while(p->left)
	{
		p = p->left;
	}
	return p;
}
bstNode* getMax(bstNode* p)
{
	if(p == NULL)
	{
		return NULL;
	}
	while(p->right)
	{
		p = p->right;
	}
	return p;
}

int GetTreeSize(bstNode* pRoot)
{
	if(pRoot == NULL)
		return 0;
	else
		return 1 + GetTreeSize(pRoot->left) + GetTreeSize(pRoot->right);
}
void AddNode(bstNode** ppRoot,int data)
{
	bstNode* pRoot = *ppRoot;
	if(pRoot == NULL)
	{
		pRoot = getbtNode(data);
		*ppRoot = pRoot;
	}
	else
	{
		if(data >pRoot->data)
		{
			AddNode(&pRoot->right,data);
		}
		else
		{
			AddNode(&pRoot->left,data);
		}
	}
}
void Inorder(bstNode* pRoot)
{
	if(pRoot == NULL)
		return;
	Inorder(pRoot->left);
	cout<<pRoot->data<<"\t";
	Inorder(pRoot->right);
}
void Preorder(bstNode* pRoot)
{
	if(pRoot == NULL)
		return;
	cout<<pRoot->data<<"\t";
	Preorder(pRoot->left);
	Preorder(pRoot->right);
}

void Postorder(bstNode* pRoot)
{
	if(pRoot == NULL)
		return;	
	Postorder(pRoot->left);
	Postorder(pRoot->right);
	cout<<pRoot->data<<"\t";
}
int main()
{
	AddNode(&pRoot,4);
	AddNode(&pRoot,6);
	AddNode(&pRoot,2);
	AddNode(&pRoot,3);
	AddNode(&pRoot,5);
	AddNode(&pRoot,7);
	AddNode(&pRoot,1);
	
	cout<<endl<<"##########################################################################################################"<<endl;
	
	cout<<"Inorder Traversal ::"<<endl;
	Inorder(pRoot);
	cout<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	
	cout<<"Preorder Traversal ::"<<endl;
	
	Preorder(pRoot);
	cout<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	
	cout<<"Postorder Traversal ::"<<endl;
	Postorder(pRoot);
	cout<<endl;
	
cout<<endl<<"##########################################################################################################"<<endl;
	
	cout<<"Deleting Node with data 7 ::"<<endl;
	DeleteNode(&pRoot,7);
	cout<<endl;
	cout<<"Inorder Traversal ::"<<endl;
	Inorder(pRoot);
	cout<<endl;
	AddNode(&pRoot,7);
	cout<<endl<<"##########################################################################################################"<<endl;
	
	cout<<"CheckIFBST  ::"<<IsBST(pRoot);
	
	cout<<endl<<"##########################################################################################################"<<endl;
	
	cout<<endl<<"LCA of 1 and 3  :: "<<LCA(pRoot,1,3)->data<<endl;

	cout<<endl<<"LCA of 1 and 7  :: "<<LCA(pRoot,1,7)->data<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;

	cout<<endl<<"ISucc of 1 :: "<<ISucc(pRoot,pRoot->left->left)->data<<endl;
	
	cout<<endl<<"ISucc of 6 :: "<<ISucc(pRoot,pRoot->right)->data<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	
	cout<<"5th Order value :: "<<Kth(pRoot,5)<<endl; 
	
	cout<<"3rd Order value :: "<<Kth(pRoot,3)<<endl;
	
	cout<<"4th Order value :: "<<Kth(pRoot,4)<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	
	int pre[] = {10,5,1,7,40,50};
	
	bstNode* pPRoot = ConstructBstFromPreOrder(pre,6);
	
	cout<<endl<<"Inorder traversal of Constructed tree ::"<<endl;
	Inorder(pPRoot);
	
	cout<<endl<<"Preorder traversal of Constructed tree ::"<<endl;
	Preorder(pPRoot);

	cout<<endl<<"##########################################################################################################"<<endl;
	return 0;
}
