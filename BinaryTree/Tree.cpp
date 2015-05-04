#include"Tree.h"

btNode* pRoot = NULL;
btNode* pRootSub = NULL;
btNode* getbtNode(int data)
{
	btNode* pNode = new btNode;
	pNode->data = data;
	pNode->left = NULL;
	pNode->right = NULL;
	return pNode;
}
int main()
{
	#if 1
	AddNode(&pRoot,4);
	AddNode(&pRoot,6);
	AddNode(&pRoot,2);
	AddNode(&pRoot,3);
	AddNode(&pRoot,5);
	AddNode(&pRoot,7);
	AddNode(&pRoot,1);
	
	//SubTree

	pRootSub = getbtNode(2);
	pRootSub->left = getbtNode(1);
	pRootSub->right = getbtNode(3);//true subtree case
	//pRootSub->right = getbtNode(4);//fasle subtree case
	#else//for Sum Tree 
	pRoot = getbtNode(30);
	pRoot->left = getbtNode(10);
	pRoot->right = getbtNode(5);
	pRoot->left->left = getbtNode(6);
	pRoot->left->right = getbtNode(4);
	pRoot->right->right = getbtNode(3);
	pRoot->right->left = getbtNode(2);
		
	#endif
	
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
	cout<<"Level Order Traversal ::"<<endl;
	LOrder(pRoot);
	cout<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	cout<<"Size of the Tree ::"<<endl;
	cout<<GetTreeSize(pRoot);
	cout<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	cout<<"Height of the Tree ::"<<endl;
	cout<<GetTreeHeight(pRoot);
	cout<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	#if 0
	DeleteTree(&pRoot);
	
	AddNode(&pRoot,1);
	
	cout<<"Inorder Traversal after Deletion::"<<endl;
	Inorder(pRoot);
	cout<<endl;
	#endif
		
	MirrorTree(pRoot);	
	cout<<"Inorder Traversal after MirrorTree operation::"<<endl;
	Inorder(pRoot);
	cout<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	
	MirrorTree(pRoot);
	cout<<"Inorder Traversal after MirrorTree operation for second time::"<<endl;
	Inorder(pRoot);
	cout<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	cout<<"Max Element of the Tree ::"<<endl;
	cout<<MaxTreeElement(pRoot);
	cout<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	
	int path[7];
	cout<<"Root To Leaf Paths ::"<<endl;
	RootToLeafPath(pRoot,path,0);
	cout<<endl<<"##########################################################################################################"<<endl;
	cout<<"Number of Leaf Nodes::"<<NumberOfLeafNodes(pRoot)<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	
	cout<<"Ancestors of 7 are ::"<<endl;
	GetAncestors(pRoot,7);
	cout<<endl;

	cout<<endl<<"##########################################################################################################"<<endl;
	
	cout<<"CheckSumTree ::"<<IsSumTree(pRoot)<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	
	cout<<endl<<"Lowest Common Ancestor of 1 and 3 ::"<<LCA(pRoot,1,3)->data<<endl;
	cout<<endl<<"Lowest Common Ancestor of 1 and 7 ::"<<LCA(pRoot,1,7)->data<<endl;
	cout<<endl<<"Lowest Common Ancestor of 4 and 6 ::"<<LCA(pRoot,4,6)->data<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	cout<<endl<<"Tree has Path Sum 9 ::"<<hasPathSum(pRoot,9)<<endl;
	cout<<endl<<"Tree has Path Sum 100 ::"<<hasPathSum(pRoot,100)<<endl;
	cout<<endl<<"Tree has Path Sum 15 ::"<<hasPathSum(pRoot,15)<<endl;
	cout<<endl<<"##########################################################################################################"<<endl;
	
	cout<<endl<<"Subtree ::"<<IsSubTree(pRoot,pRootSub)<<endl;
	
	cout<<endl<<"##########################################################################################################"<<endl;
	return 0;
}
void AddNode(btNode** ppRoot,int data)
{
	btNode* pRoot = *ppRoot;
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
void Inorder(btNode* pRoot)
{
	if(pRoot == NULL)
		return;
	Inorder(pRoot->left);
	cout<<pRoot->data<<"\t";
	Inorder(pRoot->right);
}
void Preorder(btNode* pRoot)
{
	if(pRoot == NULL)
		return;
	cout<<pRoot->data<<"\t";
	Preorder(pRoot->left);
	Preorder(pRoot->right);
}

void Postorder(btNode* pRoot)
{
	if(pRoot == NULL)
		return;	
	Postorder(pRoot->left);
	Postorder(pRoot->right);
	cout<<pRoot->data<<"\t";
}