//Longest Increasing Subsequence
#include<iostream>
using namespace std;
const int N = 8;
int arr[N] = { 10, 2, 23, 4, 25, 26, 37, 100};
int seqLength[N]={1};
int lis(int i)
{
	int len=0;
	for(int j = i -1 ;j>=0; j-- )
	{
		if(arr[i] > arr[j] && len < seqLength[j])
		{
			len = seqLength[j];
		}
	}
	seqLength[i]=len+1;
	return seqLength[i];
}
int getLIS()
{
	int lisLength = 0;
	int tlen=0;
	for(int i = 0; i < N ; i++)
	{
		tlen = lis(i);
		if(lisLength < tlen )
		{
			lisLength = tlen;
		}
	}
	return lisLength;
}
int main()
{
	cout<<"Longest increasing subsequence lenght is ::"<<getLIS()<<endl;
	return 0;
}