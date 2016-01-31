/*
 * HOTELS - Hotels Along the Croatian Coast.cpp
 *
 *  Created on: Oct 31, 2015
 *      Author: Admin
 */

//Concept : sliding window; Kadane's Algo
typedef unsigned long long ull;
ull N;//number of Hotels
ull M;//max value of hotels that can bought

#include<iostream>
#include<vector>
using namespace std;

vector<int> hotelValue;
ull ans;

int main()
{
	cin >> N >> M;

	hotelValue.push_back(0);

	int val;

	for(int i = 1; i <= N ; i++)
	{
		cin >> val;
		hotelValue.push_back(val);
	}
	int leftPos = 1;
	ull sum=0;

	for(int i = 1 ; i <= N ; i++)
	{
		sum = sum + hotelValue[i];
		if(sum <= M)
		{
			if(ans < sum )
			{
				ans = sum;
			}
		}
		else
		{
			while(1)
			{
				sum = sum - hotelValue[leftPos];
				leftPos += 1;
				if(sum <= M)
				{
					if(ans < sum )
					{
						ans = sum;
					}
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
}
