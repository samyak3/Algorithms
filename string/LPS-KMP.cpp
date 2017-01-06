#include<iostream>
using namespace std;
char content[] = "ABABDABACDABABCABAB";
char pattern[] = "ABABCABAB";
//char pattern[] = "AAACAAAA";//tricky case
int lps[100];
int N = 8;
int M = 19;
void KMPSearch()
{
	int contentIndex = 0;
	int patternIndex = 0;
	while (contentIndex < M)
	{
		if (content[contentIndex] == pattern[patternIndex])
		{
			contentIndex++;
			patternIndex++;
		}
		else
		{

			if (patternIndex != 0)
			{
				patternIndex = lps[patternIndex - 1];
			}
			else
			{
				contentIndex++;
			}
		}
		if (patternIndex == N)
		{
			cout << "match found at index :: " << contentIndex - N << endl;
			patternIndex = lps[patternIndex - 1];
		}
	}
}
void buildLPS()
{
	int PosToMatchForSuffix = 1;
	int PosToMatchForPrefix = 0;
	while (PosToMatchForSuffix < N)
	{
		if (pattern[PosToMatchForSuffix] == pattern[PosToMatchForPrefix])
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
	KMPSearch();
	return 0;
}

