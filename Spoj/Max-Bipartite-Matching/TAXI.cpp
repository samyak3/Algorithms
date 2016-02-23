#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
vector<vector<int> >v;
int nCases;
#define MAX_NUMBER_OF_PASSENGERS 401
#define MAX_NUMBER_OF_TAXIS 201
#define NO_TAXI -1
#define NO_PASSENGER -1
int whichTaxi[MAX_NUMBER_OF_PASSENGERS];
int whichPassenger[MAX_NUMBER_OF_TAXIS];

int visited[MAX_NUMBER_OF_PASSENGERS];

int nPassengers , nTaxis , nSpeed , nTime;

struct point
{
	int x;
	int y;
	point()
	{
		x = 1;
		y = 1;
	}
	point(int a , int b)
	{
		x = a;
		y = b;
	}
};
typedef struct point Point;

Point pLocation[MAX_NUMBER_OF_PASSENGERS];
Point tLocation[MAX_NUMBER_OF_TAXIS];
int x , y;
void resetVisited()
{
	for(int i = 0 ; i <= nPassengers;i++)
	{
		visited[i]=0;
	}
}
void resetAssignments()
{
	for(int i = 0 ; i < MAX_NUMBER_OF_PASSENGERS ;i++)
	{
		whichTaxi[i]=-1;
	}
	for(int i = 0 ; i < MAX_NUMBER_OF_TAXIS ;i++)
	{
		whichPassenger[i]=-1;
	}
}
bool Reachable(Point p , Point t)
{
	int dis = (abs(p.x - t.x) + abs(p.y - t.y))*200;
	int timeRequired = dis/nSpeed;
	if(nTime >= timeRequired)
	{
		return true;
	}
	return false;
}

bool HireTaxi(int pNum)
{
	if(visited[pNum] == 1)
	{
		return false;
	}
	visited[pNum] = 1;

	for(int i = 0 ; i < v[pNum].size() ; i++)
	{
		int taxiNumber = v[pNum][i];
		if(whichPassenger[taxiNumber] == NO_PASSENGER)
		{
			whichPassenger[taxiNumber]= pNum;
			whichTaxi[pNum] = taxiNumber;
			return true;
		}
	}
	for(int i = 0 ; i < v[pNum].size() ; i++)
	{
		int taxiNumber = v[pNum][i];
		int passengerAssigned = whichPassenger[taxiNumber];
		if(HireTaxi(passengerAssigned))
		{
			whichPassenger[taxiNumber]= pNum;
			whichTaxi[pNum] = taxiNumber;
			return true;
		}
	}
	return false;//No new assignment could me made to this passenger
}
void process()
{
	bool bNewAssignmentMade = false;
	while(1)
	{
		resetVisited();
		for(int i = 0 ; i < nPassengers; i++)
		{
			if(whichTaxi[i] == NO_TAXI && HireTaxi(i))
			{
				bNewAssignmentMade = true;
			}
		}
		if(bNewAssignmentMade == false)
		{
			break;
		}
		bNewAssignmentMade = false;
	}
	int answer = 0;
	for(int i = 0 ;i < nPassengers;i++ )
	{
		if(whichTaxi[i] != NO_TAXI)
		{
			answer++;
		}
	}
	cout<<answer<<endl;
}

int main()
{
	//freopen("taxi.txt","r",stdin);
	cin >> nCases;

	while(nCases--)
	{
		cin >> nPassengers >> nTaxis >> nSpeed >> nTime;
		for(int i = 0 ; i < nPassengers ; i++)
		{
			cin >> x >> y;
			Point pt(x,y);
			pLocation[i]= pt;
		}
		for(int i = 0 ; i < nTaxis ; i++)
		{
			cin >> x >> y;
			Point pt(x,y);
			tLocation[i]= pt;
		}
		resetAssignments();
		for(int i = 0 ; i < nPassengers ; i++)
		{
			vector<int>taxiNumber;
			for(int j = 0 ; j < nTaxis; j++)
			{
				if(Reachable(pLocation[i],tLocation[j]))
				{
					taxiNumber.push_back(j);
				}
			}
			v.push_back(taxiNumber);
		}
		process();
		v.clear();
	}
}
