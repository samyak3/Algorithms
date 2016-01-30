/*
 * 2_BrianDean.cpp
 *
 *  Created on: Jan 30, 2016
 *      Author: Admin
 */

//Making Change.
//You are given n types of coin denominations of values v(1) < v(2) < ... < v(n) (all integers).
//Assume v(1) = 1, so you can always make change for any amount of money C.
//Give an algorithm which makes change for an amount of money C with as few coins as possible.


#include<iostream>

using namespace std;

#define MAXX 99999

int C;//amount

int dp[1000];

int coins[] = { 1,2,3,5,10,50,100};

int f()
{
	int numCoins = sizeof(coins)/sizeof(int);

	dp[0] = 0;

	for(int a = 1 ; a <= C ; a++ )
	{
		dp[a] = MAXX;
		int nCoinsNeeded = MAXX;
		for(int i = 0 ;i < numCoins ; i++ )
		{
			if(coins[i] > a)
			{
				break;
			}
			nCoinsNeeded = 1 + dp[a - coins[i]];
			if(nCoinsNeeded < dp[a])
			{
				dp[a] = nCoinsNeeded;
			}
		}
	}
	return dp[C];
}
int main()
{
	C = 256;
	cout<<"Minimum number of coins needed for making change for amount "<<C<<" are :: "<<f()<<endl;
	return 0;
}
