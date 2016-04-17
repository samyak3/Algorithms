#include<iostream>
#include<vector> 
#include<string>
#include<algorithm>

using namespace std;

//FILE* pF;

int N;

int C;

typedef long long ll;

int arr[21][21];

ll dp[21][2097153];


void reset(int x , int y)
{
	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j < y+1; j++)
		{
			dp[i][j] = -1;
		}
	}
}

bool IsTopicAvailable(int nAssignment, int nTopic)
{
	if (nAssignment & (1 << nTopic))
	{
		return false;
	}
	return true;
}
ll solve(int nStudentIndex, int nAssignment)
{
	if (nStudentIndex == N + 1)
	{
		return 1;
	}
	if (dp[nStudentIndex][nAssignment] != -1)
	{
		return dp[nStudentIndex][nAssignment];
	}
	
	ll Answer = 0;

	for (int i = 1; i <= N; i++)
	{
		if (arr[nStudentIndex][i] && IsTopicAvailable(nAssignment, i))
		{
			nAssignment = nAssignment | (1 << i);
			Answer = Answer + solve(nStudentIndex + 1, nAssignment);
			nAssignment = nAssignment ^ (1 << i);
		}
	}
	dp[nStudentIndex][nAssignment] = Answer;
	return Answer;
}

int main()
{
	//freopen_s(&pF, "input.txt", "r",stdin);
	cin >> C;
	
	
	for (int c = 1; c <= C; c++)
	{
		cin >> N;
		reset(N,1<<(N+1));
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> arr[i][j];
			}
		}
		
		int nStudentIndex = 1;
		
		int nAssignment = 0;
		
		ll Answer = solve(nStudentIndex, nAssignment);
				
		cout << Answer << endl;
	}
	return 0;
}
