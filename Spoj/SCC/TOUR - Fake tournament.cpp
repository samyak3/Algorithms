/*
 * TOUR.cpp
 *
 *  Created on: 08-Aug-2015
 *      Author: ankur
 */


#include<iostream>
#include<stdio.h>
#include<stack>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
enum Color
{
	WHITE,
	GRAY,
	BLACK,
};

typedef unsigned un;
struct node
{
	int data;
	Color eColor;
	node()
	{
		eColor = WHITE;
	}
};
vector< vector<node> >g;
vector< vector<node> >gt;
vector< int> vscc;
vector< int> gvscc;
set<int>sccset;

bool bPossible = true;
un C,N,E;

stack<int> gstack;
void scc();
void dfs(int source);
void dfst(int source);
void vcleanup();
void findBottom();
void outB();
int main()
{
	//freopen("input","r",stdin);
	cin >> C;
	for(un c = 1; c<=C;c++)
	{
		cin >> N ;
		vcleanup();
		for(un p = 1; p <= N ; p++)
		{
			un nBetter;
			cin >> nBetter;
			for(un b = 1 ; b <= nBetter ; b++)
			{
				un d ;
				cin >> d;
				node tnode;
				tnode.data = d;
				gt[p].push_back(tnode);
				tnode.data = p;
				g[d].push_back(tnode);
			}
		}
		scc();
		outB();
		cout<<endl;
	}
}

void vcleanup()
{
	bPossible = true;
	gvscc.clear();
	sccset.clear();
	vscc.clear();
	g.clear();
	gt.clear();
	for(unsigned i = 0; i <= N; i++)
	{
		node tnode;
		tnode.data = i;
		vector<node> v;
		v.push_back(tnode);
		g.push_back(v);
		gt.push_back(v);
	}
}
void dfs(int source)
{
	g[source][0].eColor = GRAY;

	for(unsigned i = 1 ; i < g[source].size();i++)
	{
		int next = g[source][i].data;
		if(g[next][0].eColor == WHITE)
		{
			dfs(next);
		}
	}
	g[source][0].eColor = BLACK;

	gstack.push(source);
}
void dfst(int source)
{
	gt[source][0].eColor = GRAY;
	vscc.push_back(source);
	sccset.insert(source);
	for(unsigned i = 1 ; i < gt[source].size();i++)
	{
		int next = gt[source][i].data;
		if(gt[next][0].eColor == WHITE)
		{
			dfst(next);
		}
	}
	gt[source][0].eColor = BLACK;
}
void scc()
{
	for(unsigned i = 1; i <= N ; i++)
	{
		if(g[i][0].eColor == WHITE)
		{
			dfs(i);
		}
	}
	while(gstack.empty() == false)
	{
		int top = gstack.top();
		if(gt[top][0].eColor == WHITE)
		{
			dfst(top);
		}
		findBottom();
		gstack.pop();
	}
}
void findBottom()
{
	bool bBottom = true;
	for(unsigned i = 0; i < vscc.size(); i++)
	{
		int nv = vscc[i];
		for(unsigned j = 1 ; j < gt[nv].size(); j++)
		{
			int ng = gt[nv][j].data;
			if(sccset.find(ng) == sccset.end() )
			{
				bBottom = false;
				break;
			}
		}
		if(bBottom == false)
		{
			break;
		}
	}
	if(bBottom && gvscc.size() && vscc.size())
	{
		bPossible = false;
	}
	if(bBottom)
	{
		for(unsigned i = 0 ; i < vscc.size(); i++)
		{
			gvscc.push_back(vscc[i]);
		}
	}
	vscc.clear();
	sccset.clear();
}
void outB()
{
	if(!bPossible)
	{
		cout<<0;
		return ;
	}
		cout<<gvscc.size();
}
