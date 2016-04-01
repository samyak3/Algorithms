/*
* Rook.cpp
*
*  Created on: Apr 1, 2016
*      Author: Admin
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
FILE* pistream;
vector<vector<char>>cb;
int N;
typedef struct
{
	int x;
	int y;
}Point;
void combinations();
Point GetXY(int j)
{
	Point pt;
	switch (j)
	{
	case 0:
		pt.x = 0;
		pt.y = 0;
		break;
	case 1:
		pt.x = 0;
		pt.y = 1;
		break;
	case 2:
		pt.x = 0;
		pt.y = 2;
		break;
	case 3:
		pt.x = 0;
		pt.y = 3;
		break;
	case 4:
		pt.x = 1;
		pt.y = 0;
		break;
	case 5:
		pt.x = 1;
		pt.y = 1;
		break;
	case 6:
		pt.x = 1;
		pt.y = 2;
		break;
	case 7:
		pt.x = 1;
		pt.y = 3;
		break;
	case 8:
		pt.x = 2;
		pt.y = 0;
		break;
	case 9:
		pt.x = 2;
		pt.y = 1;
		break;
	case 10:
		pt.x = 2;
		pt.y = 2;
		break;
	case 11:
		pt.x = 2;
		pt.y = 3;
		break;
	case 12:
		pt.x = 3;
		pt.y = 0;
		break;
	case 13:
		pt.x = 3;
		pt.y = 1;
		break;
	case 14:
		pt.x = 3;
		pt.y = 2;
		break;
	case 15:
		pt.x = 3;
		pt.y = 3;
		break;
	default:
		break;
	}
	return pt;
}

int cnt(vector<vector<char>>cb)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (cb[i][j] == 'R')
			{
				count++;
			}
		}
	}
	return count;
}
bool IsLegal(int x, int y, vector<vector<char>>cb)
{
	if (cb[x][y] == 'X')
		return false;

	int j = y;
	while (j >= 0)
	{
		char cp = cb[x][j];
		if (cp == 'X')
		{
			break;
		}
		else if (cp == 'R')
		{
			return false;
		}
		else
		{

		}
		j--;
	}

	j = y;
	while (j < N)
	{
		char cp = cb[x][j];
		if (cp == 'X')
		{
			break;
		}
		else if (cp == 'R')
		{
			return false;
		}
		else
		{

		}
		j++;
	}

	int i = x;
	while (i >= 0)
	{
		char cp = cb[i][y];
		if (cp == 'X')
		{
			break;
		}
		else if (cp == 'R')
		{
			return false;
		}
		else
		{

		}
		i--;
	}
	i = x;
	while (i < N)
	{
		char cp = cb[i][y];
		if (cp == 'X')
		{
			break;
		}
		else if (cp == 'R')
		{
			return false;
		}
		else
		{

		}
		i++;
	}
	return true;
}

int solve(int x, int y, vector<vector<char>>cb)
{
	if (IsLegal(x, y, cb))
	{
		if (x == N - 1 && y == N - 1)
		{
			return cnt(cb);
		}
		cb[x][y] = 'R';
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (cb[i][j] == 'R' || cb[i][j] == 'X')
					continue;
				ans = max(ans, solve(i, j, cb));
			}
		}
		return ans;
	}
	if (x == N - 1 && y == N - 1)
	{
		return cnt(cb);
	}
	return 0;
}
int main()
{
	freopen_s(&pistream, "input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector<char>row;
		char ch;
		for (int j = 0; j < N; j++)
		{
			cin >> ch;
			row.push_back(ch);
		}
		cb.push_back(row);
	}
	//recursive
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans = max(ans, solve(i, j, cb));
		}
	}
	cout << "Recursive max Rook :: " << ans << endl;

	combinations();

	return 0;
}

void combinations()
{
	unsigned totalC = 1 << (N*N);
	int ans = 0;
	int loopCnt = 0;
	for (unsigned int i = 0; i < totalC; i++)
	{
		vector<vector<char> >lcb(cb);
		bool bLegal = true;
		int lans = 0;
		for (int j = 0; j < N*N; j++)
		{
			loopCnt++;
			if (i & (1 << j))
			{
				Point pt = GetXY(j);
				if (IsLegal(pt.x, pt.y, lcb))
				{
					lcb[pt.x][pt.y] = 'R';
					lans++;
				}
				else
				{
					bLegal = false;
					break;
				}
			}
		}
		if (bLegal)
		{
			ans = max(ans, lans);
		}
	}
	cout << "loopCnt :: " << loopCnt << endl;

	cout << "Iterative  max Rook :: " << ans << endl;
}
