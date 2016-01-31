/*
 * BUSYMAN - I AM VERY BUSY.cpp
 *
 *  Created on: Oct 24, 2015
 *      Author: Admin
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Atime
{
	int start;
	int end;
};
vector<Atime> v;
int C;
int N;
class comp
{
public:
	bool operator()(const Atime& a,const Atime& b)
	{
		if(a.end < b.end)//strict weak ordering else seg fault
		{
			return true;
		}
		return false;
	}
};
int main()
{
	cin >> C;
	for(int c =1 ; c <= C ; c++)
	{
		cin >> N;
		int s;
		int e;
		Atime stAtime;
		for(int n = 1 ; n <= N ; n++)
		{
			cin >> s >> e;
			stAtime.start = s;
			stAtime.end = e;
			v.push_back(stAtime);
		}
		sort(v.begin(),v.end(),comp());
		int ans = 1;
		int cend = v[0].end;
		for(int i = 1 ; i < v.size();i++)
		{
			if(cend <= v[i].start)
			{
				ans += 1;
				cend = v[i].end;
			}
		}
		cout<<ans<<endl;
		v.clear();
	}
}
