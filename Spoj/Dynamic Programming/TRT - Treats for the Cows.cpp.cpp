#include <iostream>
#include<vector>
using namespace std;
vector<int>v;
int ans[2001][2001];
int f(int s , int e , int age)
{
	if(s == e)
		return v[e]*age;
	
	if(ans[s][e])
	{
		return ans[s][e];
	}
	
	ans[s][e] =  max(v[s]*age + f(s+1,e,age+1) , v[e]*age + f(s,e-1,age+1));
	return ans[s][e];
}
int main() {
	// your code goes here
	int num;
	
	cin >> num;
	int val;
	for(int i = 1 ; i <= num ; i++)
	{
		cin >> val;
		v.push_back(val);
	}
	cout<<f(0,v.size()-1,1)<<endl;
	return 0;
}