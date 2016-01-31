#include<vector>
#include<stdio.h>
#include<iostream>
using namespace std;
typedef vector<int > vi;
typedef vector<vi> vvi;
vvi final;


int C;

void findFactorial()
{
	vi fac;
	fac.push_back(1);
	final.push_back(fac);
	final.push_back(fac);
	fac.clear();
	for(int i = 2; i <= 100 ; i++)
	{
		fac.clear();
		int prev = final.size()-1;
		int carry = 0;
		for(int j = 0; j < final[prev].size(); j++)
		{
			int sum  = carry + i * final[prev][j];
			int last = sum % 10;
			carry = sum / 10;
			fac.push_back(last);
		}
		while(carry)
		{
			int last = carry%10;
			fac.push_back(last);
			carry = carry /10;
		}
		final.push_back(fac);
	}
}
int main()
{
	//freopen("input","r",stdin);
	findFactorial();
	cin >> C;
	int num;
	for(int i = 1; i <= C; i++)
	{
		cin >> num;
		for(int j = final[num].size() -1 ;j >= 0; j--)
		{
			cout<<final[num][j];
		}
		cout<<endl;
	}
}
