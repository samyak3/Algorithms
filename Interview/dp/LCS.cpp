//Longest Common subsequence

#include<iostream>
#include<string.h>
using namespace std;

//char str1[]="ZBCDEF";
//char str2[]="BACDF";
//char str1[]="SATURDAY";
//char str2[]="SUNDAY";

char str1[]="Wehretehreisawliltehreisawya";
char str2[]="Wherethereisawillthereisaway";

int callsForDP=0;
int callsForMemoization=0;
const int M = 28;
const int N = 28;
int len[M][N];
int dplen[M+1][N+1];
void updateBaseCase();
//memozation approach
int lcs(int pos1, int pos2)
{
	if(pos1 < 0 || pos2 < 0)
	{
		return 0;
	}
	if(len[pos1][pos2])
		return len[pos1][pos2];	
	else if(str1[pos1] == str2[pos2])
	{
		callsForMemoization++;
		len[pos1][pos2] = 1 + lcs(pos1-1,pos2-1);
		return len[pos1][pos2];
	}
	else
	{
		callsForMemoization++;
		len[pos1][pos2]=max(lcs(pos1-1,pos2),lcs(pos1,pos2-1));
		return len[pos1][pos2];
	}
}
void updateTable()
{
	for(int i = 0;i<= M ; i++ )
	{
		dplen[i][0]=0;
	}
	for(int i = 0;i<= N ; i++ )
	{
		dplen[0][i]=0;
	}
	for(int i = 1;i<= M ; i++ )
	{
		for(int j= 1;j<= N ; j++ )
		{
			callsForDP++;
			if(str1[i-1] == str2[j-1])
			{
				dplen[i][j]=1+dplen[i-1][j-1];
			}
			else
			{
				dplen[i][j]=max(dplen[i-1][j],dplen[i][j-1]);
			}
		}
	}
	
}
int main()
{
	cout<<endl<<"Top Down :: Length of longest common subsequence for "<<str1<<"  and "<<str2<<" is ::"<<lcs(strlen(str1)-1,strlen(str2)-1)<<endl<<endl;
	
	cout<<endl<<"Cals for Memoization/Top Down approach ::"<<callsForMemoization<<endl;
	
	updateTable();
	
	cout<<endl<<"DP :: Length of longest common subsequence for "<<str1<<"  and "<<str2<<" is ::"<<dplen[M][N]<<endl<<endl;
	
	cout<<endl<<"Cals for DP/Bottom Up approach ::"<<callsForDP<<endl;
	
	return 0;
	
}