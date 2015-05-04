//Q 3 Remove duplicates characters in a string  

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main(int argc , char* argv[])
{
	if(argc == 1)
	{
		cerr<<"Enter string for removing duplicates "<<endl;
		exit(EXIT_FAILURE);
	}
	char arr[256] = {0};
	strcpy(arr,argv[1]);
	bool count[256]={0};
	int cur=0;
	int next=0;
	for(int i = 0 ; i < strlen(arr); i++)
	{
		if(count[arr[cur]] == 0)
		{
			count[arr[cur]] = 1;
			cur++;
		}
		else//find the next 
		{
			while(i <strlen(arr))
			{
				if(count[arr[i]] == 0)
				{
					break;
				}
				else
				{
					i++;
				}
			}		
			if(i <strlen(arr))
			{
				arr[cur]=arr[i];
				count[arr[cur]] = 1;
			}
			else
			{
				arr[cur]='\0';
				break;
			}
			cur++;
		}
	}
	arr[cur]='\0';
	cout<<" String after removing duplicates  "<<arr<<endl;
	
	return 0;
}