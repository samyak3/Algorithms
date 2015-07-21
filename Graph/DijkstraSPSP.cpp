#include<iostream>

using namespace std;

#define MD 9999
const int N = 7;
int size = 7;

struct node
{
	int data;
	int d;
	int sd;
	int p;
	node* next;
	int hindex;
};
node* pqueue[7];

node* gg[8];
void heapify(int i , int size);
void heapify2(int i);
void hswap(int i , int j);
int extractMinNode();
void Relax(int source);
int Dijkstra(int source , int dest);
void showhIndex();
int parentsd(int i)
{
	if((i-1)/2 < 0)
	{
		return -1;
	}
	else
	{
		return pqueue[(i-1)/2]->sd;
	}
}

int lchild(int i , int size)
{
	if(2*i+1 > size -1 )
	{
		return MD;
	}
	else
	{
		return pqueue[2*i + 1]->sd;
	}
}

int rchild(int i , int size)
{
	if(2*i+2 > size -1 )
	{
		return MD;
	}
	else
	{
		return pqueue[2*i + 2]->sd;
	}
}

void buildGraph();


void InitSSSP(int source)
{
	gg[source]->sd = 0;
	for(int i = 0; i < 7; i++ )
	{
		pqueue[i] = gg[i+1];
	}
	for(int i = N/2 -1 ;i >=0; i--)
	{
		heapify(i,N);
	}
}

node* getNode(int data, int d)
{
	node* pNode = new node;
	pNode->data = data;
	pNode->d = d;
	pNode->sd = MD;
	pNode->p = 0;
	pNode->next = NULL;
	pNode->hindex = data -1;
	return pNode;
}


int main()
{
	buildGraph();

	InitSSSP(1);

	cout<<"Shorted Path from 1 to 7 is ::"<<Dijkstra(1,7)<<endl;
	return 0;
}
void buildGraph()
{
	node *v1,*v2,*v3,*v4,*v5,*v6,*v7;
	//Node1
	v1 = getNode(1,0);
	v2 = getNode(2,1);
	v3 = getNode(3,2);
	v4 = getNode(4,10);
	v5 = getNode(5,10);
	v6 = getNode(6,10);
	v7 = getNode(7,100);

	v1->next = v2;
	v2->next = v3;
	v3->next = v4;
	v4->next = v5;
	v5->next = v6;
	v6->next = v7;

	gg[1] = v1;

	//Node2
	v1 = getNode(2,0);
	v2 = getNode(1,1);
	v3 = getNode(3,3);
	v4 = getNode(4,4);
	v5 = getNode(5,5);
	v6 = getNode(6,10);
	v7 = getNode(7,10);

	v1->next = v2;
	v2->next = v3;
	v3->next = v4;
	v4->next = v5;
	v5->next = v6;
	v6->next = v7;

	gg[2] = v1;

	//Node3
	v1 = getNode(3,0);
	v2 = getNode(2,3);
	v3 = getNode(1,2);
	v4 = getNode(4,10);
	v5 = getNode(5,10);
	v6 = getNode(6,7);
	v7 = getNode(7,200);

	v1->next = v2;
	v2->next = v3;
	v3->next = v4;
	v4->next = v5;
	v5->next = v6;
	v6->next = v7;

	gg[3] = v1;

	//Node4
	v1 = getNode(4,0);
	v2 = getNode(2,4);
	v3 = getNode(3,10);
	v4 = getNode(1,10);
	v5 = getNode(5,6);
	v6 = getNode(6,10);
	v7 = getNode(7,10);

	v1->next = v2;
	v2->next = v3;
	v3->next = v4;
	v4->next = v5;
	v5->next = v6;
	v6->next = v7;

	gg[4] = v1;

	//Node 5
	v1 = getNode(5,0);
	v2 = getNode(2,5);
	v3 = getNode(3,10);
	v4 = getNode(4,6);
	v5 = getNode(1,10);
	v6 = getNode(6,10);
	v7 = getNode(7,10);

	v1->next = v2;
	v2->next = v3;
	v3->next = v4;
	v4->next = v5;
	v5->next = v6;
	v6->next = v7;

	gg[5] = v1;

	//Node6
	v1 = getNode(6,0);
	v2 = getNode(2,10);
	v3 = getNode(3,7);
	v4 = getNode(4,10);
	v5 = getNode(5,10);
	v6 = getNode(1,10);
	v7 = getNode(7,9);

	v1->next = v2;
	v2->next = v3;
	v3->next = v4;
	v4->next = v5;
	v5->next = v6;
	v6->next = v7;

	gg[6] = v1;
	//Node7
	v1 = getNode(7,0);
	v2 = getNode(2,10);
	v3 = getNode(3,200);
	v4 = getNode(4,10);
	v5 = getNode(5,10);
	v6 = getNode(6,9);
	v7 = getNode(1,100);

	v1->next = v2;
	v2->next = v3;
	v3->next = v4;
	v4->next = v5;
	v5->next = v6;
	v6->next = v7;

	gg[7] = v1;
}
void heapify(int i , int  size)
{
	//cout<<__LINE__<<" "<<__FUNCTION__<<endl;
	if( rchild(i,size) <= lchild(i,size) && pqueue[i]->sd >  rchild(i,size))
	{
		//cout<<__LINE__<<" "<<__FUNCTION__<<endl;
		hswap(i,2*i+2);
		heapify(2*i+2,size);
	}
	else
	{
		if( lchild(i,size) <= rchild(i,size) && pqueue[i]->sd >  lchild(i,size))
		{
			//cout<<__LINE__<<" "<<__FUNCTION__<<endl;
			hswap(i,2*i+i);
			heapify(2*i+1,size);
		}

	}

}
void hswap(int i , int j)
{
	node* temp = pqueue[j];
	pqueue[j] = pqueue[i];
	pqueue[i] = temp;
#if 0
	pqueue[j]->hindex = i;
	pqueue[i]->hindex = j;
#else
	//cout<<endl<<"swapping nodes ::"<<gg[pqueue[i]->data]->data<<" and "<<gg[pqueue[j]->data]->data<<endl;
	//cout<<"i = "<<i<<" hindex = "<<gg[pqueue[i]->data]->hindex<<endl;
	//cout<<"j = "<<j<<" hindex = "<<gg[pqueue[j]->data]->hindex<<endl;
	gg[pqueue[j]->data]->hindex = j;
	gg[pqueue[i]->data]->hindex = i;
	//showhIndex();
#endif
}
int Dijkstra(int source , int dest)
{
	showhIndex();
	while(1)
	{
		int xnodeData = extractMinNode();
		//	cout<<"xnodeData :: "<<xnodeData<<endl;
		if(xnodeData == dest)
		{
			break;
		}
		else
		{

		}
	}
	return gg[dest]->sd;
}
int extractMinNode()
{
	int minNode = pqueue[0]->data;
	cout<<__LINE__<<" "<<__FUNCTION__<<" minNode :: "<<minNode<<endl;
	size--;
	pqueue[0] = pqueue[size];
	gg[pqueue[0]->data]->hindex = 0;
	//showhIndex();
	//heapify(0,size);
	Relax(minNode);
	heapify(0,size);
	showhIndex();
	return minNode;
}
void Relax(int source)
{
	node* temp = gg[source];
	node* stemp = gg[source];
	while(temp->next)
	{
		//cout<<__LINE__<<" "<<__FUNCTION__<<endl;
		node* nNode = gg[temp->next->data];
		if(nNode->sd > stemp->sd + temp->next->d)
		{
			nNode->sd = stemp->sd + temp->next->d;
			cout<<" sd updated for "<<nNode->data<<" to "<<nNode->sd<<endl;
			heapify2(nNode->hindex);
		}
		temp = temp->next;
	}
}
void heapify2(int i)
{
	if(i <1)
		return;

	if( parentsd(i) >  pqueue[i]->sd )
	{
		hswap(i,(i-1)/2);
		heapify2((i-1)/2);
	}
}
void showhIndex()
{
	for(int i = 0; i < N ; i++)
	{
		cout<<endl<<"data ::"<<pqueue[i]->data<<" hIndex :: "<<gg[pqueue[i]->data]->hindex<<endl;
	}
}
