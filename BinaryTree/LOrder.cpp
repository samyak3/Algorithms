#include"Tree.h"
#include<queue>
void LOrder(btNode* pRoot)
{
	queue<btNode*>q;
	if(pRoot)
	q.push(pRoot);
	while(!q.empty())
	{
		btNode* tempNode = q.front();
		cout<<q.front()->data<<"\t";
		if(tempNode->left)
			q.push(tempNode->left);
		if(tempNode->right)
			q.push(tempNode->right);
		q.pop();
	}
}