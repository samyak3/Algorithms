/*
 * STAR3CAS.cpp
 *
 *  Created on: Oct 15, 2015
 *      Author: Admin
 */

#include<queue>
#include<iostream>
using namespace std;
int C;
int N;
typedef struct node
{
	int data;
	int dis;
	node()
	{
		data = 0;
		dis = 0;
	}
};
node g[25][3];
bool visited[25]= {false};
int nCount[25];
void resetG()
{
	node n;
	for(int i = 0 ; i <= N + 1; i++)
	{
		for(int j = 0 ;  j <= nCount[i]; j++)
		{
			g[i][j] = n;
		}
		nCount[i]=0;
		visited[i]= false;
	}
}
int bfs()
{
	g[1][0].dis = 0;
	queue<int>q;
	q.push(1);
	visited[1]=true;
	bool bSolution = false;
	while(q.empty() == false)
	{
		int parent = q.front();
		
		for(int i = 1 ; i <= nCount[parent];i++)
		{
			int next = g[parent][i].data;
			if(next ==  N + 1)
			{
				g[N+1][0].dis = g[parent][0].dis + 1;
				//cout<<"dis for "<<next<<" is :: "<<g[next][0].dis <<endl;
				bSolution = true;
				break;
			}
			if(visited[next] == false)
			{
				g[next][0].dis = g[parent][0].dis + 1;
				//cout<<"dis for "<<next<<" is :: "<<g[next][0].dis <<endl;
				visited[next]=true;
				q.push(next);
			}
		}
		if(bSolution)
			break;
		q.pop();
	}
	if(bSolution)
		return g[N+1][0].dis;
	else
		return -1;
}
int main()
{
	cin >> C;
	for(int c = 1 ; c <= C ; c++)
	{
		cin >> N;
		int jump;
		node tnode;
		for(int n = 1 ; n <= N ; n++)
		{
			tnode.data = n;
			g[n][0]=tnode;
			tnode.data = n+1;
			g[n][1]=tnode;
			nCount[n]=1;
			cin >> jump;
			if(n+jump <= N+1 && n+jump >0)
			{
				tnode.data = n+jump;
				g[n][2]= tnode;
				nCount[n]++;
			}
		}
		int moves = bfs();
		cout<<moves<<endl;
		resetG();
	}

}
