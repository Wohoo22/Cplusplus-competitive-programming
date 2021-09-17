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
        int n = rnd.next(100000, 100000);
        int k = rnd.next(1, 10000);
        cout << n << ' ' << k << endl;

        // diff set cnt
        int diff = rnd.next(n/2, n);
        int a[n]; 
        a[0] = rnd.next(1,20);

        // init diff set
        int j = 0;
        for (int i=1; i<diff; i++) {
            a[i] = a[i-1] + k;
            j = i;
            if (a[i] >= 1000000)
                break;
        }
        
        // complete
        for (int i=j+1; i<n; i++)
            if (i > 0) a[i] = a[i-1] + rnd.next(1,20);
            else a[i] = rnd.next(1, 20);

        // randomize
        for (int i=0; i<n; i++) {
            int j = rnd.next(0,n-1);
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }

        for (int i=0; i<n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/