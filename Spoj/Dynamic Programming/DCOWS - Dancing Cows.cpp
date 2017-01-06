#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
int N , M;
typedef  long long ull;
vector<ull>bh;

vector<ull>ch;
ull maxx = 999999999999;


ull dp[5001][5001];

ull solve();
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> N >> M;
	ull b;
	bh.push_back(0);
	for(int i = 1 ; i <= N ; i++)
	{
		cin >> b;
		bh.push_back(b);
	}
	ull c;
	ch.push_back(0);
	for(int i = 1 ; i <= M ; i++)
	{
		cin >> c;
		ch.push_back(c);
	}
	sort(bh.begin(),bh.end());
	sort(ch.begin(),ch.end());
	

	cout<<solve()<<endl;
	
	return 0;
}


ull solve()
{

	for(int j = 0; j <= M ; j++)
	{
		dp[0][j] = 0;
	}

	for(int i = 1; i <= N ; i++)
	{
		for(int j = 0; j <= M ; j++)
		{
			dp[i][j] = maxx;
		}
	}
	for(int b = 1; b <= N ; b++)
	{

		for(int c = b; c <= M ; c++)
		{
			ull tcost = abs(bh[b] - ch[c]);			

			dp[b][c] = min(tcost + dp[b-1][c-1],dp[b][c-1]);
		}
	}
	ull ans = maxx;
	for(int j = N; j <= M; j++)
	{
		ans = min(ans ,dp[N][j]);
	}
	return ans;
}

