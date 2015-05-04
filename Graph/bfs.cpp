#include"graph.h"
#include<iostream>
#include<queue>
using namespace std;
int bvisited[7];
extern Node* a[7];

void bfs(Node* pNode)
{
	if(pNode == NULL)
		return;
	queue<Node*> q;
	pNode = a[pNode->data-1];
	q.push(pNode);
	while(!q.empty())
	{

		int d = q.front()->data -1;
		cout<<q.front()->data<<"\t";
		bvisited[d] = 1;
		while(pNode->next != NULL)
		{
			if(bvisited[pNode->next->data -1] == 0)
				q.push(pNode->next);
			pNode = pNode->next;
		}
		q.pop();
		if(!q.empty())
			pNode = a[q.front()->data -1];
	}
}

