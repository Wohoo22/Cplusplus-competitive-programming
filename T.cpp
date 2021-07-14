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

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

vector<vector<ll>> subsets;

void CombinationRepetitionUtil(int chosen[], vector<ll> &arr,
					int index, int r, int start, int end)
{
	if (index == r)
	{
        vector<ll> ss;
		for (int i = 0; i < r; i++) {
            ss.push_back(arr[chosen[i]]);
        }

        // for (int i = 0; i < r; i++) 
        //     cout<<" "<< arr[chosen[i]];
        //  cout<<"\n";
         
        subsets.push_back(ss);
		return;
	}
	for (int i = start; i <= end; i++)
	{
		chosen[index] = i;
		CombinationRepetitionUtil(chosen, arr, index + 1,
											r, i, end);
	}
	return;
}

void CombinationRepetition(vector<ll> &arr, int n, int r)
{
    subsets.clear();
	int chosen[r+1];
	CombinationRepetitionUtil(chosen, arr, 0, r, 0, n-1);
}

bool same(vector<ll> &a, vector<ll> &b)
{
    if (a.size() != b.size()) return false;
    sort(a.begin(), a.end());    
    sort(b.begin(), b.end());
    for (int i=0; i<a.size(); i++)
        if (a[i] != b[i])
            return false;
    return true;
}

void solve()
{
    ll w,c;
    cin >> w >> c;

    vector<ll> money;
    for (int i=0; i<=c; i++)
        for (int j=1000; j<=5000; j+=1000)
            if (j != 4000)
                money.push_back(j * pow(10,i));

    int mn_size = INT_MAX;
    vector<vector<ll>> valid;
    for (int r=1; r <= w/1000 + 1; r++)
    {
        CombinationRepetition(money,money.size(), r);
        bool ok = false;
        for (int i=0; i<subsets.size(); i++)
        {
            vector<ll> set = subsets[i];
            ll sum = 0;
            for (int j=0; j<set.size(); j++)
                sum += set[j];
            if (sum == w && set.size() < mn_size) {
                ok=true;
            }
        }
        if (ok) {
            mn_size = r;
            break;    
        }
    }

    if (mn_size == INT_MAX) {
        cout << 0 << endl;
        return;
    }

    CombinationRepetition(money,money.size(), mn_size);
    for (int i=0; i<subsets.size(); i++)
    {
        vector<ll> set = subsets[i];
        ll sum = 0;
        for (int j=0; j<set.size(); j++)
            sum += set[j];
        if (sum == w)
            valid.push_back(set);
    }

    int cnt=0;
    for (int i=0; i<valid.size(); i++)
    {
        vector<ll> set = valid[i];
        bool ok = true;
        for (int j=0; j<i; j++)
            if (same(set,valid[j]))
            {
                ok = false;
                break;
            }
        if (ok) {
            cout << "CASE: ";
            for (int i=0; i<set.size(); i++)
                cout << set[i]<< ' ';
            cout << endl;
            cnt++;
        }
    }
    
    cout << mn_size << ' ' << cnt << endl;
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
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/