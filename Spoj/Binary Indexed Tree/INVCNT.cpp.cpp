#include <iostream>
#include<vector>
typedef long long ll;
using namespace std;
ll N ;
vector<ll>v;
vector<ll>vb;
ll maxx=-1;
ll CheckFor(ll val )
{

	ll sum = 0;
	while(val >= 1)
	{
		sum += vb[val];
		val -= val & (-val);
	}
	return sum;
}
void update(ll index , int val)
{
	while(index <= maxx)
	{
		vb[index] += val;
		index += index & -index;
	}

}
int main() {
	int C;
	cin >> C;
	ll var;

	for(int c =1 ; c <= C ; c++)
	{
		cin >> N ;
		v.push_back(0);
		maxx = -1;
		for(ll i = 1 ; i <= N ; i++)
		{
			cin >> var;
			if(maxx < var)
				maxx = var;
			v.push_back(var);
		}
		for(ll i = 0 ; i <= maxx+2; i++)
		{
			vb.push_back(0);
		}
		ll sum = 0;
		for(ll i = N ; i >= 1 ; i--)
		{
			sum +=  CheckFor(v[i]-1);
			update(v[i],1);
		}
		cout<<sum<<endl;
		v.clear();
		vb.clear();
	}

	return 0;
}
