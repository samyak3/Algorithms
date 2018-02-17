/*
 * GSS1.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: Admin
 */

#include<iostream>
using namespace std;
#define MAXX 100000
typedef struct node
{
	int sum;
	int maxsum;
	int prefixsum;
	int suffixsum;
};
node seg[MAXX];
int N;
void build()
{
	int val;
	for(int i = N ; i < 2* N -1 ; i++)
	{
		cin >> val;
		seg[i].maxsum = val;
		seg[i].sum = val;
		seg[i].prefixsum = 0;
		seg[i].suffixsum = 0;
	}
	for(int parent = N -1 ; parent >= 1 ; parent--)
	{
		seg[parent].sum = seg[2*parent].sum + seg[2*parent+1].sum;
		seg[parent].prefixsum = seg[2*parent].sum + seg[2*parent+1].prefixsum;
		seg[parent].suffixsum = seg[2*parent+1].sum + seg[2*parent].suffixsum;
		seg[parent].maxsum =max(seg[parent].sum, max(max(seg[2*parent].maxsum ,seg[2*parent+1].maxsum ),max(seg[parent].prefixsum,seg[parent].suffixsum) ));
	}
}
long long query(int l , int r)
{
	l = l+N;
	r = r+N;
	long long  answer = -99999999999;
	while(l < r)
	{
		if(l&1)
		{
			answer = max(answer , seg[l].maxsum);
			l++;
		}
		if(r & 1)
		{
			r--;
			answer = max(answer,seg[r].maxsum);
		}
		l = l/2;
		r = r/2;
	}
	return answer;
}

int main()
{

}
