/*
 * parens.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: Admin
 */

//Generate strings of matched parens

#include<iostream>
#include<stdio.h>
using namespace std;

int g_pairCount;

void parens(int pos , int nOpenBraces , int nCloseBraces)
{
	static char sBraces[100];

	if(nCloseBraces == g_pairCount)
	{
		printf("%s\n",sBraces);
		return;
	}


	if(nOpenBraces < g_pairCount)
	{
		sBraces[pos] = '(';
		parens(pos+1,nOpenBraces+1,nCloseBraces);
	}
	if(nCloseBraces < nOpenBraces)
	{
		sBraces[pos] = ')';
		parens(pos+1,nOpenBraces,nCloseBraces+1);
	}

}
int main()
{
	g_pairCount = 3;
	//pos = 0 means write first bracket at pos 0 , nOpenBraces = nCloseBraces = 0 means initially there are no brackets
	parens(0,0,0);
	return 0;
}

//Output:

/*

((()))
(()())
(())()
()(())
()()()

 */
