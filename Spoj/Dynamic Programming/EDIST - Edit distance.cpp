#include<iostream>
#include<string>
using namespace std;
string s1,s2;
	
//Choices :: either insertion or deletion or replacement

int slen,dlen;
int dis[3000][3000];

//bottom up 

void updateTable()
{
	for(int i = 1; i <= slen ; i++)
	{
		dis[i][0]=i;
	}
	for(int j = 1; j <= dlen ; j++)
	{
		dis[0][j]=j;
	}
	for(int i = 1; i <= slen; i++)
	{
		for(int j = 1; j <= dlen; j++)
		{
			dis[i][j] = min(1+dis[i-1][j] , min( 1+dis[i][j-1],dis[i-1][j-1] + (s1.at(i-1) != s2.at(j-1)) ) );
		}
	}
}
void resetTable()
{
	for(int i = 1; i <= slen ; i++)
	{
		dis[i][0]=i;
	}
	for(int j = 1; j <= dlen ; j++)
	{
		dis[0][j]=j;
	}
	for(int i = 1; i <= slen; i++)
	{
		for(int j = 1; j <= dlen; j++)
		{
			dis[i][j] = 10000;
		}
	}
}

int main()
{
	int C;
	cin >> C;
	for(int c = 1 ; c <= C ; c++)
	{
		cin >> s1 >> s2;
		slen = s1.size();
		dlen = s2.size();
		updateTable();
	
		cout<<dis[slen][dlen]<<endl;
		resetTable();
	}
	return 0;
}