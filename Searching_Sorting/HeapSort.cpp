#include<iostream>
using namespace std;
const int N = 32;
#define ZERO 0
#define MAXX 1000
int arr[N] =  { 7, 2, 15, 9, 4, 8, 1, 13, 3, 16, 6, 5, 11, 10, 12 ,14, 7, 2, 15, 9, 4, 8, 1, 13, 3, 16, 6, 5, 11, 10, 12 ,14};

void minHeapify(int index , int size);
void HeapSortDescendingOrder(int size);
void maxHeapify(int index , int size);
void HeapSortAsscendingOrder(int size);
void printArray();
void PrintNextSmallest();
int lchild(int index,int size)
{
	if(2*index +1 >= size)
		return MAXX;
	return arr[index*2 + 1];
}

int rchild(int index,int size)
{
	if(2*index +2 >= size)
		return MAXX;
	return arr[index*2 + 2];
}
int lmchild(int index,int size)
{
	if(2*index +1 >= size)
		return ZERO;
	return arr[index*2 + 1];
}

int rmchild(int index,int size)
{
	if(2*index +2 >= size)
		return ZERO;
	return arr[index*2 + 2];
}

void hswap(int x , int y)
{
	int temp = arr[x];
	arr[x]=arr[y];
	arr[y]=temp;
}

void HeapSortDescendingOrder(int size)
{
	for(int i = N/2 - 1; i >=0 ; i--)
	{
		minHeapify(i,size);
	}
	
	int min = arr[ZERO];
	hswap(ZERO,size-1);
	size--;
	int R = size;
	for(int i = 1; i <=R ; i++)
	{
		minHeapify(ZERO,size);
		hswap(ZERO,size-1);
		size--;
	}
}
void HeapSortAscendingOrder(int size)
{
	for(int i = N/2 - 1; i >=0 ; i--)
	{
		maxHeapify(i,size);
	}
	
	hswap(ZERO,size-1);
	size--;
	int R = size;
	for(int i = 1; i <=R ; i++)
	{
		maxHeapify(ZERO,size);
		hswap(ZERO,size-1);
		size--;
	}
}
void minHeapify(int index, int size)
{
	if(index > size/2 -1  || index <0)
		return;
	
	if(arr[index] >lchild(index,size) || arr[index] >rchild(index,size))
	{
		if(lchild(index,size) > rchild(index,size))
		{
			hswap(index,2*index+2);
			minHeapify(2*index+2,size);
		}
		else
		{
			hswap(index,2*index+1);
			minHeapify(2*index+1,size);
		}
	}
}
void maxHeapify(int index, int size)
{
	if(index > size/2 -1  || index <0)
		return;
	
	if(arr[index] <lmchild(index,size) || arr[index] <rmchild(index,size))
	{
		if(lmchild(index,size) < rmchild(index,size))
		{
			hswap(index,2*index+2);
			maxHeapify(2*index+2,size);
		}
		else
		{
			hswap(index,2*index+1);
			maxHeapify(2*index+1,size);
		}
	}
}

int main()
{
	printArray();
	cout<<endl<<"Descending Order ::"<<endl<<endl;
	
	HeapSortDescendingOrder(N);
	printArray();

	cout<<endl<<"Ascending Order ::"<<endl<<endl;
	
	HeapSortAscendingOrder(N);
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
