//Longest Common subsequence

#include<iostream>
#include<string.h>
using namespace std;

char str1[]="ZBCDEF";
char str2[]="BACDF";
int len[6][5];

int lcs(int pos1, int pos2)
{
	if(len[pos1][pos2])
		return len[pos1][pos2];
	if(pos1 < 0 || pos2 < 0)
	{
		return 0;
	}
	
	else if(str1[pos1] == str2[pos2])
	{
		len[pos1][pos2] = 1 + lcs(pos1-1,pos2-1);
		return len[pos1][pos2];
	}
	else
	{
		len[pos1][pos2]=max(lcs(pos1-1,pos2),lcs(pos1,pos2-1));
		return len[pos1][pos2];
	}
}

int main()
{
	cout<<endl<<"Length of longest common subsequence for "<<str1<<"  and "<<str2<<" is ::"<<lcs(strlen(str1)-1,strlen(str2)-1)<<endl<<endl;
	return 0;
}