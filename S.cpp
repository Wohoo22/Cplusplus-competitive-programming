#include "bits/stdc++.h"
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INP freopen("S.INP", "r", stdin);
#define ll long long
#define MOD 1000000007
#define CHARNT \
    int char_int(char c) { return c - 'a'; }
#define CUTLAST \
    int cut_last(int x, int n) { return x % (int)pow(10, n); }
#define INTCHR \
    char int_char(int i) { return "abcdefghijklmnopqrstuvwxyz"[i]; }

ll dist(ll x1, ll y1, ll x2, ll y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve()
{
    ll n, m, i, j;
    cin >> n >> m >> i >> j;

    ll c[4][2];

    c[0][0] = 1;
    c[0][1] = 1;

    c[1][0] = 1;
    c[1][1] = n;

    c[2][0] = m;
    c[2][1] = n;

    c[3][0] = m;
    c[3][1] = 1;

    ll max_dist = -1;
    ll c1 = 0;
    ll c2 = 0;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
        {
            ll dis = dist(j, i, c[i][0], c[i][1]) + dist(c[i][0], c[i][1], c[j][0], c[j][1]) + dist(c[j][0], c[j][1], j, i);
            if (dis >= max_dist)
            {
                c1 = i;
                c2 = j;
                max_dist = dis;
            }
        }
    cout << c[c1][1] << " " << c[c1][0] << " " << c[c2][1] << " " << c[c2][0] << endl;
}

int main()
{
    FAST;
    // INP;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
    /* [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
    */
}