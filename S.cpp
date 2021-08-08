#include "bits/stdc++.h"
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INP freopen("S.INP", "r", stdin);
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

int matrix[1000][1000];
int ro, co;

bool contains(int k, int r, int c) {
    for (int i=0; i<ro; i++) {
        if (matrix[i][c] == k)
            return true;
    }
    for (int i=0; i<co; i++)
        if (matrix[r][i] == k)
            return true;
    return false;
}

void solve()
{
    cin >> ro >> co;
    for (int i=0; i<ro; i++)
        for (int j=0; j<co; j++)
            matrix[i][j] = -1;
    for (int i=0; i<ro; i++)
        for (int j=0; j<co; j++) {
            for (int k=0; k<=1000; k++) {
                if (!contains(k, i, j))
                {
                    matrix[i][j] = k;
                    break;
                }
            }
        }
    
    int sum = 0;
    for (int i=0; i<ro; i++) {
        for (int j=0; j<co; j++) {
            cout << matrix[i][j] << ' ';
            sum += matrix[i][j];
        }
        cout << endl;
    }
    cout << "sum " << sum;
}

int main()
{
    FAST;
    solve();
    return 0;
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/