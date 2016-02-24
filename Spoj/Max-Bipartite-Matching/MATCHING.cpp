/*
 * MATCHING-p1.cpp
 *
 *  Created on: 24-Feb-2016
 *      Author: jain.a
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 50001
#define INF (1<<28)
#define NIL 0
int dist[MAX];
int nCows , nBulls, P;
int Cow[MAX];
int Bull[MAX];
vector<int>v[MAX];
bool Augment()
{
	queue<int>q;
	for(int i = 1 ; i <= nCows ; i++)
	{
		if(Bull[i] == 0)
		{
			dist[i]=0;
			q.push(i);
		}
		else
		{
			dist[i]=INF;
		}
	}
	dist[NIL]=INF;

	while(q.empty() == false)
	{
		int nCowNumber = q.front();
		q.pop();
		for(int i = 0 ; i < v[nCowNumber].size(); i++)
		{
			int BullNumber = v[nCowNumber][i];
			int CowAssigned = Cow[BullNumber];
			if(dist[CowAssigned] == INF)
			{
				dist[CowAssigned] = dist[nCowNumber]+1;//CowAssigned should pair again to result in augmentation if possible
				q.push(CowAssigned);
			}
		}
	}
	if(dist[NIL] != INF)//This means an augmenting path was found , such a path will actually end at NIL node and hence the dist wont be INF
	{
		return true;
	}
	else
	{
		return false;//No path found
	}
}
bool Assign(int nCowNumber)//we will assign a new partner to nCowNumber
{
	if(nCowNumber != NIL)
	{
		for(int i = 0 ; i < v[nCowNumber].size();i++)
		{
			int nBullNumber = v[nCowNumber][i];
			if(dist[Cow[nBullNumber]] == dist[nCowNumber] + 1)
			{
				if(Assign(Cow[nBullNumber]))
				{
					Bull[nCowNumber] = nBullNumber;
					Cow[nBullNumber] = nCowNumber;
					return true;
				}
			}
		}
		dist[nCowNumber]= INF;
		return false;
	}
	return true;
}
void Hopcroft_Karp()
{
	int nMatchCount=0;
	while(Augment())
	{
		for(int i = 1 ; i<= MAX; i++ )
		{
			if(Bull[i] == 0 && Assign(i))
			{
				nMatchCount++;
			}
		}
	}
	cout<<nMatchCount<<endl;
}

int main()
{
//	freopen("matching.txt","r",stdin);
	cin >> nCows >> nBulls >> P;
	int nCowNumber , nBullNumber;
	for(int i = 1; i <= P ; i++)
	{
		cin >> nCowNumber >> nBullNumber;
		v[nCowNumber].push_back(nBullNumber);
	}
	Hopcroft_Karp();
	return 0;
}
