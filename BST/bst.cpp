#include<iostream>
using namespace std;


struct node
{
	int d;
	struct node* left;
	struct node* right;
};
typedef struct node* Node;
typedef struct node objNode;

Node pRoot = NULL;

void insert(Node*,int);
void inorder(Node);
void preorder(Node);
void postorder(Node);
int getMin(Node);
int getMax(Node);
Node getNode(int d)
{
	Node ptr = new objNode;
	ptr->d=d;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}
int main()
{
	insert(&pRoot,5);
	insert(&pRoot,7);
	insert(&pRoot,3);
	insert(&pRoot,4);
	insert(&pRoot,2);
	insert(&pRoot,1);
	insert(&pRoot,6);
	insert(&pRoot,8);
	cout<<"inorder ::"<<endl;
	inorder(pRoot);
	cout<<endl;
	cout<<"postorder ::"<<endl;
	postorder(pRoot);
	cout<<endl;
	cout<<"preorder ::"<<endl;
	preorder(pRoot);
	cout<<endl;
	cout<<"min ---"<<getMin(pRoot);
	cout<<endl;
	cout<<"max ---"<<getMax(pRoot);
	cout<<endl;
	return 0;
}
void insert(Node* p,int d)
{
	if(*p == NULL)
	{
		*p = getNode(d);
		return;
	}
	Node ptr = *p;
	if(ptr->d > d)
	{
		insert(&(ptr->left),d);
	}
	else
	{
		insert(&(ptr->right),d);
	}		
}
void inorder(Node p)
{
	if(p)
	{
		inorder(p->left);
		cout<<p->d<<"\t";
		inorder(p->right);
	}	
}
void preorder(Node p)
{
	if(p)
	{
		cout<<p->d<<"\t";
		preorder(p->left);
		preorder(p->right);
	}	
}
void postorder(Node p)
{
	if(p)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->d<<"\t";
	}	
}
int getMin(Node p)
{
	if(p == NULL)
	{
		return -1;
	}
	while(p->left)
	{
		p = p->left;
	}
	return p->d;
}
int getMax(Node p)
{
	if(p == NULL)
	{
		return -1;
	}
	while(p->right)
	{
		p = p->right;
	}
	return p->d;
}
