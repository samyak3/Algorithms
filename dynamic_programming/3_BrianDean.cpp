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
		if(s.insert(A[i]).second)
		{
			it = s.find(A[i]);
			it++;
			if(it != s.end())
			{
				s.erase(it);
			}
		}
	}
	return s.size();
}
int GetNextGreaterElementIndex(int arr[],int arrlen , int key)
{
	int left = 0;
	int right = arrlen - 1;
	int mid ;
	while(right > left)
	{
		mid = left + (right-left)/2 ;
		if(key >= arr[mid])
		{
			left = mid+1;
		}
		else
		{
			right = mid;
		}
	}
	return right;
}
int LIS(int arr[],int arraylen)
{
	int len = 0;

	int* longestSequence = new int[arraylen];

	longestSequence[len] = arr[0];
	len++;
	for(int i = 1; i < arraylen; i++)
	{
		if(arr[i] < longestSequence[0])
		{
			longestSequence[0] = arr[i];//new smallest element of longest sequence
		}
		else if(arr[i] > longestSequence[len-1])
		{
			longestSequence[len++] = arr[i] ;//extent the longest sequence
		}
		else
		{
			int key = arr[i];
			int indexForReplacing = GetNextGreaterElementIndex(longestSequence,len,key);
			longestSequence[indexForReplacing] = arr[i];
		}
	}
	return len;
}
int main()
{
	int arr[] = { -7 ,10 ,9 ,2 ,3 ,8 ,8 ,1};

	int arraylen = sizeof(arr)/sizeof(int);

	vector<int>v(arr,arr+sizeof(arr)/sizeof(int));

	cout<<"LIS length :: "<<LIS(v)<<endl;//using std::set

	cout<<"LIS length :: "<<LIS(arr,arraylen)<<endl;//using binary search

	return 0;
}
//Complexity : O(nlogn)
