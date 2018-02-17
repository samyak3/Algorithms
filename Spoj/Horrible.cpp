#if 1
#include<iostream>
using namespace std;
#define MAX_LEN 1000001
typedef unsigned long long ll;
ll N;
ll H;
ll d[MAX_LEN];
ll seg[2 * MAX_LEN];
ll getNext(ll N)
{
	ll bitnum = 0;
	while (N / (1 << bitnum))
	{
		if (N % (1 << bitnum) == 0 && bitnum)
			return N;
		bitnum++;
	}
	return  1 << bitnum;
}
void init()
{
	for (ll i = 0; i <= 2 * N; i++)
	{
		if (i <= N)d[i] = 0;
		seg[i] = 0;
	}
}
void down(ll cIndex)
{
	//here we want all parents of cIndex to push changes to their children so query function will have updated seg values to get answer
	ll s = H - 1;
	ll p = cIndex >> s;
	ll intervalSize = (1 << (H - 2));
	while (p < N)
	{
		if (d[p])
		{
			seg[2 * p] += d[p] * intervalSize;
			d[2 * p] += d[p];
			seg[2 * p + 1] += d[p] * intervalSize;
			d[2 * p + 1] += d[p];
			d[p] = 0;
		}
		s--;
		p = cIndex >> s;
		intervalSize = intervalSize / 2;
	}

}
void up(ll cIndex)
{
	ll p = cIndex / 2;
	ll intervalSize = 2;
	while (p >= 1)
	{
		seg[p] = seg[2 * p] + seg[2 * p + 1] + d[p] * intervalSize;
		p = p / 2; intervalSize = intervalSize * 2;
	}
}
void inc(ll l, ll r, ll val)
{
	l = l + N;
	ll lorg = l;
	r = r + N;
	ll rorg = r - 1;
	ll intervalSize = 1;
	while (l < r)
	{
		if (l & 1)
		{
			seg[l] += intervalSize*val;
			if (l < N)d[l] += val;
			l++;
		}
		if (r & 1)
		{
			seg[r - 1] += intervalSize*val;
			if (r < N)d[r - 1] += val;
			r--;
		}
		l = l / 2;
		r = r / 2;
		intervalSize = intervalSize * 2;
	}
	up(lorg);
	up(rorg);
}
ll query(ll l, ll r)
{
	ll ans = 0;
	l = l + N;
	r = r + N;
	down(l);
	down(r - 1);

	while (l < r)
	{
		if (l & 1)
		{
			ans += seg[l];
			l++;
		}
		if (r & 1)
		{
			ans += seg[r - 1];
			r--;
		}
		l = l / 2;
		r = r / 2;
	}
	return ans;
}
FILE* pF = 0;
ll getHeight(ll n)
{
	ll height = 0;
	ll num = 1;
	while (n / num)
	{
		height++;
		num = num << 1;
	}
	return height;
}

int main()
{
	//freopen_s(&pF, "input.txt", "r", stdin);
	ll C = 0;
	cin >> C;
	ll nCmd = 0;
	ll op = 0;
	ll l = 0;
	ll r = 0;
	ll val = 0;
	while (C--)
	{
		cin >> N >> nCmd;
		H = getHeight(N);
		N = getNext(N);
		init();
		while (nCmd--)
		{
			cin >> op;
			if (op)
			{
				cin >> l >> r;
				cout << query(l - 1, r) << endl;
			}
			else
			{
				cin >> l >> r >> val;
				inc(l - 1, r, val);
			}
		}
	}
}
#endif