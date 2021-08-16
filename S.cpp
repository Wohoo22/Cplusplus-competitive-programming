#include "bits/stdc++.h"
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INP freopen("S.INP", "r", stdin);
#define ll long long
#define MOD 1000000007
#define CI \
    int ci(char c) { return c - 'a'; }
#define CUTLAST \
    int cut_last(int x, int n) { return x % (int)pow(10, n); }
#define IC \
    char ic(int i) { return "abcdefghijklmnopqrstuvwxyz"[i]; }
/*
    RANDOM:
    rand() % (max – min + 1)
*/


ll power(ll x, int y, int p)
{
	ll res = 1;
	x = x % p; 
	while (y > 0) {
		if (y & 1) res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

ll mod_inverse(ll n, int p)
{
	return power(n, p - 2, p);
}

ll ncr(ll n, int r, int p)
{
	if (n < r) return 0;
	if (r == 0) return 1;
	ll fac[n + 1]; fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % p;
	return (fac[n] * mod_inverse(fac[r], p) % p * mod_inverse(fac[n - r], p) % p) % p;
}
void solve()
{
    ll n, k;
    cin >> n >> k;

    if (n % 2 == 0) {
        ll ans = 1;
        for (ll i=0; i<=n-1; i+=2) {

        }
    }
}

int main()
{
    FAST;
#ifndef ONLINE_JUDGE
    INP;
#endif
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/