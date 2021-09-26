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
IC;
int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    FAST;
    // freopen("input05.txt", "w", stdout);
    int t = rnd.next(1, 1);
    cout << t << endl;
    while(t--) {
       int r = rnd.next(1, 3);
       int g = rnd.next(1, 3);
       int b = rnd.next(1, 3);
       cout << r << ' ' << g << ' ' << b << endl;
       for (int i=0; i<r; i++) {
            cout << rnd.next(1, 10) << ' ';
       }
       cout << endl;
        for (int i=0; i<g; i++) {
            cout << rnd.next(1, 10) << ' ';
       }
       cout << endl;
        for (int i=0; i<b; i++) {
            cout << rnd.next(1, 10) << ' ';
       }
       cout << endl;
    }
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/