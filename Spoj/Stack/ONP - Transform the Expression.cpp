#include<iostream>
#include<stack>
#include<string>
#include<map>
#include<stdio.h>
using namespace std;

map<char,int>op;

void doPost(string exp);
int main()
{
//	freopen("input","r",stdin);
	char moptr = '*';
	char aoptr = '+';
	char soptr = '-';
	char doptr = '/';
	char poptr = '^';

	op[moptr]=2;
	op[aoptr]=1;
	op[soptr]=1;
	op[doptr]=2;
	op[poptr]=3;
	int C=0;
	cin >>C ;
	string exp;
	for(int c= 1 ; c <= C ; c++)
	{
		cin >> exp;
		doPost(exp);
		cout<<endl;
	}

	return 0;
}

void doPost(string exp)
{
	int i = 0;
	stack<char>s;
	while(i < exp.size())
	{
		if(exp[i] >= 97 && exp[i] <= 122)
		{
			cout<<exp[i];
		}
		else
		{
			if(s.empty() == true)
			{
				s.push(exp[i]);
			}
			else
			{
				if(exp[i] == '(')
				{
					s.push(exp[i]);
					i++;
					continue;
				}
				if(exp[i] == ')')
				{
					while( !s.empty() )
					{
						if(s.top() != '(')
						{
							cout<<s.top();
							s.pop();
						}
						else
						{
							s.pop();
							break;
						}
					}
					i++;
					continue;
				}
				if(op[exp[i]] >= op[s.top()])
				{
					s.push(exp[i]);
				}
				else
				{
					while(!s.empty() && op[s.top()] > op[exp[i]])
					{
						cout<<s.top();
						s.pop();
					}
					s.push(exp[i]);
				}
			}
		}
		i++;
	}
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}

}