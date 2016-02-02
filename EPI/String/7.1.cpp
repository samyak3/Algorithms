/*
 * 7.1.cpp
 *	Interconvert string and integers
 *  Created on: Jan 26, 2016
 *      Author: Admin
 */
#include<iostream>
using namespace std;
string IntToString(int num)
{
	string str;
	bool bNegative = false;
	if(num < 0 )
	{
		bNegative = true;
		num = num * -1;
	}
	while(num)
	{
		str = char(num % 10 + 48) + str;
		num = num/10;
	}
	if(bNegative)
	{
		str = '-' + str;
	}
	return str;
}
int StringToInt(string str)
{
	bool bNegative = false;

	if(str[0] == '-')
	{
		bNegative = true;
	}

	int ssize = str.size();

	int index = 0 + bNegative ? 1 : 0;

	int num = 0;

	while(index < ssize)
	{
		num = num * 10 +  str[index] - '0';
		index++;
	}
	if(bNegative)
	{
		num = num * -1 ;
	}
	return num;
}
int main()
{
	cout<<StringToInt("1234")<<endl;
	int num = -1080;
	cout<<IntToString(num)<<endl;
	return 0;
}
