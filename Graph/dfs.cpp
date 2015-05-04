#include"graph.h"
#include<iostream>
using namespace std;
int dvisited[7];
extern Node* a[7];
void dfs(Node* pNode)
{
	if(pNode == NULL || dvisited[pNode->data-1])
		return;
	//cout<<"dfs called for "<<pNode->data<<endl;
	pNode = a[pNode->data-1];
	while(pNode->next)
	{
		dvisited[pNode->data-1]=1;
		int d = pNode->data-1;
		cout<<d+1<<"\t";
		dvisited[d] = 1;
		while(pNode->next != NULL)
		{
			pNode = pNode->next;
			dfs(pNode);
		}
	}
}
