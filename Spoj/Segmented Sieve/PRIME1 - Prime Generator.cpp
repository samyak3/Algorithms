/*
 * SegmentedSieve.cpp
 *
 *  Created on: 01-Aug-2015
 *      Author: ankur
 */

#include <string.h>
#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;
//#define MAX 46656
#define MAX 1000000
//#define LMT 216
#define LMT 317
//#define LEN 4830
#define LEN 100000000
//#define RNG 100032
#define RNG 1000000
typedef unsigned long long ull;
ull base[MAX/64], segment[RNG/64], primes[LEN];
ull C;
struct range
{
	ull l;
	ull h;
};
vector<range> ivrange;
#define sq(x) ((x)*(x))
#define mset(x,v) memset(x,v,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

/* Generates all the necessary prime numbers and marks them in base[]*/
void sieve()
{
	ull i, j, k;
	for(i=3; i<LMT; i+=2)
	{
		if(!chkC(base, i))
		{
			for(j=i*i, k=i<<1; j<MAX; j+=k)
			{
				setC(base, j);
			}
		}
	}
	for(i=3, j=0; i<MAX; i+=2)
	{
		if(!chkC(base, i))
		{
			primes[j++] = i;
		}
	}
}

/* Returns the prime-count within range [a,b] and marks them in segment[] */
//int segmented_sieve(int a, int b)
void segmented_sieve(ull a, ull b)
{
	ull i, j, k;//, cnt = (a<=2 && 2<=b)? 1 : 0;
	if(b<2)
	{
		return;// 0;
	}
	if(a<3)
	{
		a = 3;
	}
	if(a%2==0)
	{
		a++;
	}
	mset(segment,0);
	for(i=0; sq(primes[i])<=b; i++)
	{
		j = primes[i] * ( (a+primes[i]-1) / primes[i] );
		if(j%2==0)
		{
			j += primes[i];
		}
		for(k=primes[i]<<1; j<=b; j+=k)
		{
			if(j!=primes[i])
			{
				setC(segment, (j-a));
			}
		}
	}
	for(i=0; i<=b-a; i+=2)
	{
		if(!chkC(segment, i))
		{
			cout<<a+i<<endl;
			//cnt++;
		}
	}
	cout<<endl;
	//return cnt;
}
int main()
{
	//freopen("input","r",stdin);
	ull  L , H;
	cin >> C;
	range stRange;
	for(ull c = 1 ; c <= C ; c++)
	{
		cin >> L >> H;
		stRange.l = L;
		stRange.h = H;
		ivrange.push_back(stRange);
	}
	sieve();
	for(ull c = 0 ; c < C ; c++)
	{
		ull a = ivrange[c].l;
		ull b = ivrange[c].h;
		if(a<=2)
		{
			cout<<2<<endl;
		}
		segmented_sieve(a,b);
	}
	return 0;
}

