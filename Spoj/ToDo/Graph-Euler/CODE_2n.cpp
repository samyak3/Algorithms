/*
 * CODE.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author: Admin
 */

#include<iostream>
#include<string.h>
using namespace std;
int c[10][10] ;
int f[10];
void dfs(int s);
int N;
int main()
{
	for(int i = 0 ; i <= 9; i++)
		for(int j = 0 ; j <= 9; j++)
			c[i][j] =1;

	for(int j = 0 ; j <= 9; j++)
		f[j]=10;

	dfs(0);

	cout<<"DONE!!"<<endl;

	return 0;
}
void dfs(int s)
{
	if(f[s] == 0)
	{
		return;
	}
	else
	{
		cout<<s;
		for(int d = 0 ;d <= 9; d++ )
		{
			if(c[s][d])
			{
//				cout<<"s : " <<s<<" d : "<<d<<"c[s][d] : " <<c[s][d]<<endl;
				c[s][d]--;
				f[s]--;
				dfs(d);
			}
		}
	}
}
