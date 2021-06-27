#include "bits/stdc++.h"
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define OUT freopen("CORRECT.INP", "w", stdout);
#define ll long long
#define MOD 1000000007
#define CHARNT \
    int char_int(char c) { return c - 'a'; }
#define CUTLAST \
    int cut_last(int x, int n) { return x % (int)pow(10, n); }
#define INTCHR \
    char int_char(int i) { return "abcdefghijklmnopqrstuvwxyz"[i]; }

INTCHR;

void tc()
{
    ll lo = 2;
    ll hi = 10;

    ll n = rand() % (hi - 2 - lo + 1) + 1;
    ll k = rand() % (hi - lo + 1) + 1;
    
    cout << n << " " << k << endl;
    for (int i = 0; i < n; i++)
    {
        int l = rand() % (24 + 1) + 1;
        cout << int_char(l);
    }
    cout
        << endl;
}

int main()
{
    OUT;
    int t = 2000;
    cout << t << endl;
    for (int i = 0; i < t; i++)
        tc();

    return 0;
}