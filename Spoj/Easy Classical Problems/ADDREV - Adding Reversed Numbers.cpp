/*
 * ADDREV.cpp
 *
 *  Created on: 01-Aug-2015
 *      Author: ankur
 */


#include<iostream>
using namespace std;
#include<string>
#include<sstream>
#include<stdio.h>

int getrev(string s);

int addrev(string num1, string num2);

int main()
{
	int C;
//	freopen("input","r",stdin);
	cin >> C;
	for(int c = 1 ; c <= C; c++)
	{
		string num1, num2;

		cin >> num1 >> num2;

		cout<<addrev(num1,num2)<<endl;;
	}
}
int addrev(string s1, string s2)
{
	int sum = getrev(s1) + getrev(s2);

	stringstream ss;

	ss << sum;

	return getrev(ss.str());
}

int getrev(string s)
{
	int num=0;
	for(int i = s.size() -1 ; i >=0 ; i--)
	{
		num= 10*num + int(s.at(i)) - 48;
	}
	return num;
}

