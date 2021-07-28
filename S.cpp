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

void solve()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<pair<int,int>> action;
    vector<int> a;

    for (int i=0; i< 2 * n; i++) {
        string s;
        getline(cin,s);
        if (s[0] == '+') {
            action.push_back({0,0});
        } else {
            string num = "";
            for (int j=2; j<s.size(); j++) {
                num.push_back(s[j]);
            }
            action.push_back({1,stoi(num)});
            a.push_back(stoi(num));
        }
    }

    // 0 is +
    // 1 is -
    
    cout << "Actions\n";
    for (int i=0; i<2 *n; i++) {
        cout << action[i].first << ' ' << action[i].second << endl;
    }
    cout << "-------\n";

    sort(a.begin(), a.end());

    priority_queue<int, vector<int>, greater<int> > q;
    vector<bool> in_q(n+1, false);
    int pointer = a.size()-1;

    vector<int> res;
    for (int i=0; i<2*n; i++){
        pair<int,int> act = action[i];
        if (act.first == 0) {
            pair<int,int> nxt = action[i+1];
            if (nxt.first == 1) {
                int m = nxt.second;
                if (!in_q[m])
                {
                    q.push(m);
                    in_q[m] = true;
                    res.push_back(m);
                } 
            } else {
                while (in_q[a[pointer]])
                    pointer--;
                if (pointer >= 0) {
                    q.push(a[pointer]);
                    in_q[a[pointer]] = true;
                    res.push_back(a[pointer]);
                    pointer--;
                }
            }
        } else {
            int min = q.top();
            q.pop();
            cout << "ACT " << act.first << ' ' << act.second << endl;
            cout << "MIN " << min << endl;
            if (min != act.second) {
                cout << "NO";
                return;
            }
        }
    }

    cout << "YES\n";
    for (int i=0; i<res.size(); i++)
        cout << res[i] << ' ';
}

int main()
{
    FAST;
#ifndef ONLINE_JUDGE
    INP;
#endif
    solve();
    return 0;
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/