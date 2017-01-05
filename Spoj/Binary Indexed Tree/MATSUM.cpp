#if 1
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int MSIZE = 1030;
int bit[MSIZE][MSIZE];
int N;
FILE* pF;
void update(int x, int y, int val)
{
	int yy = 0;
	while (x <= N)
	{
		yy = y;
		while (yy <= N)
		{
			bit[x][yy] += val;
			yy += yy & (-yy);
		}
		x += x & (-x);
	}
}
int sum(int x, int y)
{
	int vsum = 0;
	int y1 = 0;
	while (x >= 1)
	{
		y1 = y;
		while (y1 >= 1)
		{
			vsum += bit[x][y1];
			y1 -= y1 & (-y1);
		}
		x -= x & (-x);
	}
	return vsum;
}
void resetBIT()
{
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			bit[i][j] = 0;
}
int main()
{
	freopen_s(&pF, "input.txt", "r", stdin);
	int C;//cases
	scanf_s("%d", &C);
	char cmd[5];
	memset(cmd, 0, 1);
	int x, y, val;
	int x1, x2, y1, y2;
	while (C--)
	{
		scanf_s("%d", &N); //size of matrix N x N
		resetBIT();
		while (1)
		{
			scanf_s("%s", cmd);
			if (strcmp(cmd, "END") == 0)
			{
				break;
			}
			else if (strcmp(cmd, "SET") == 0)
			{

				scanf_s("%d", &x);
				scanf_s("%d", &y);
				scanf_s("%d", &val);
				x++; y++;
				int v1 = sum(x - 1, y - 1);
				int v2 = sum(x - 1, y);
				int v3 = sum(x, y - 1);
				int v4 = sum(x, y);
				update(x, y, val - (v4 + v1 - v2 - v3));
			}
			else
			{
				scanf_s("%d", &x1);
				scanf_s("%d", &y1);
				scanf_s("%d", &x2);
				scanf_s("%d", &y2);
				x1++; y1++; x2++; y2++;
				int sumx1y1 = sum(x1 - 1, y1 - 1);
				int sumx1y2 = sum(x1 - 1, y2);
				int sumx2y1 = sum(x2, y1 - 1);
				int sumx2y2 = sum(x2, y2);
				printf("%d\n", sumx2y2 + sumx1y1 - sumx1y2 - sumx2y1);
			}
		}
	}
	return 0;
}
#endif