/*
The Bogus Corporation distributes salary to its employees in a weird manner. The salary is distributed every K days,  and instead of same salary for
each day, the salary for the ith day is ai. An ambitious young manager, fresh from Institute of Mismanagement, observes that people usually prefer to
 take leave towards the end of this period of K days, when the workload is higher. Instead of revising each of the ai's, the manager comes up with a
 quick fix solution - he redefines the new salary on the ith day as bi=ai+2ai-1+22ai-2+23ai-3+........+2i-1a1 . Baba, one of the employees, is in a
 dire financial crisis, and must accumulate at least N rupees at the end of the forthcoming period. Being a lazy worker that he is, he is interested in
 finding out if attending particular days would guarantee him exactly  N rupees at the end of the period. Can you help Baba?

Input

First line contains a single integer integer T, the number of test cases ( 1<=T<=100). Each test case is described on two lines.
 First line contains two integers, N and K ( 1<=N<=263-1, 1<=K<=50) ,
 the second line contains a space separated list of K integers, the ai's ( 1<=ai<=1000).

Output

For each test case, output on a single line 1-based indices of the days (separated by a single space) he should attend to ensure a salary of exactly N
rupees at the end of the period. The indices should be printed in the sorted order. In case of multiple answers,
output any one of them. If there is no answer, print -1.
 */
#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long ull;
ull N;
short K;
int Salary[51];
ull revisedSalary[51];
vector<int> days;
#define NO_ANSWER -1;
int main()
{

   int C;//number of testcases
   cin >> C;
   for(int c = 1 ; c <= C; c++)
   {
	   cin >> N >> K;
       for(int n = 1; n <= K ; n++)
       {
           cin>>Salary[n];

           revisedSalary[n] = revisedSalary[n-1]*2 + Salary[n];
       }


       //Make a greeedy choice
       for(int i = K; i >= 1; i--)
       {
           if(revisedSalary[i]<=N)
           {
               days.push_back(i);
               N = N - revisedSalary[i];
           }
       }

       if(N > 0)
       {
           cout<<NO_ANSWER;
       }
       else
       {
           for(int j = days.size()-1; j >= 0; j--)
           {
        	   cout<<days[j]<<" ";
           }
       }
       days.clear();
       cout<<endl;
   }

   return 0;
}
