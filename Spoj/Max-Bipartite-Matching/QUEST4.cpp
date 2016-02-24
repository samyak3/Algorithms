/*
 * spoj-QUEST4-p1.cpp
 *
 *  Created on: 24-Feb-2016
 *      Author: jain.a
 */

#include<iostream>
#include<vector>
using namespace std;
#define MAX 121
vector<int>v[MAX];
int visited[MAX];
int Row[MAX];
int Column[MAX];
#define NO_COLUMN -1
#define NO_ROW -1
void resetAssignments()
{
	for(int i = 0 ; i < MAX ;i++)
	{
		Row[i]=-1;
		Column[i]=-1;
	}
}
void resetv()
{
	for(int i = 0 ; i < MAX ; i++)
	{
		v[i].clear();
	}
}
void resetVisited()
{
	for(int i = 0 ; i < MAX;i++)
	{
		visited[i]=0;
	}
}
bool AssignColumn(int row)
{
	if(visited[row])
		return false;
	visited[row]=1;

	for(int i = 0 ; i < v[row].size(); i++)
	{
		int column = v[row][i];
		if(Row[column] == -1)
		{
			Row[column] = row;
			Column[row] = column;
			return true;
		}
	}
	for(int i = 0 ; i < v[row].size(); i++)
	{
		int column = v[row][i];
		if(AssignColumn(Row[column]))
		{
			Row[column] = row;
			Column[row] = column;
			return true;
		}
	}
	return false;
}
void process()
{
	bool bAugmented = false;

	while(1)
	{
		resetVisited();
		for(int i = 0 ; i < MAX ; i++)
		{
			if(Column[i] == NO_COLUMN && AssignColumn(i))
			{
				bAugmented = true;
			}
		}
		if(bAugmented == false)
		{
			break;
		}
		bAugmented = false;
	}
	int nPlankCnt=0;
	for(int i = 0 ; i < MAX ; i++)
	{
		if(Column[i] != -1)
		{
			nPlankCnt++;
		}
	}
	cout<<nPlankCnt<<endl;
}
int main()
{
	//freopen("quest4.txt","r",stdin);

	int nRooms;

	cin >> nRooms;

	while(nRooms--)
	{
		int nTiles;
		cin >> nTiles;
		int r , c;
		resetAssignments();
		for(int i = 0; i < nTiles ; i++)
		{
			cin >> r >> c;
			v[r].push_back(c);
		}
		process();
		resetv();
	}
	return 0;
}
