#include <iostream>
using namespace std;

int N;

int a[25];

int f(int pval , int cindex , int len)
{
	if(cindex == N+1)
	{
		return len;
	}
	if(a[cindex] > pval)
	{
		return max( f(a[cindex],cindex+1,len+1) , f(pval , cindex+1 , len));
	}
	return f(pval , cindex+1 , len);
	
}
int main() {
	cin >> N;
	int num;
	for(int i = 1 ; i <= N ; i++)
	{
		cin >> num ;
		a[i] = num;
	}
	cout<<f(0,1,0)<<endl;
	return 0;
}