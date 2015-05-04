#include<iostream>
using namespace std;
const int N = 32;
int arr[N] =  { 7, 2, 15, 9, 4, 8, 1, 13, 3, 16, 6, 5, 11, 10, 12 ,14,
 7, 2, 15, 9, 4, 8, 1, 13, 3, 16, 6, 5, 11, 10, 12 ,14};

void msort(int* arr, int l , int h);
void merge(int* arr , int l1, int h1, int l2, int h2);
void printArray();
void msort(int* arr, int l , int h)
{
	if(l==h )
	{
		return;
	}
	else
	{
		int p = l+(h-l)/2;
		msort(arr,l,p);
		msort(arr,p+1,h);
		merge(arr,l,p,p+1,h);
	}
}
void merge(int* arr, int l1, int h1, int l2, int h2)
{
	int s1 = h1-l1+1;
	int s2 = h2-l2+1;
	int* auxArray = new int[s1+s2];
//	int* auxArray = new int[N];
	int* ptr1 = &arr[l1];
	int* ptr2 = &arr[l2];
	int cnt=0;
	int c1 = 0;
	int c2 = 0;
	while(c1 < s1 && c2 < s2)
	{
		if(*ptr1 < *ptr2)
		{
			auxArray[cnt] = *ptr1;
			ptr1++;
			c1++;
		}
		else
		{
			auxArray[cnt] = *ptr2;
			ptr2++;
			c2++;
		}
		cnt++;
	}
	if(c1 < s1)
	{
		for(cnt; cnt<=s1+s2;cnt++)
		{
			auxArray[cnt] = *ptr1;
			ptr1++;
		}
	}
	else
	{
		for(cnt; cnt<=s1+s2;cnt++)
		{
			auxArray[cnt] = *ptr2;
			ptr2++;
		}
	}
	int ai=0;
	for(int i = l1; i <=h2; i++)
	{
		arr[i]=auxArray[ai];
		ai++;
	}
	delete []auxArray;
}

int main()
{
	printArray();
	cout<<endl<<endl;
	msort(arr,0,31);
	printArray();
	cout<<endl<<endl;
	return 0;
}
void printArray()
{
	for(int i = 0 ; i < N ; i++)
	{
		cout<<arr[i]<<"\t";
	}
}
