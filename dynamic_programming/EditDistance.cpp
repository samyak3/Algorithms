#include<iostream>
#include<string.h>
using namespace std;
//char s1[]="DonaldKnuth";
//char s2[]="DoanldKunth";
char s1[]="SUNDAY";
char s2[]="SATURDAY";
//char s1[]="piug";
//char s2[]="ping";

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
	cout<<"distance between "<<s1<<" and "<<s2<<" :: "<<d(strlen(s1),strlen(s2))<<endl;
	return 0;
}