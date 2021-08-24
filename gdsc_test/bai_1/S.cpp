#include "bits/stdc++.h"
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INP freopen("S.INP", "r", stdin);
#define ll long long
#define mod 1000000007
ll get_last(int x, int n) { 
    return x % (int)pow(10, n); 
}
ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp % 2 == 1) 
            res = (res * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return res;
}
ll madd(ll a, ll b) {
    return (a + b) % mod;
}
ll msub(ll a, ll b) {
    return (((a - b) % mod) + mod) % mod;
}
ll mmul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

/* ---------------------------------- END TEMPLATE ---------------------------------- */

void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];
    set<int> ele;
    for (auto &e : a)
        ele.insert(e);
    int ans = 0;
    for (auto &e : a)
        if (ele.find(e - k) != ele.end())
            ans++;
    cout << ans << endl;
}

int main()
{
    FAST;
    // INP;
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