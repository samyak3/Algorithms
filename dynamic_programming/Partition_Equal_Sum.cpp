#include<iostream>
using namespace std;
int a[]={3,5,7,13,100,200,73,12,13,5,11,10};
int S;
int N;
bool IsSum(int index, int sum)
{
	if(sum *2 == S)
	{
		return true;
	}
	if(index >= N || sum*2 > S)
		return false;
	return(IsSum(index+1,sum+a[index]) || IsSum(index+1,sum));
}
void updateSum()
{
	N = sizeof(a)/sizeof(int);
	for(int i = 0 ; i < N ; i++)
	{
		S = S + a[i];
	}
}
int main()
{
	updateSum();
	cout<<IsSum(0,0)<<endl;
	return 0;
}