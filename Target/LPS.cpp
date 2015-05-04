//Longest Palindrome subsequence

#include<iostream>
#include<string.h>
using namespace std;
const int N = 16;
char str[]="ABCQWERTYCQNBJIA";

int len[N][N];

int lps(int start, int end)
{
	if(len[start][end])
		return len[start][end];
	if(start == end)
	{
		return 1;
	}
	else if(start > end)
	{
		return 0;
	}
	else if(str[start] == str[end])
	{
		cout<<endl<<__LINE__<<"  "<<start<<" "<<end<<endl;
		len[start][end] = 2 + lps(start+1,end-1);
		return len[start][end];
	}
	else
	{
		cout<<endl<<__LINE__<<"  "<<start<<" "<<end<<endl;
		len[start][end]=max(lps(start+1,end),lps(start,end-1));
		return len[start][end];
	}
}

int main()
{
	cout<<endl<<"Length of longest palindrome subsequence "<<str<<" is ::"<<lps(0,N-1)<<endl<<endl;
	return 0;
}