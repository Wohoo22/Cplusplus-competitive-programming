#include "bits/stdc++.h"
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INP freopen("CORRECT.INP", "r", stdin);
#define OUT freopen("CORRECT.OUT", "w", stdout);
#define ll long long
#define MOD 1000000007
#define CHARNT \
    int char_int(char c) { return c - 'a'; }
#define CUTLAST \
    int cut_last(int x, int n) { return x % (int)pow(10, n); }
#define INTCHR \
    char int_char(int i) { return "abcdefghijklmnopqrstuvwxyz"[i]; }

void solve()
{
}

int main()
{
    FAST;
    INP;
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