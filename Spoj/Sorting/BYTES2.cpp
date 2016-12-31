#include<iostream>
#include<algorithm>
using namespace std;
int nC;
int N;
int entryTime[101];
int exitTime[101];
FILE* pF;
int solve()
{
	int i = 0;
	int j = 0;
	int nDancersAtATime = 0;
	int ans = 0;
	while (i < N && j < N)
	{
		if (entryTime[i] < exitTime[j])
		{
			nDancersAtATime++;
			i++;
		}
		else
		{
			nDancersAtATime--;
			j++;
		}
		ans = max(ans, nDancersAtATime);
	}
	return ans;
}
int main()
{
	//freopen_s(&pF, "input.txt", "r", stdin);
	cin >> nC;
	while (nC--)
	{
		cin >> N;
		for (int n = 0; n < N; n++)
		{
			cin >> entryTime[n] >> exitTime[n];
		}
		sort(entryTime, entryTime + N);
		sort(exitTime, exitTime + N);
		cout << solve() << endl;
	}
	return 0;
}