#include<iostream>
using namespace std;


typedef struct node
{
int d;
struct node* nxt;
}Node;

Node* pHead = NULL;

void append(int);
void traverse();
void deleteNode(Node*);
void iterative_reverse();
Node* recursive_reverse(Node*);
Node* tptr = NULL;
Node* getNode(int d)
{
	Node* ptr = new Node;
	ptr->d=d;
	ptr->nxt=NULL;
	return ptr;
}
int main()
{
	append(1);
	append(2);
	append(3);
	append(4);
	append(5);
	append(6);
	append(7);
	append(8);
	append(9);
	append(10);
	append(11);

	traverse();
	cout<<endl;
	cout<<endl;
	//	deleteNode(tptr);
	//	deleteNode(pHead);
	iterative_reverse();

	traverse();

	cout<<endl;

	Node* ptrl=	recursive_reverse(pHead);
	ptrl->nxt = NULL;
	cout<<endl;
	traverse();
	cout<<endl;
	return 0;
}
void append(int d)
{
	if(pHead == NULL)
	{
		pHead = getNode(d);
		return;
	}
	Node* ptr = pHead;
	while(ptr->nxt != NULL)
	{
		ptr = ptr->nxt;
	}
	ptr->nxt=getNode(d);
	if(d == 4)
		tptr = ptr->nxt;
}
void traverse()
{
	Node* ptr = pHead;
	while(ptr)
	{
		cout<<ptr->d<<"\t";
		ptr = ptr->nxt;
	}	
}
void deleteNode(Node* pNode)
{
	Node* ptr1 = pHead;
	Node* ptr2 = ptr1->nxt;
	if(ptr1 == pNode)
	{
		pHead = ptr1->nxt;
		delete ptr1;
		return;
	}
	while(ptr2)
	{
		if(ptr2 == tptr)
		{
			ptr1->nxt = ptr2->nxt;
			delete ptr2;
			return;
		}
		ptr1 = ptr2;
		ptr2= ptr2->nxt;	
	}
}
void iterative_reverse()
{
	Node* ptr1;
	Node* ptr2 ;
	Node* ptr3; 
	if(pHead)
	{
		ptr1 = pHead;
		ptr2 = ptr1->nxt;
		if(ptr2 == NULL)
		{
			return;
		}
		else
		{
			ptr1->nxt=NULL;
			ptr3 = ptr2->nxt;
		}

	}
	while(ptr3)
	{
		ptr2->nxt = ptr1;
		ptr1=ptr2;
		ptr2 = ptr3;
		ptr3=ptr3->nxt;
	}	
	pHead = ptr2;
	ptr2->nxt = ptr1;
}	

Node* recursive_reverse(Node* pNode)
{
	if(pNode->nxt)
	{
		Node* ptr = recursive_reverse(pNode->nxt);
		ptr->nxt = pNode;
		return pNode;
	}
	else
	{
		pHead = pNode;
		return pNode;
	}
}
