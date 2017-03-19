#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
FILE* pF = NULL;
#define MS 10005
int N;
typedef struct node
{
	int disanceFromTown;
	int fuelAvailable;
};
node a[MS];
class comp
{
public:
	bool operator()(node a, node b)
	{
		return a.disanceFromTown > b.disanceFromTown;
	}
};


int totalDis;

int solve()
{
	int fuelRemaining = a[0].fuelAvailable;

	priority_queue<int>pq;

	int pos = 0;

	int ans = 0;


	while (fuelRemaining >= 0)
	{

		int nextMoveCost = a[pos].disanceFromTown - a[pos + 1].disanceFromTown;

		if (fuelRemaining - nextMoveCost >= 0)
		{
			pq.push(a[pos+1].fuelAvailable);
			
			fuelRemaining = fuelRemaining - nextMoveCost;
			
			pos++;
			
			if (pos == N + 1)
			{
				break;
			}
		}
		else
		{
			if (pq.empty())
				return -1;
			int addfuel = pq.top();

			pq.pop();
			fuelRemaining = fuelRemaining + addfuel;
			ans++;
		}
	}

	return ans;
}
int main()
{
	//freopen_s(&pF, "input.txt", "r", stdin);
	int C;
	cin >> C;
	while (C--)
	{
		cin >> N;
		int totalfuel = 0;
		for (int i = 0; i <= N; i++)
		{
			cin >> a[i].disanceFromTown >> a[i].fuelAvailable;
			totalfuel += a[i].fuelAvailable;
		}
		
		sort(a, a + N + 1,comp());

		totalfuel += a[0].fuelAvailable;
		totalDis = a[0].disanceFromTown;
		if (totalfuel < totalDis)
			cout << -1 << endl;
		else
			cout << solve() << endl;
	}

	return 0;
}