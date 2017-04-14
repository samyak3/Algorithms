#include<iostream>
#include<algorithm>
using namespace std;

FILE* pF = NULL;

const int MAXN = 52;
const int MAXTIME = 1001;
const int INF = 1 << 30;

int T, N;

int toll[MAXN][MAXN];
int ntime[MAXN][MAXN];
int cost[MAXN][1001];

int main() {
	//freopen_s(&pF, "input.txt", "r", stdin);
	while (1)
	{
		cin >> N >> T;
		if (N + T == 0)
			break;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				cin >> ntime[i][j];

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				cin >> toll[i][j];


		for (int j = 1; j <= N; j++)
			for (int i = 0; i <= T; i++)
				cost[j][i] = INF;

		for (int i = 0; i <= T; i++)
			cost[1][i] = 0;


		for (int i = 1; i <= T; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) {
					if ((j == k) || (i < ntime[j][k]))
						continue;

					int timeReqForJK = ntime[j][k];
					if (cost[j][i - timeReqForJK] + toll[j][k] < cost[k][i])
						cost[k][i] = cost[j][i - timeReqForJK] + toll[j][k];

					cost[k][i] = min(cost[k][i], cost[k][i - 1]);
				}
			}
		}
		int ans = INF;
		int timeAns = 0;
		for (int t = 1; t <= T; t++)
		{
			if (ans > cost[N][t])
			{
				ans = cost[N][t];
				timeAns = t;
			}
		}
		cout << ans << " " << timeAns << endl;
	}
	return 0;
}
