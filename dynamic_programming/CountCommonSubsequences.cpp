//https://stackoverflow.com/questions/31065929/number-of-common-sub-sequences-of-two-strings/50186332#50186332
#include<iostream>
#include<string>
using namespace std;
#define MAX_LEN 101
FILE* pF = 0;
string s1;
string s2;
int N1;
int N2;
int dp[MAX_LEN][MAX_LEN];
int GetCommomSubsequencesCount()
{
	for (int i = 0; i <= N1; i++)//N1 is size of 1st string
	{
		for (int j = 0; j <= N2; j++)//N2 is size of 2nd string
		{
			dp[i][j] = 0;//dp[i][j] is the number of common subsequences for two strings with size i and j respectively
		}
	}
	for (int i = 1; i <= N1; i++)
	{
		for (int j = 1; j <= N2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = 1 + dp[i][j - 1] + dp[i - 1][j]; 
			}
			else
			{
				dp[i][j] =  dp[i][j - 1] + dp[i - 1][j] - dp[i-1][j-1];
			}
		}
	}
	return dp[N1][N2];
}
int main()
{
	freopen_s(&pF, "input.txt", "r", stdin);
	cin >> s1 >> s2;

	N1 = s1.size(); N2 = s2.size();
	cout << GetCommomSubsequencesCount() << endl;
	return 0;
}