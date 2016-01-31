#include <iostream>
#include<stack>
using namespace std;
int nsize;
int main() {
	// your code goes here
	
	while(1)
	{
		cin >> nsize;
		if(nsize == 0)
			break;
	
		stack<int>s;
		int var;
		int index = 1;
		int scanned=0;
		while(scanned < nsize)
		{
			cin >> var;// = arr[scanned];
			scanned++;
			if(var != index )
			{
				//cout<<"push ::"<<var<<endl;
				s.push(var);
			}
			else
			{
				index++;
			}
			
		
			while(1)
			{
				if(s.empty())
					break;
				if(s.top() == index)
				{
					//cout<<"index :: "<<index<<endl;
					index++;
					s.pop();
				}
				else
				{
					break;
				}
			}
		}
		if(s.empty() == true)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}