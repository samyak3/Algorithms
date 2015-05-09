#include<iostream>
using namespace std;

int d[] = {1,2,3,5,10};
const int typesOfCoins = 5;
const int N = 501;

int dpways[N+1][typesOfCoins+1];

int tdways[N+1][typesOfCoins+1];

//DP
void updateTable()
{
	for(int j = 0; j <= typesOfCoins ; j++)
	{
		dpways[0][j]= 1;
	}
	for(int i = 1; i <= N ; i++)
	{
		dpways[i][0]= 0;
	}
	for(int i = 1; i <= N ; i++)
	{
		for(int j = 1; j <= typesOfCoins ; j++)
		{
			if(i-d[j-1] >= 0)
				dpways[i][j] = dpways[i-d[j-1]][j] + dpways[i][j-1];
			else
				dpways[i][j] = dpways[i][j-1];
		}
	}
}
//Recursive 
int ways(int sum , int index)
{
	
	if(sum == 0)
	{
		return 1;
	}
	else if(sum < 0 || index <= 0 )
	{
		return 0;
	}
	if(tdways[sum][index])
	{
		return tdways[sum][index];
	}
	else
	{
		tdways[sum][index] =  ways(sum - d[index-1], index) + ways(sum,index - 1) ;
		return tdways[sum][index];
	}		
}

int main()
{
	

	updateTable();
	cout<<"DP :: No of ways to give a sum of value "<<N<<" is ::"<<dpways[N][typesOfCoins]<<endl<<endl;
	
	cout<<"Recursive :: No of ways to give a sum of value "<<N<<" is ::"<<ways(N,typesOfCoins)<<endl<<endl;
	return 0;
}