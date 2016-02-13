#include<iostream>
using namespace std;


typedef struct node
{
	int d;
	struct node* nxt;
}Node;

Node* pHead = NULL;
void printInReverseOrder(Node* pNode)
{
	if(pNode == 0)
	{
		return;
	}
	printInReverseOrder(pNode->nxt);
	cout<<pNode->d<<" ";
}
void rreverse(Node** pHead,Node* pNode)
{
	if(*pHead == 0 || (*pHead)->nxt == 0)
	{
		return; //empty linked list or single node list
	}
	if(pNode->nxt == 0)
	{
		*pHead = pNode;//last node of the original list now becomes the head of reversed linked list
		return;
	}
	else
	{
		rreverse(pHead,pNode->nxt);
		pNode->nxt->nxt = pNode;
		pNode->nxt = 0;
	}
}
