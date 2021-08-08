#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INP freopen("S.INP", "w", stdout);
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

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    FAST;
    // INP;
    int t = rnd.next(1,10);
    cout << t << endl;
    while (t--) {
        int n = rnd.next(20,100);
        cout << n << endl;
        int p = n;
        while (n--) {
            cout << rnd.next(1, p) << ' ';
        }
        cout << endl;
    }
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/