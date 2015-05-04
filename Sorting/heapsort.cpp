#include<iostream>
using namespace std;

void heapify(int i);
int N = 8;
int a[] = { 7, 1,6,3,8,2,5,4};
//int a[] = { 1, 2, 3,4,5,6,7,8};
void hsort();
void bheap(int i);
void hswap(int i, int j)
{
	int t = a[i];
	a[i]=a[j];
	a[j]=t;
}
void disp()
{
	cout<<endl;
	for(int i = 0; i <8; i++)
	{
		cout<<a[i]<<"\t";
	}
}
int cleft(int i)
{
	return 2*i + 1;
}
int cright(int i)
{
	return 2*i + 2;
}
int main()
{
	cout<<"before hsort :: "<<endl;
	disp();
	hsort();
	cout<<"after hsort :: "<<endl;
	disp();
	cout<<endl;
	return 0;
}
void hsort()
{
	for(int i = N/2-1 ; i < N ; i++)
	{
		heapify(i);
	}
//	disp();
	hswap(0,N-1);
//	disp();
	N--;
	for(int i = 1; i <=7; i++)
	{
		bheap(0);
		hswap(0,N-1);
		N--;
//		disp();
	}

}
void heapify(int i)
{
	if(i == 0)
		return;

	if(a[i] > a[i/2])
	{
		hswap(i,i/2);
	}
	heapify(i/2);
}
void bheap(int i)
{
//	cout<<"bheap called for "<<i<<endl;
	int l = cleft(i);
	int r = cright(i);
	int mx=i;
	if(l < N && a[i] < a[l])
		mx = l;
	if(r<N && a[i] < a[r])
	{
		if(mx != i)
		{
			if(a[r] > a[l])
				mx = r;
		}
	}
	if(mx != i)
	{
//		cout<<"swapping "<<i<<" & "<<mx<<endl;
		hswap(i,mx);
//		disp();
		bheap(mx);
	}
}
