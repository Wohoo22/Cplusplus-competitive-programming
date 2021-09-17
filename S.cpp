#include "bits/stdc++.h"
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INP freopen("S.INP", "r", stdin);
#define OUT freopen("S.OUT", "w", stdout);
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

vector<int> vals;
vector<int> adj[20000];

int dfs(int u, int par, int depth) {
    int child = 0;
    for (auto &v : adj[u]) 
        if (v != par) 
            child += dfs(v, u, depth + 1) + 1;
    vals.push_back(depth - child);
    return child + 1;
}

void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    sort(vals.begin(), vals.end());
    int rm = n - k;
    int ans = 0;
    for (int i=vals.size() - 1; i>=0; i--) {
        if (rm <= 0) break;
        ans += vals[i];
        rm--;
    }   
    cout << ans;
}

int main()
{
    FAST;
#ifndef ONLINE_JUDGE
    INP;
#endif
    int t = 1;
    for (int i=1; i<=t; i++)
        solve(i);
    return 0;
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/