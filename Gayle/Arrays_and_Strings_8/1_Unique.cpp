//Q Implement an algorithm to determine if a string has all unique characters. 
//What if you cannot use additional data structures?
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(int argc , char* argv[])
{
	if(argc == 1)
	{
		cerr<<"Enter string for evaluation of unique characters "<<endl;
		exit(EXIT_FAILURE);
	}
	string str(argv[1]);
	bool arr[256] = {0};
	bool bUnique = true;
	for(int i = 0 ; i < str.size(); i++)
	{
		if(arr[str[i]] == 0)
		{
			arr[str[i]] = 1;
		}
		else
		{
			bUnique = false;
			break;
		}
	}
	if(bUnique)
	{
		cout<<str<<" has all unique characters !!"<<endl;
	}
	else
	{
		cout<<str<<" does not have unique characters !!"<<endl;
	}
	return 0;
}