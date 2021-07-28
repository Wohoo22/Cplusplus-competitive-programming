#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INP freopen("SOL.INP", "w", stdout);
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
    int t = 20;
    cout << t << endl;
    while (t--) {
        int n =  rnd.next(3, 10);
        int m =  rnd.next(1, n-1);
        cout << n << ' ' << m << endl;

        vector<int> row;
        vector<int> col;
        for (int i=1; i<=n; i++) {
            row.push_back(i);
            col.push_back(i);
        }

        while(m--) {
            int x = rnd.any(row);
            int y = rnd.any(col);
            for (int i=0; i<row.size(); i++) {
                if (x == row[i]) {
                    row.erase(row.begin()+i);
                    break;
                }
            }
            for (int i=0; i<col.size(); i++) {
                if (y == col[i]) {
                    col.erase(col.begin()+i);
                    break;
                }
            }

            cout << x << ' ' << y << endl;
        }
    }
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/