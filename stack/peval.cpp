#include<iostream>
#include<stack>
#include<string>
#include<map>

using namespace std;

map<char,int>op;

void doPost(string exp);
void peval(void);
string pexp;
int main()
{
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
	//	string exp = "a+b*c/d^e";
	string exp;// = "4+2*3";
	cin >> exp;
	//	string exp = "a*b*c+d";
	//	string exp = "a+b-c";
	cout<<"infix -- "<<exp<<endl;
	cout<<"postfix-- ";
	doPost(exp);
	peval();
	cout<<endl;
	return 0;
}

void doPost(string exp)
{
	int i = 0;
	stack<char>s;
	while(i < exp.size())
	{
		if(exp[i] >= 49 && exp[i] <= 57)
		{
			cout<<exp[i];
			pexp.push_back(exp[i]);
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
							pexp.push_back(s.top());
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
				if(op[exp[i]] > op[s.top()])
				{
					s.push(exp[i]);
				}
				else
				{
					while(!s.empty() && op[s.top()] >= op[exp[i]])
					{
						cout<<s.top();
						pexp.push_back(s.top());
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
		pexp.push_back(s.top());
		s.pop();
	}

}
void peval()
{
	stack<int>pr;
	int i = 0;
	while(i < pexp.size())
	{
		if(pexp[i] >= 49 && pexp[i] <= 57)
		{
			pr.push(pexp[i]);
		}

		if(pexp[i] < 49 || pexp[i] > 57)
		{
			int b = pr.top();
			b = b - 48;
			pr.pop();
			int a = pr.top();
			pr.pop();
			a = a- 48;
//			cout<<"a -- "<<a<<endl;
//			cout<<"b -- "<<b<<endl;
			int c =0;
			switch(pexp[i])
			{
				case '+' :
					pr.push(a+b+48);
					c= a+b+48;
					break;
				case '-' :
					pr.push(a-b+48);
					c= a-b+48;
					break;
				case '*' :
					pr.push(a*b+48);
					c= a*b+48;
					break;
				case '/' :
					pr.push(a/b+48);
					c= a/b+48;
					break;
				case '^' :
					pr.push(a^b+48);
					c = a^b+48;
					break;
			}
			cout<<"pushing -- "<<c<<endl;
		}
		i++;
	}
	cout<<endl<<"Answer :: ";
	cout<<pr.top()-48<<endl;
}
