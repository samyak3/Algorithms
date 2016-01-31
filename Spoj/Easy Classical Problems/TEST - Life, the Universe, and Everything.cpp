/*
 * LifeUniverseEverything.cpp
 *
 *  Created on: 01-Aug-2015
 *      Author: ankur
 */

#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	//freopen("input","r",stdin);
	int num=0;
	while(1)
	{
		cin >> num;
		if(num == 42)
		{
			break;
		}
		else
		{
			cout<<num<<endl;
		}
	}
	return 0;
}

