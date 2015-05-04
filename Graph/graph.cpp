#include<iostream>
#include<vector>
#include<queue>
#include"graph.h"

using namespace std;

int visited[7];

Node* a[7];
Node* pHead= NULL;
Node* getNode(int data)
{
	Node* pNode = new Node;
	pNode->data = data;
	pNode->next = NULL;
	return pNode;
}
void bfs(Node*);
int main()
{
	Node *v1, *v2, *v3,*v4;
	v1 = getNode(1);
	v2 = getNode(2);
	v3 = getNode(3);
	a[0] = v1;
	pHead = v1;
	v1->next = v2;
	v2->next = v3;

	v1 = getNode(1);
	v2 = getNode(2);
	v3 = getNode(4);
	v4 = getNode(5);
	v2->next= v1;
	v1->next = v3;
	v3->next = v4;
	a[1] = v2;

	v1 = getNode(1);
	v2 = getNode(3);
	v3 = getNode(6);
	v4 = getNode(7);
	v2->next= v1;
	v1->next = v3;
	v3->next = v4;
	a[2] = v2;

	v1 = getNode(4);
	v2 = getNode(2);
	v1->next= v2;
	a[3] = v1;	

	v1 = getNode(5);
	v2 = getNode(2);
	v1->next= v2;
	a[4] = v1;	


	v1 = getNode(6);
	v2 = getNode(3);
	v1->next= v2;
	a[5] = v1;	
	v1 = getNode(7);
	v2 = getNode(3);
	v1->next = v2;
	a[6] = v1;	
	cout<<"bfs traversal ::"<<endl;
	bfs(pHead);
	cout<<endl<<"##########################################################################################################"<<endl;
	cout<<endl<<"dfs traversal ::"<<endl;
	dfs(pHead);
	cout<<endl<<"##########################################################################################################"<<endl;
	return 0;
}
