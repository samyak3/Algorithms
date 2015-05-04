//Q 4 Write a method to check if two strings are anagram or not 
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(int argc , char* argv[])
{
	if(argc < 3)
	{
		cerr<<"Enter 2 string for evaluation of anagram  "<<endl;
		exit(EXIT_FAILURE);
	}
	string str(argv[1]);
	string str2(argv[2]);
	int arr[256] = {0};
	bool bAnagram= true;
	for(int i = 0 ; i < str.size(); i++)
	{
			arr[str[i]] = arr[str[i]] + 1;				
	}
	for(int i = 0 ; i < str2.size(); i++)
	{
		if(arr[str2[i]] == 0)
		{
			cout<<str2[i]<<" is not common "<<endl;
			bAnagram = false;
			break;
		}	
		else
		{
			arr[str2[i]] = arr[str2[i]] - 1;
		}
	}
	if(bAnagram == false)
	{
		cout<<str<<"  and  "<<str2<<" are  not anagrams !!!"<<endl;
		return 0;
	}
	else
	{
		for(int i = 0 ; i < 256 ; i++)
		{
			if(arr[i] != 0)
			{
				bAnagram = false;
				break;
			}
		}
	}
	
	if(bAnagram == false)
	{
		cout<<str<<"  and  "<<str2<<" are  not anagrams !!!"<<endl;
	}
	else
	{
			cout<<str<<"  and  "<<str2<<" are  anagrams !!!"<<endl;
	}
	return 0;
}