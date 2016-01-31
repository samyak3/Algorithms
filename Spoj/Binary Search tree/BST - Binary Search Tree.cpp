/*
 * BST - Binary Search Tree.cpp
 *
 *  Created on: Oct 26, 2015
 *      Author: Admin
 */
#include<iostream>
#include<set>
#include<iterator>
using namespace std;
#define MAXX 300002
typedef long long ll;
ll insertCount[MAXX];
bool hasRightChild[MAXX]={false};
ll nCount=0;
int N;
set<int>s;
int main()
{
	//std::ios::sync_with_stdio(false);
	cin >> N;
	int num;
	s.insert(0);
	s.insert(MAXX-1);
	hasRightChild[0]= true;
	insertCount[0]=-1;
	insertCount[MAXX-1]=-1;
	set<int>::iterator it;
	int justLesserValueNumberSoFar;
	int justHigherValueNumberSoFar;
	for(int n = 1 ; n <= N ; n++)
	{
		scanf("%d",&num);//cin >> num;
		s.insert(num);
		it = s.find(num);
		it--;
		justLesserValueNumberSoFar = *it;
		if(hasRightChild[justLesserValueNumberSoFar] == false)
		{
			insertCount[num] = insertCount[justLesserValueNumberSoFar] + 1;
			hasRightChild[justLesserValueNumberSoFar] = true;
		}
		else
		{
			it++;it++;
			justHigherValueNumberSoFar = *it;
			insertCount[num] = insertCount[justHigherValueNumberSoFar] + 1;
		}
		nCount = nCount+insertCount[num];
		printf("%lld\n",nCount);//cout<<nCount<<endl;
	}
}
