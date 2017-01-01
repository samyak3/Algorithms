#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>anum; 
vector<int>num;
vector<int>cmd;
vector<int>unum;
int Q;
int N; //number of max insertions
FILE* pF;
int bitarray[20001];
bool present[20001];

#define invalid 99999999999
void updateBIT(int pos)
{
	while (pos <= N)
	{
		bitarray[pos]++;
		pos += pos & -pos;
	}
}
void updateBITForDeletion(int pos)
{
//	pos++; 
	while (pos <= N)
	{
		bitarray[pos]--;
		pos += pos & -pos;
	}
}
int getCnt(int pos)
{	
	int cnt = 0;
	while (pos >= 1)
	{
		cnt += bitarray[pos];
		pos -= pos & -pos;
	}
	return cnt;
}
int getpos(int n)
{
	int low = 0;
	int high = N-1;
	
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (unum[mid] == n)
			return mid+1;
		if (unum[mid] < n)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return low;
}
long long  getKthSmallestNumber(int K)
{
	int low = 0;
	int high = N;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		int cnt = getCnt(mid);
		if (cnt == K)
			return unum[mid-1];
		if (cnt < K)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return invalid;
}
int main()
{
	//freopen_s(&pF, "input.txt", "r", stdin);
	cin >> Q;
	int nQ = Q;
	char chcmd;
	int number;
	while (nQ--)
	{
		cin >> chcmd >> number;
		cmd.push_back(chcmd);
		if(chcmd == 'I')
			num.push_back(number);
		anum.push_back(number);
	}
	sort(num.begin(), num.end());
	
	unum.push_back(num[0]);
	int nsize = 1;
	for (unsigned i = 1; i < num.size(); i++)
	{
		if (num[i] != unum[nsize-1])
		{
			unum.push_back(num[i]);
			nsize++;
		}
	}
	N = nsize;
	for (int i = 0; i<Q ; i++)
	{
		chcmd = cmd[i];
		number = anum[i];
		if (chcmd == 'I')
		{
			int pos = getpos(number);
			if (present[pos] == false)
			{
				updateBIT(pos);
				present[pos] = true;
			}
		}
		else if (chcmd == 'D')
		{
			int pos = getpos(number);
			if (present[pos] == true)
			{
				updateBITForDeletion(pos);
				present[pos] = false;
			}
		}
		else if (chcmd == 'C')
		{
			int pos = getpos(number);
			if (present[pos] && (number == unum[pos - 1]))
			{
				cout << getCnt(pos) - 1 << endl;
			}
			else
			{
				cout << getCnt(pos) << endl;
			}
		}
		else if (chcmd == 'K')
		{
			long long  ans = getKthSmallestNumber(number);
			if (ans == invalid)
			{
				cout << "invalid" << endl;
			}
			else
			{
				cout << ans << endl;
			}
		}
		else
		{

		}
	}
	return 0;
}