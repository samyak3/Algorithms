#include"graph.h"
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int ma[7][7] = {
	999, 1, 1, 999, 999, 999, 999,
	1, 999, 2, 1, 1, 999, 999,
	1, 2, 999, 999, 999, 1, 1,
	999, 1, 999, 999, 2, 999, 999,
	999, 1, 999, 2, 999, 999, 999,
	999, 999, 1, 999, 999, 999, 2,
	999, 999, 1, 999, 999, 2, 999
};
int mincost=0;

int min = 999;

int parent[8];

typedef struct edje
{
	int u;
	int v;
	int d;
}Edje;

void updatearrEdjes();
void 	findMST();
vector<Edje> vecEdje;
vector<Edje> mstEdje;

int findset(int x)
{
	while(parent[x])
	{
		x = parent[x];	
	}
	return x;
}

int unionfunc(int x , int y)
{
	if(x != y)
	{
		parent[y] = x;
		return 1;
	}
	return 0;
}
class edjeComp
{
	public:
		bool operator()(Edje a, Edje b)
		{
			return a.d < b.d;
		}
};
void KMST()
{
	updatearrEdjes();

	sort(vecEdje.begin(), vecEdje.end(), edjeComp());

	findMST();
}
void updatearrEdjes()
{
	for(int i = 0; i < 7 ; i++)
	{
		for(int j = 0; j < 7 ; j++)
		{
			Edje e;
			e.u = i+1;
			e.v = j+1;
			e.d = ma[i][j];
			if(ma[i][j] != 999)
				ma[j][i] = 999;
			vecEdje.push_back(e);
		}
	}
}
void findMST()
{
	int n = 0;
	vector<Edje>::iterator iter = vecEdje.begin();

	for(iter = vecEdje.begin(); iter != vecEdje.end(); iter++)
	{
		if(n >= 7)
			break;
		if(findset(iter->u) != findset(iter->v))
		{
			mstEdje.push_back(*iter);
			mincost += iter->d;
			n++;
			unionfunc(iter->u,iter->v);
		}	
	}
		cout<<endl<<"edjes of mst are :: "<<endl<<endl;
		vector<Edje>::iterator mstiter = mstEdje.begin();
		for(mstiter = mstEdje.begin(); mstiter != mstEdje.end(); mstiter++)
		{
			cout<<"u = "<<mstiter->u<<"  v = "<<mstiter->v<<" d = "<<mstiter->d<<endl;
		}
		cout<<"parent :: "<<endl;
		for(int p = 1; p <= 7 ; p++)
		{
			cout<<"parent of "<<p<<" is "<<parent[p]<<endl;
		}
		cout<<"weight of mst is :: "<<mincost<<endl<<endl;
		
}

