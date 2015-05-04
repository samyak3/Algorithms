#include<iostream>
#include<stdlib.h>
using namespace std;
const int N = 8192;
int arr[N];
int cnt;
void fillarray()
{
	for(int i = 1; i <=N ; i++)
	{
		arr[i-1] = i;
	}
}
bool bsearch(int x, int low, int high)
{
	cout<<"high --"<<high<<"   low -- "<<low<<endl;
	if(high < low)
		return false;
	cnt++;
	if(high == low)
	{
		return (arr[low] == x);
	}
	int mid = low + (high - low)/2;
	cout<<"high --"<<high<<"   low -- "<<low<<"  mid -- "<<mid<<endl;
	if(x == arr[mid])
	{
		return true;
	}
	else
	{
		/*		if(high - low == 1)
				{
				return ((arr[high] == x) || (arr[low] == x));
				}*/
		if(x > arr[mid] )
		{
			return bsearch(x,mid+1,high);
		}
		else
		{
			return bsearch(x,low,mid-1);
		}
	}
}

int main(int argc , char* argv[])
{
	fillarray();
	int x = atoi(argv[1]);
	bsearch(x,0,N-1);
	cout<<"Number of search operations ::"<<cnt<<endl;
	return 0;
}
