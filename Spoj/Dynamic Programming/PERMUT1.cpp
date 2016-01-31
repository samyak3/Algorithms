#include<iostream>
using namespace std;
int C;
int N;
int K;
#define MAX_K 99
#define MAX_N 13
typedef unsigned long long ull;
ull ways[MAX_K][MAX_N];
void tabulate()
{
	for(int j = 0; j <= MAX_N-1; j++)
	{
		ways[0][j] = 1;
	}
	for(int i = 0; i <= MAX_K-1; i++)
	{
		ways[i][0] = 0;
	}
	for(int k = 1 ; k <= MAX_K - 1; k++)
	{
		for(int n = 1 ; n <= MAX_N -1 ; n++)
		{
			int tK = k;
			int tN = 0;
			for(tK ; tK >= 0; tK--)
			{
				ways[k][n] += ways[tK][n-1];
				tN++;
				if(tN == n)
					break;
			}
		}
	}
}
int main()
{
	tabulate();
	cin >> C;
	for(int c = 1 ; c <= C ; c++)
	{
		cin >> N >> K;
		cout<<ways[K][N]<<endl;
	}

	return 0;
}
