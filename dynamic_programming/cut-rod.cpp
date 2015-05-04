#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int N = 8;
//int p[] = { 0,1, 5, 8, 9, 10, 17, 17, 20,24,30};
int p[] = { 0,1,   5,   8,   9,  10,  17,  17,  20};
//1	5	8	10	13	17	18	22	25	30
vector<int>r;
void processRod();
int  maxof(int x, int y)
{
	if(x > y )
		return x;
	else
		return y;
}
int main()
{

	processRod();
	cout<<"Soln ::"<<endl;
	for(int i = 0; i <= N; i++)
	{
		cout<<r[i]<<"\t";
	}
	cout<<endl;
	return 0;

}

void processRod()
{
	r.push_back(0);
	for(int i = 1; i <= N; i++)
	{
		int nr = p[i];
		for(int j = 1; j < i; j++)
		{
			nr = maxof(nr,r[i-j]+r[j]);
			if( i == 2)
				cout<<nr<<endl;
		}
		r.push_back(nr);
	}
}
