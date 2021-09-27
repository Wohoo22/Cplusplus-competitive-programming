#include "bits/stdc++.h"
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INP freopen("S.INP", "r", stdin);
#define OUT freopen("S.OUT", "w", stdout);
#define ll long long
#define modd 1000000007
ll get_last(int x, int n) { 
    return x % (int)pow(10, n); 
}
ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp % 2 == 1) 
            res = (res * base) % modd;
        exp >>= 1;
        base = (base * base) % modd;
    }
    return res;
}
ll madd(ll a, ll b) {
    return (a + b) % modd;
}
ll msub(ll a, ll b) {
    return (((a - b) % modd) + modd) % modd;
}
ll mmul(ll a, ll b) {
    return ((a % modd) * (b % modd)) % modd;
}

/* ---------------------------------- END TEMPLATE ---------------------------------- */

void solve(int tc)
{
}

int main()
{
    FAST;
#ifndef ONLINE_JUDGE
    INP;
#endif
    int t = 1;
    cin >> t;
    for (int i=1; i<=t; i++)
        solve(i);
    return 0;
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/
