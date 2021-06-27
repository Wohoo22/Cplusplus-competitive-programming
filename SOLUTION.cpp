#include "bits/stdc++.h"
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INP freopen("SOLUTION.INP", "r", stdin);
#define ll long long
#define MOD 1000000007
#define CHARNT \
    int char_int(char c) { return c - 'a'; }
#define CUTLAST \
    int cut_last(int x, int n) { return x % (int)pow(10, n); }
#define INTCHR \
    char int_char(int i) { return "abcdefghijklmnopqrstuvwxyz"[i]; }
/*
    RANDOM:
    rand() % (max – min + 1)
*/

vector<Prod> prods;

class Prod
{
public:
    ll id;
    ll req;
    ll disc;
};

Prod create(ll id, ll req, ll disc)
{
    Prod p;
    p.id = id;
    p.req = req;
    p.disc = disc;
    return p;
}

void solve()
{
    ll n;
    cin >> n;

    prods.push_back(create(0, 0, 0));

    for (ll i = 1; i < n; i++)
    {
        ll req, disc;
        cin >> req >> disc;
        prods.push_back(create(i, req, disc));
    }

    
}

int main()
{
    FAST;
#ifndef ONLINE_JUDGE
    INP;
#endif
    int t = 1;
    while (t--)
        solve();
    return 0;
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/