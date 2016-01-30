/*
 * 1_BrianDean.cpp
 *
 *  Created on: Jan 30, 2016
 *      Author: Admin
 */

//Maximum Value Contiguous Subsequence.
//Given a sequence of n real numbers A(1) ... A(n), determine a contiguous subsequence A(i) ... A(j) for which the sum of elements in the subsequence
//is maximized
#include<iostream>
using namespace std;
int arr[9] = {-2,-4,-2,-5,-7,-10,-1, -11,-13};
int dp[9];
int f()
{

	int nSize = sizeof(arr)/sizeof(int);
	dp[0] = arr[0];
	int maxsum = dp[0];
	for(int i = 1 ; i < nSize; i++)
	{
		dp[i] = max(arr[i] + max(arr[i-1],dp[i-1]),arr[i]);
		if(maxsum < dp[i])
		{
			maxsum = dp[i];
		}
	}
	return maxsum;
}
int main()
{
	cout<<"Maximun Value Contiguous Subsequence :: "<<f()<<endl;
	return 0;
}


//Complexity : O(n) : Linear
//Handles all negative numbers as well
