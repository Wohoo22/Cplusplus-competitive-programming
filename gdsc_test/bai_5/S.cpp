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

int n, k;
vector<int> a;
set<int> ele;
map<int, bool> visited; 
int close;

bool exist(int val) {
    return ele.find(val) != ele.end();
}

bool open(int u) {
    visited[u] = true;
    bool is_open = true;
    if (exist(u - k) && !visited[u - k]) {
        if (open(u - k))
            is_open = false;
    }
    if (exist(u + k) && !visited[u + k]) {
        if (open(u + k))
            is_open = false;
    }
    if (is_open == false)
        close++;

    return is_open;
}

void solve(int tc)
{
    cin >> n >> k;
    a.clear();
    for (int i=0; i<n; i++) {
        int c; cin >> c;
        a.push_back(c);
    }
    ele.clear();
    for (auto &e : a)
        ele.insert(e);
    visited.clear();
    for (auto &e : a)
        visited[e] = false;
    int ans = 0;
    for (auto &e : a) {
        if (!visited[e]) {
            close = 0;
            open(e);
            ans += close;
        }
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    // INP;
    // freopen("S.OUT", "w", stdout);
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