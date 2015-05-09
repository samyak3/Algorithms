#include<iostream>
#include<string.h>
using namespace std;
//char s1[]="DonaldKnuth";//11
//char s2[]="DoanldKunth";//11

char s1[]="piug";
char s2[]="ping";


//char s1[]="SUNDAY";//6
//char s2[]="SATURDAY";//8


//Choices :: either insertion or deletion or replacement


const int M = 4;
const int N = 4;
int dis[M+1][N+1];

//bottom up 

void updateTable()
{
	for(int i = 1; i <= M ; i++)
	{
		dis[i][0]=i;
	}
	for(int j = 1; j <= N ; j++)
	{
		dis[0][j]=j;
	}
	for(int i = 1; i <= M; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			dis[i][j] = min(1+dis[i-1][j] , min( 1+dis[i][j-1],dis[i-1][j-1] + (s1[i-1] != s2[j-1]) ) );
		}
	}
}



//recursive Top Down approach
int d(int i , int j)
{
	if(i==0 && j == 0)
		return 0;
	if(i==0)
		return j;
	if(j==0)
		return i;
	return min(d(i-1,j)+1, min(d(i,j-1)+1,d(i-1,j-1) + (s1[i-1] != s2[j-1])));
}
int main()
{
	cout<<"Recursive approach -- distance between "<<s1<<" and "<<s2<<" :: "<<d(strlen(s1),strlen(s2))<<endl;
	
	updateTable();
	
	cout<<"DP approach -- distance between "<<s1<<" and "<<s2<<" :: "<<dis[strlen(s1)][strlen(s2)]<<endl;
	return 0;
}