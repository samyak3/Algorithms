//Q 2 Write code to reverse a C-style string 
//( C String means that "abcd" is represented as five characters, including the null character )
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main(int argc , char* argv[])
{
	if(argc == 1)
	{
		cerr<<"Enter string for reverse evaluation "<<endl;
		exit(EXIT_FAILURE);
	}
	char szCString[256] = {0};
	strcpy(szCString,argv[1]);
	int j =strlen(szCString) - 1;; 
	for(int i = 0 ; i < j; i++)
	{
		char ch = szCString[i];
		szCString[i] = szCString[j];
		szCString[j] = ch;
		j--;
	}
	
	cout<<"C String after reverse operation -- "<<szCString<<endl;
	
	return 0;
}