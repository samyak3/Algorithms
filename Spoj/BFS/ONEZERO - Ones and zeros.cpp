/*
 * ONEZERO.cpp
 *
 *  Created on: 03-Aug-2015
 *      Author: ankur
 */
#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N;
struct node
{
	node* p;
	char c;
	int v;
	node()
	{
		v = 0;
	}
};
node* root = NULL;
int C;
int main()
{
	//freopen("input","r",stdin);
	cin >> C;

	for(int i = 1; i <= C; i++)
	{
		cin >> N;
		queue<node*> q;
		node* one = new node;
		one->c = '1';
		one->v=1;
		one->p = NULL;
		q.push(one);
		node* fnode;
		string answer;
		while(!q.empty())
		{
			fnode = q.front();
			if(fnode->v % N == 0)
			{
				while(fnode)
				{
					answer = answer + fnode->c;
					fnode = fnode->p;
				}
				break;
			}
			else
			{
				node* n = new node;
				n->c= '0';
				n->v = (fnode->v % N) * 10;
				n->p = fnode;
				q.push(n);
				node* nn = new node;
				nn->c = '1';
				nn->v = (fnode->v % N) * 10 +1;
				nn->p = fnode;
				q.push(nn);
			}
			q.pop();
		}
		reverse(answer.begin(),answer.end());
		cout<<answer<<endl;
	}
	return 0;
}
