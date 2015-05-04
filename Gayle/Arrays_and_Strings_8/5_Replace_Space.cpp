//Q 5 Write a method to replace all spaces in a string with '%20'. 
//
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(int argc , char* argv[])
{
	string istr("Where there is will there is way");
	int len = istr.size();
	int spaceCount=0;
	for(int i = 0 ; i < len; i++)
	{
		if(istr[i] == ' ')
		{
			spaceCount++;
		}
	}
	int newlen = len + spaceCount*2;
	cout<<"string before replacing -- "<<istr<<endl;
	istr.resize(newlen);
	int j = newlen - 1;
	for(int i = len -1;i >=0; i--)
	{
		if(istr[i] == ' ')
		{
			istr[j] = '0';
			istr[j-1] = '2';
			istr[j-2] = '%';
			j=j-3;
		}
		else
		{
			istr[j]= istr[i];
			j = j-1;
		}
	}
	cout<<"new string after replacing spaces with %20 is -- "<<istr<<endl;
	return 0;
}