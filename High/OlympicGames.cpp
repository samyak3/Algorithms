#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class OlympicGames
{
public:
	int worstPlace(vector<string> medals, int nGamesLeft)
	{
		const int nTotalTeams = medals.size();
		vector<int>gold;
		vector<int>silver;
		vector<int>bronze;
		int i, j, k;
		i = j = k = 0;
		for (int t = 0; t < nTotalTeams; t++)
		{
			string str = medals[t];
			string sg;
			for (i = 0; i < str.size(); i++)
			{
				if (str[i] != ' ')
				{
					string ls(str.begin() + i, str.begin() + i + 1);
					sg.append(ls);
				}
				else
				{
					break;
				}
			}
			int nval = stoi(sg);
			gold.push_back(nval);
			string ss;
			for (j = i + 1; j < str.size(); j++)
			{
				if (str[j] != ' ')
				{
					string ls(str.begin() + j, str.begin() + j + 1);
					ss.append(ls);
				}
				else
				{
					break;
				}
			}
			nval = stoi(ss);
			silver.push_back(nval);
			string sb;
			for (k = j + 1; k < str.size(); k++)
			{
				if (str[k] != ' ')
				{
					string ls(str.begin() + k, str.begin() + k + 1);
					sb.append(ls);
				}
				else
				{
					break;
				}
			}
			nval = stoi(sb);
			bronze.push_back(nval);
		}
		int rank = 1;
		gold[0] += nGamesLeft;
		vector<int>silverdeficit;
		vector<int>bronzedeficit;
		for (int c = 1; c <= nTotalTeams; c++)
		{
			if (gold[0]>gold[c])//team c can never beat team zero
				continue;
			if (gold[0] < gold[c])//team zero can never beat team c;
			{
				rank++;
				continue;
			}
			//now comes the case when the team c has same number of gold medals as with team zero
			if (silver[0]<silver[c] || (silver[c] == silver[0] && bronze[c] >bronze[0]))
			{
				rank++;
				continue;
			}
			int sd = silver[0] - silver[c];
			int bd = bronze[0] - bronze[c];
			if (bd < 0)
				bd = -1;
			silverdeficit.push_back(sd);
			bronzedeficit.push_back(bd);
		}
		int nTeamsThatCanBeatZero = silverdeficit.size();

		int MinimumBronzeMedalsRequired[51][10001] = { 0 };
		for (int i = 1; i <= nTeamsThatCanBeatZero; i++)
		{
			for (int j = 0; j <= nGamesLeft; j++)//where j is silver medals used/assigned so i team could beat zero
			{
				MinimumBronzeMedalsRequired[i][j] = 999999999;
			}
		}
		for (int teamIndex = 0; teamIndex <= nTeamsThatCanBeatZero; teamIndex++)
		{
			//for the current team the deficits are :
			int sd = silverdeficit[teamIndex];
			int bd = bronzedeficit[teamIndex];
			for (int teamsConsidered = nTeamsThatCanBeatZero - 1; teamsConsidered >= 0; teamsConsidered--)
			{
				for (int silverMedalsUsed = 0; silverMedalsUsed <= nGamesLeft; silverMedalsUsed++)
				{
					if ((sd + silverMedalsUsed <= nGamesLeft) && (sd + bd + 1 >= nGamesLeft))
					{
						MinimumBronzeMedalsRequired[teamsConsidered + 1][silverMedalsUsed + sd] = min(MinimumBronzeMedalsRequired[teamsConsidered + 1][silverMedalsUsed + sd], MinimumBronzeMedalsRequired[teamsConsidered][silverMedalsUsed] + bd + 1);
					}
					if (sd + silverMedalsUsed + 1 <= nGamesLeft)
					{
						MinimumBronzeMedalsRequired[teamsConsidered + 1][silverMedalsUsed + sd + 1] = min(MinimumBronzeMedalsRequired[teamsConsidered + 1][silverMedalsUsed + sd + 1], MinimumBronzeMedalsRequired[teamsConsidered][silverMedalsUsed]);
					}
				}
			}

		}
		for (int i = nTeamsThatCanBeatZero; i >= 1; i++)
		{
			for (int j = 0; j <= nGamesLeft; j++)
			{
				if (MinimumBronzeMedalsRequired[i][j] <= nGamesLeft)
					return rank + i;
			}
		}
		return rank;
	}
};
int main()
{
	OlympicGames obj;
	vector<string>v;
	string str1("0 0 0");
	v.push_back(str1);
	string str2("1 0 0");
	v.push_back(str2);
	string str3("1 0 0");
	v.push_back(str3);
	cout<<obj.worstPlace(v, 1);
	return 0;
}
