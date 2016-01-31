/*
 * SUBSUMS.cpp
 *
 *  Created on: Oct 20, 2015
 *      Author: Admin
 */
/*
Q. Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN (-20,000,000 ≤ Si ≤ 20,000,000),
determine how many subsets of S (including the empty one)
have a sum between A and B (-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.
Input
The first line of standard input contains the three integers N, A, and B. The following N lines contain S1 through SN, in order.
Output
Print a single integer to standard output representing the number of subsets satisfying the above property.
Note that the answer may overflow a 32-bit integer.
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
typedef long long ll;
vector<ll>leftSum;
vector<ll>rightSum;
vector<ll>::iterator lowerIter,higherIter;
ll a[35];
int N;
ll A;
ll B;
ll fskip(int index , ll sum);//fs -- > f skip

ll finclude(int index , ll sum);

void fIncludeSumRight(int index , int sum);

void fSkipSumRight(int index , int sum);

void fIncludeSumLeft(int index , int sum);

void fSkipSumLeft(int index , int sum);

ll fskip(int index , ll sum)//fs -- > f skip
{
	if(index == N+1)
	{
		return 0;
	}
	return finclude(index+1,sum+a[index]) + fskip(index+1,sum);
}

//2^34 operations : results in TLE
ll finclude(int index , ll sum)//f --> f inclusive
{
	if(index == N+1)
	{
		if((sum >= A) && (sum <= B))
		{
			return 1;
		}
		return 0;
	}
	if((sum >= A) && (sum <= B))
	{
		return 1 +	finclude(index+1,sum+a[index]) + fskip(index+1,sum);
	}
	else
		return finclude(index+1,sum+a[index]) + fskip(index+1,sum);
}

int main()
{
	cin >> N;
	cin >> A;
	cin >> B;
	ll numm ;
	for(int i = 1 ; i <= N ; i++)
	{
		cin >> numm;
		a[i] = numm;
	}
#if 0
	ll ans = finclude(1,0);//TLE approach
#else
	fIncludeSumLeft(1,0);

	fIncludeSumRight(N/2+1,0);

	sort(rightSum.begin(),rightSum.end());

	ll subsetCount = 0;

	for(int i=0;i<leftSum.size();i++)
	{
		lowerIter=lower_bound(rightSum.begin(),rightSum.end(),A-leftSum[i]);
		higherIter=upper_bound(rightSum.begin(),rightSum.end(),B-leftSum[i]);
		subsetCount+=(higherIter-rightSum.begin())-(lowerIter-rightSum.begin());
	}
#endif
	cout<<subsetCount<<endl;
	return 0;
}

void fSkipSumLeft(int index , int sum)
{
	if(index == N/2+1)
	{
		return ;
	}
	fIncludeSumLeft(index+1,sum+a[index]);

	fSkipSumLeft(index+1,sum);
}

void fIncludeSumLeft(int index , int sum)
{
	if(index == N/2+1)
	{
		leftSum.push_back(sum);
		return ;
	}

	leftSum.push_back(sum);

	fIncludeSumLeft(index+1 , sum+a[index]) ;

	fSkipSumLeft(index+1,sum);
}

void fSkipSumRight(int index , int sum)
{
	if(index == N+1)
	{
		return ;
	}
	fIncludeSumRight(index+1,sum+a[index]);
	fSkipSumRight(index+1,sum);
}

void fIncludeSumRight(int index , int sum)
{
	if(index == N+1)
	{
		rightSum.push_back(sum);
		return ;
	}

	rightSum.push_back(sum);

	fIncludeSumRight(index+1 , sum+a[index]) ;

	fSkipSumRight(index+1,sum);
}
