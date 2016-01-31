#include<stdio.h>
#include<iostream>
using namespace std;
typedef unsigned long long ull;

int main()
{
	//freopen("input","r",stdin);
	int N=0;
	while(1)
	{
		cin >> N;
		if(N == 0)
			break;
		cout<< ( N * (N + 1) * (2* N + 1) ) /6;
		cout<<endl;
	}
	return 0;
}
