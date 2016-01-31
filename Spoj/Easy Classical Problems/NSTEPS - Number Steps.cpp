#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
	int C;
//	freopen("input","r",stdin);
	cin >> C;
	for(int c = 1 ; c <= C ; c++)
	{
		int x,y;
		cin >> x >> y;
		if(x > 10000 || y > 10000 || x < 0 || y <0 || abs(x - y ) > 2)
		{
			cout<<"No Number"<<endl;
			continue;

		}
		if( x % 2 == 0 && y % 2 == 0 && x >= y)
		{
			cout<<x+y<<endl;
		}
		else if(x % 2 != 0 && y % 2 != 0 && x >= y)
		{
			cout<<x+y-1<<endl;
		}
		else
		{
			cout<<"No Number"<<endl;
		}
	}
	return 0;
}