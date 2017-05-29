#include<iostream>
using namespace std;

const int N = 16;
int a[2 * N];
FILE* p = 0;
void build()
{
	for (int i = 0; i <  N; i++)
	{
		cin >> a[N+i];
	}
	for (int p = N - 1; p >= 1; p--)
	{
		a[p] = a[p << 1] + a[p << 1 | 1];
	}
	
}


void modify(int index, int val)
{
	a[index + N] = val;
	int childIndex = index + N;
	for (; childIndex > 1; childIndex = childIndex >> 1)
	{
		a[childIndex >> 1] = a[childIndex] + a[childIndex ^ 1];//mistake second child
	}
}

int query(int l, int r)//l included , r excluded 
{
	int sum = 0;
	l = l + N;
	r = r + N;
	while (l < r)
	{
		
		//if l is odd it is included in interval but its left index
		// is not included and hence parent cannot be included 
		//so add the value at l
		
		if (l & 1)
		{
			sum += a[l++];
		}

		if (r & 1)
		{
			sum += a[--r];
		}

		l = l / 2;
		r = r / 2;
	}
	return sum;
}

int main()
{
	freopen_s(&p, "input.txt", "r", stdin);
	build();
	cout << query(0, 2) << endl;
	return 0;
}