/*
You are given scales for weighing loads. On the left side lies a single stone of known weight W<2N.
You own a set of N different weights, weighing 1, 2, 4, ..., 2N-1 units of mass respectively.
 Determine how many possible ways there are of placing some weights on the sides of the scales,
  so as to balance them (put them in a state of equilibrium). Output this value modulo a small integer D.

Input

The input begins with the integer t, the number of test cases. Then t test cases follow.

For each test case, the first line contains three integers: N L D, where N denotes the number of weights at your disposal,
L is the length of the binary representation of number W, and D is the modulus (1<= L<= N<= 1000000, 2<= D<=100).
The second line contains the value of W, encoded in the binary system as a sequence of exactly L characters 0 or 1 without separating spaces.

Output

For each test case, output a single line containing one integer - the calculated number of possible weight placements, modulo D.
*/
#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long ull;
//Top Down Approach
/*
 int f(int index, int lW , int rW)
{
	if(index == N)
	{
		if(lW == rW)
		{
			return 1;
		}
		else
			return 0;
	}
	int a = 1;
	int b = a << index ;
	int w = W&(a << index) ? a << index : 0;
	return f(index+1 ,lW + b ,rW+w) + f(index+1 ,lW , rW + w + b ) + f(index+1,lW,rW+w);
}
 */
int main()
{
	//cout<<f(0,0,0);//top down gives TLE !!!
	int C;
	cin >> C;
	for(int c = 1 ; c <= C ; c++)
	{
		int N , L , D;
		string W;
		cin >> N >> L >> D >> W;
		vector<ull>balanced;
		vector<ull>unbalanced;
		for(int n = 0 ; n <= N ; n++)
		{
			balanced.push_back(0);
			unbalanced.push_back(0);
		}
		balanced[0]=1;
		for(int n = 1 ; n <=N ; n++)
		{
			if(L - n < 0 || W.at(L-n) == '0')
			{
				balanced[n] = (balanced[n-1] + unbalanced[n-1])%D;
				unbalanced[n] = (unbalanced[n-1])%D;
			}
			else
			{
				balanced[n] = (balanced[n-1])%D;
				unbalanced[n] = (balanced[n-1] + unbalanced[n-1])%D;
			}
		}
		cout<<balanced[N]<<endl;
	}
	return 0;
}
