/*
 * PowerSetK.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: Admin
 */

//Generate power set : all subsets of a set of size K;


#include<iostream>

#include<vector>

using namespace std;

int s[] = { 1 , 2 , 3 , 4, 5};
int size;
int K = 2;
void printV(vector<int>v)
{
	for(int i = 0 ; i < v.size() ; i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
void f(int i,vector<int>v)
{
	if(v.size() > K)
		return;
	if(i == size )
	{
		if(v.size() == K)
			printV(v);
		return;
	}

	f(i+1,v);//excluding ith item from subset

	v.push_back(s[i]);

	f(i+1,v);//inclding  ith item in  subset
}
int main()
{
	size = sizeof(s)/sizeof(int);
	vector<int>v;
	f(0,v);
	return 0;
}
