#include<iostream>
using namespace std;

int N = 8;
//int a[] = { 7, 1,6,3,8,2,5,4};
int a[] = { 7, 1,6,3,8,2,5,4,16,12,13,11,14,15,9,10};
void qswap(int i, int j)
{
	int t = a[i];
	a[i]=a[j];
	a[j]=t;
}
void disp()
{
	cout<<endl;
	for(int i = 0; i <sizeof(a)/sizeof(int); i++)
	{
		cout<<a[i]<<"\t";
	}
}
void mqsort(int i , int j);
int partt(int i , int j);
int main()
{
	cout<<"before qsort :: "<<endl;
	disp();
	mqsort(0,15);
	cout<<endl;
	cout<<"after qsort :: "<<endl;
	disp();
	cout<<endl;
	return 0;
}
void mqsort(int i,int j)
{
	if(i >= j)
	return;
	int p = partt(i,j);
	mqsort(i,p-1);
	mqsort(p+1,j);
}
int partt(int i , int j)
{
	int pv = j;
	int C = a[pv];
	j--;
	while(i <= j)
	{
		if(a[i] > C && a[j] < C)
		{
			qswap(i,j);
			i++;
			j--;
		}
		else
		{
			if(a[i] <= C)
			{
			i++;
			}
			if(a[j] >= C)
			{
				j--;
			}
		}
	}
	a[pv] = a[i];
	a[i] = C;
	return i;
}
