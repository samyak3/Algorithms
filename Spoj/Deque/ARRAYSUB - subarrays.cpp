/*
 * ARRAYSUB - subarrays.cpp
 *
 *  Created on: Oct 25, 2015
 *      Author: Admin
 */

#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int>v;
int N;
int K;

int main()
{
	cin >> N;
	int num;
	for(int n = 1 ; n <= N ; n++)
	{
		cin >> num;
		v.push_back(num);
	}
	cin >> K;
	deque<int>q;//queue must have the index of max num as the front element-> descending order arrangement !!

	for(int i = 0 ; i < K ; i++)
	{
		while((q.empty() == false) && (v[i] >= v[q.back()]))
			q.pop_back();
		q.push_back(i);
	}


	for(int i = K ;i < N ;i++)
	{
		cout<<v[q.front()]<<" ";
		while((q.empty() == false )&& (i - K >= q.front()))//sliding window !!
			q.pop_front();
		while((q.empty() == false) && (v[i] >= v[q.back()]))
			q.pop_back();

		q.push_back(i);

	}


	cout<<v[q.front()];
}
