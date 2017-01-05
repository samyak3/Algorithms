#include<iostream>
using namespace std;
char a[] = "AAACAAAA";
int lps[100];
int N = 8;
void buildLPS()
{
	int PosToMatchForSuffix = 1;
	int PosToMatchForPrefix = 0;
	while (PosToMatchForSuffix < N)
	{
		if (a[PosToMatchForSuffix] == a[PosToMatchForPrefix])
		{
			lps[PosToMatchForSuffix] = PosToMatchForPrefix + 1;
			PosToMatchForPrefix++;
			PosToMatchForSuffix++;
		}
		else
		{
			if (PosToMatchForPrefix == 0)
			{
				lps[PosToMatchForSuffix] = 0;
				PosToMatchForSuffix++;
			}
			else
			{
				PosToMatchForPrefix = lps[PosToMatchForPrefix - 1];//beauty
			}
		}
	}
}
int main()
{
	buildLPS();
	return 0;
}

