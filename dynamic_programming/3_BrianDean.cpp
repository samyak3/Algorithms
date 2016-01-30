/*
 * 3_BrianDean.cpp
 *
 *  Created on: Jan 30, 2016
 *      Author: Admin
 */

//Longest Increasing Subsequence.
//Given a sequence of n real numbers A(1) ... A(n),
//determine a subsequence (not necessarily contiguous) of maximum length in which the values in the subsequence form a strictly increasing sequence

#include<iostream>
#include<set>
#include<vector>
using namespace std;

int LIS(vector<int> A)
{
	int vsize = A.size();
	set<int>s;
	set<int>::iterator it;
	for(int i = 0 ; i < vsize; i++)
	{
		if(s.insert(A[i].second))
		{
			it = s.find(A[i]);
			it++;
			if(it != s.end())
			{
				s.erase(k);
			}
		}
	}
	return s.size();
}
int main()
{
	int arr[] = { -7 ,10 ,9 ,2 ,3 ,8 ,8 ,1};
	vector<int>v(arr,arr+sizeof(arr)/sizeof(int));
	cout<<"LIS lenght :: "<<LIS(v)<<endl;
	return 0;
}
