/*
 * IWGBS - 0110SS.cpp
 *
 *  Created on: Oct 31, 2015
 *      Author: Admin
 */

#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long ull;
vector<ull>Wzero;//number of ways we can make a number from 1 and 0 which ends with zero
vector<ull>Wone;//number of ways we can make a number from 1 and 0 which ends with one

int N;

int main()
{
	cin >> N ;
	for(int i = 0; i <= N ; i++)
	{
		Wzero.push_back(0);
		Wone.push_back(0);
	}
	Wzero[1] = 1;
	Wone[1]  = 1;

	for(int i = 2 ; i <= N ; i++)
	{
		Wzero[i] = Wone[i-1];
		Wone[i] = Wone[i-1] + Wzero[i-1];
	}
	cout<<Wzero[N] + Wone[N]<<endl;
}
