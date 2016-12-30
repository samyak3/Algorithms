#include<iostream>
using namespace std;

int t[16];
int N = 8;
FILE* pF;
void build()
{
	for (int pos = N; pos < 2 * N; pos++)
	{
		cin >> t[pos];
	}
	for (int pos = N - 1; pos >= 1; pos--)
	{
		t[pos] = t[2 * pos] + t[2 * pos + 1];
	}
}
void update(int pos, int val)
{
	pos = pos + N;
	t[pos] = val;
	int parent = pos / 2;
	while (parent > 0)
	{
		t[parent] = t[2 * parent] + t[2 * parent + 1];
		parent = parent / 2;
	}
}
int query(int l, int r)
{
	l = l + N;
	r = r + N;
	int sum = 0;
	while (l < r)
	{
		if (l & 1)
			sum += t[l++];
		if (r & 1)
			sum += t[--r];
		l = l / 2;
		r = r / 2;
	}
	return sum;
}
int main()
{
	freopen_s(&pF,"input.txt", "r", stdin);
	build();
	cout << query(0, 8) << endl;
	return 0;
}