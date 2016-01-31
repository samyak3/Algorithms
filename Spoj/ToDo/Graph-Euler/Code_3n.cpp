/*
 * Code_3n.cpp
 *
 *  Created on: Nov 3, 2015
 *      Author: Admin
 */

#include<iostream>
#include<string.h>
using namespace std;
int c[10][10][10] ;
int f[10];
void dfs(int s1,int s2);
int N;

int main()
{
	for(int i = 0 ; i <= 9; i++)
		for(int j = 0 ; j <= 9; j++)
			for(int k = 0 ; k <= 9; k++)
				c[i][j][k] =0;

	for(int j = 0 ; j <= 9; j++)
		f[j]=100;
	cout<<0;
	dfs(0,0);

	cout<<endl<<"DONE!!"<<endl;

	return 0;
}
void dfs(int s1,int s2)
{
	if(f[s1] == 0)
	{
		return;
	}
	else
	{
		cout<<s2;
		for(int d = 0 ;d <= 9; d++ )
		{
			if(c[s1][s2][d] == 0)
			{
				c[s1][s2][d]++;
				f[s1]--;
				dfs(s2,d);
			}
		}
	}
}
