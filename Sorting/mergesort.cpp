#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int d[] = {7,3,1,5,2,6,4,8};
void msort(int*,int s);
void conquer(int*,int s1,int*,int);

int main()
{
	cout<<"before sorting"<<endl;
	for(int i = 0; i <=7 ; i++)
	{
		cout<<d[i]<<"\t";
	}
	msort(d,8);
	
	cout<<"after sorting"<<endl;
	for(int i = 0; i <=7 ; i++)
	{
		cout<<d[i]<<"\t";
	}
	cout<<endl;
	return 0;
}	
void msort(int* p, int s)
{
	if(s == 1)
	return;
	else
	{
		msort(p,s/2);
		msort(p+s/2,ceil(float(s)/2.0));
		conquer(p,s/2,p+s/2,ceil(float(s)/2.0));
	}
}

void conquer(int* p1, int s1, int* p2, int s2)
{
	int c1 = s1;
	int c2 = s2;
	int* p = (int*)malloc(sizeof(int)*(s1+s2+1));
	int *sptr = p;
	int *dptr = p1;
//	cout<<" *p1 -- "<<*p1<<" s1 -- "<<s1<<" *p2 --"<<*p2<<" s2 -- "<<s2<<endl;
	while(c1 != 0 && c2 != 0)
	{
		if(*p1 <= *p2)
		{
			*p = *p1;
			p++;
			c1--;
			if(c1!=0)
				p1++;
		}
		else
		{
			//			cout<<"*p2 -- "<<*p2<<endl;
			*p = *p2;
			p++;
			c2--;
			if(c2!=0)
				p2++;
		}
	}
	if(c1==0)
	{
		for(int i = 1; i <= c2; i++)
		{
			*p=*p2;
			p++;
			p2++;
		}
	}
	else
	{
		for(int i = 1; i <= c1; i++)
		{
			*p=*p1;
			p++;
			p1++;
		}

	}
	for(int i = 0; i <s1+s2 ; i++)
	{
		*(dptr+i) = *(sptr+i);
		//cout<<*(dptr+i)<<"\t";
		//		cout<<*(sptr+i)<<"\t";
	}
	free(sptr);
	cout<<endl;
}
