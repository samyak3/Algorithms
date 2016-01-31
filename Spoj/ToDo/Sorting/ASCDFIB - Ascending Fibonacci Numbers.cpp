/*
 * ASCDFIB - Ascending Fibonacci Numbers.cpp
 *
 *  Created on: Oct 25, 2015
 *      Author: Admin
 */

#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long ull;
ull C;
ull A , B;
#define MAXX 2100002
vector<ull>dpfib;
vector<ull>ans;
void bottomup()
{
	for(ull i = 1 ; i <= MAXX; i++ )
	{
		dpfib.push_back(0);
	}
	dpfib[1] = 0;
	dpfib[2] = 1;
	for(ull i = 3 ; i <= MAXX; i++ )
	{
		dpfib[i] = (dpfib[i-1] + dpfib[i-2]) % 100000;
	}
}
void resetans()
{
	ans.clear();
	for(ull i = 1 ; i <= MAXX; i++ )
	{
		ans.push_back(0);
	}

}
int main()
{
	cin >> C;
	bottomup();
	for(ull c = 1 ; c <= C ; c++)
	{
		cin >> A >> B;
		resetans();
		for(ull j = A ; j <= A+B ; j++)
		{
			ans[dpfib[j]] += 1;
		}
		ull count = 0;
		cout<<"Case "<<c<<":"<<" ";
		for(ull j = 0 ; j <= MAXX ; j++)
		{
			while(ans[j])
			{
				cout<<j;
				count++;
				if(count >= 100 || count >= A + B)
					break;
				ans[j]--;
				cout<<" ";
			}
		}
		if(c != C)
			cout<<endl;
	}
}
