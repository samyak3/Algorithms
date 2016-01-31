#include <iostream>
#include<vector>
using namespace std;
int K[2002][2002]={0};
int  W , N ;
int main() 
{
	cin >> W >> N;
	
	vector<int>w;
	
	vector<int>v;
	
	w.push_back(0);
	
	v.push_back(0);
	int nw,nv;
	for(int i = 1 ; i <= N ; i++)
	{
		cin >> nw >> nv;
		w.push_back(nw);
		v.push_back(nv);
	}
	for(int i = 1 ; i <= N; i++ )
	{
		for(int j = 1 ; j <= W; j++)
		{
			if(w[i] <= j)
			K[i][j]  = max(v[i] + K[i-1][j -w[i]],K[i-1][j]);
			else
			K[i][j] = K[i-1][j];
		}
	}
	cout<<K[N][W];
	return 0;
}