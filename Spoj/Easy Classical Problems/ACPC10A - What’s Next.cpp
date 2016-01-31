#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	//freopen("input","r",stdin);
	int a , b , c;
	while(1)
	{
		cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0)
		{
			break;
		}
		else if( b - a == c - b)
		{
			int cd = b - a ;
			cout<<"AP "<<c+cd<<endl;
		}
		else
		{
			int cr = b/a;
			cout<<"GP "<<c*cr<<endl;
		}
	}
	return 0;
}
