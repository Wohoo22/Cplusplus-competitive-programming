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
    freopen("input05.txt", "w", stdout);
    int t = rnd.next(1, 1);
    cout << t << endl;
    while(t--) {
        int n = rnd.next(1000000, 1000000);
        cout << n << endl;
        bool palindrome = false;
        if (palindrome) {
            vector<char> s(n);
            int l=0, r=n-1;
            while (l < r) {
                s[l] = s[r] = ic(rnd.next(0, 25));
                l++, r--;
            }
            if (n % 2 != 0)
                s[l] = ic(rnd.next(0, 25));
            for (int i=0; i<n; i++) {
                int j = rnd.next(0, n-1);
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
            for (auto &c : s)
                cout << c;
            cout << endl;
        } else {
            while(n--)
                cout << ic(rnd.next(0, 25));
            cout << endl;
        }
    }
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/