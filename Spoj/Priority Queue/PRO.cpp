#if 1
#include<algorithm>
#include<functional>
#include<iostream>
#include<queue>
using namespace std;
FILE* pF = NULL;
#define MS 10005
int N, k;
int cnt[1000001];
typedef unsigned long long ull;
ull solve()
{
	priority_queue<int>pqmax;
	priority_queue<int , vector<int> , std::greater<int> >pqmin;
	ull sum = 0;
	cin >> N;
	int amt = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> amt;
			cnt[amt]++;
			pqmax.push(amt);
			pqmin.push(amt);
		}
		int high = pqmax.top();
		int low = pqmin.top();
		pqmax.pop(); pqmin.pop();
		while (1)
		{
			if (cnt[high])
			{
				cnt[high]--;
				break;
			}
			else
			{
				high = pqmax.top();
				pqmax.pop();
			}
		}
		while (1)
		{
			if (cnt[low])
			{
				cnt[low]--;
				break;
			}
			else
			{
				low = pqmin.top();
				pqmin.pop();
			}
		}
		sum += high - low;
	}
	return sum;
}
int main()
{
	freopen_s(&pF, "input.txt", "r", stdin);
	
	cout << solve() << endl;
	
	return 0;
}
#endif