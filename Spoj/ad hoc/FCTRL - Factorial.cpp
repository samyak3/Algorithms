
#include<iostream>

#include<vector>

#include<stdio.h>

using namespace std;

typedef unsigned long long ull;

vector<ull> iv;
vector<ull> outv;

void findZ();
void outZ();
ull maxNum = 1;

int main()
{
//	freopen("input","r",stdin);
	ull C;
	cin >> C;
	ull num;

	for(ull c = 1; c <= C; c++)
	{
		cin >>  num ;
		num = (num/5) * 5;
		if(num > maxNum)
			maxNum = num;

		iv.push_back(num);
	}
	findZ();
	outZ();
}
void findZ()
{
	for(ull i = 0; i < iv.size() ; i++)
	{
		ull dd = 5;
		ull nz = 0;
		ull num = iv[i];
		while(dd <= num )
		{
			nz = nz + num/dd;
			dd= dd * 5;
		}
		outv.push_back(nz);
	}
}
void outZ()
{
	for(ull  i = 0; i < outv.size() ;i++)
	{
		cout<<outv[i]<<endl;
	}
}