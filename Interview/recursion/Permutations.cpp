/*
 * Permutations.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: Admin
 */
//Print all permutations of a string

#include<iostream>
#include<string>
using namespace std;

static int calls=0;
void Permute(string prefix , string s)
{
	if(s.size() == 0)
	{
		return;
	}

	char temp;

	for(int i = 0 ; i < s.size() ; i++)
	{
		temp = s[0];
		s[0] = s[i];
		s[i] = temp;

		if(s.size() == 1)
		{
			calls++;
			cout<<prefix<<s<<endl;
		}

		string ns(s.begin()+1,s.end());

		Permute(prefix+s[0],ns);
	}
}
int main()
{
	cout<<"Permutations of abcd are :: "<<endl;

	string s("abcd");

	char temp;

	for(int i = 0 ; i < s.size() ; i++)
	{
		temp = s[0];
		s[0] = s[i];
		s[i] = temp;

		string prefix(s.begin(),s.begin()+1);

		string ns( s.begin()+1,s.end());

		Permute(prefix,ns);
	}
	cout<<"calls :: "<<calls<<endl;
	return 0;
}
