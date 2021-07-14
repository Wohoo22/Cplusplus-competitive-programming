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
    int cut_last(ll x, ll n) { return x % (ll)pow(10, n); }
#define IC \
    char ic(int i) { return "abcdefghijklmnopqrstuvwxyz"[i]; }
/*
    RANDOM:
    rand() % (max – min + 1)
*/
CUTLAST;
vector<ll> money;

ll get_mx(ll upper) {
    for (int i=money.size()-1; i>=0; i--)
        if (money[i] <= upper)
            return money[i];
    return 1;
}

vector<vector<ll>> subsets;

void comb_util(int chosen[], vector<ll> &arr,
					int index, int r, int start, int end)
{
	if (index == r)
	{
        vector<ll> ss;
		for (int i = 0; i < r; i++) {
            ss.push_back(arr[chosen[i]]);
        }
         
        subsets.push_back(ss);
		return;
	}
	for (int i = start; i <= end; i++)
	{
		chosen[index] = i;
		comb_util(chosen, arr, index + 1,
											r, i, end);
	}
	return;
}

void comb(vector<ll> &arr, int n, int r)
{
    subsets.clear();
	int chosen[r+1];
	comb_util(chosen, arr, 0, r, 0, n-1);
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

vector<ll> vals = {1,2,3,5};
ll calc(ll size, ll sum) 
{
    while (sum % 10 == 0)
        sum /= 10;
    comb(vals, vals.size(), size);

    vector<vector<ll>> valids;
    for (int i=0; i<subsets.size(); i++)
    {
        vector<ll> set = subsets[i];
        ll s=0;
        for (int j=0; j<set.size(); j++)
            s += set[j];
        if (sum == s)
            valids.push_back(set);
    }

    ll ans=0;
    for (int i=0; i<valids.size(); i++)
    {
        vector<ll> set = valids[i];
        bool flag=true;
        for (int j=0; j<i; j++)
            if (same(set, valids[j]))
            {
                flag=false;
                break;
            }
        if (flag) ans++;
    }

    return ans;
}

void solve()
{
    ll w, c;
    cin >> w >> c;

    if (cut_last(w,3) > 0) 
    {
        cout << 0 << endl;
        return;
    }

    money.clear();
    for (int i=0; i<=c; i++)
        for (int j=1000; j<=5000; j+=1000)
            if (j != 4000)
                money.push_back(j * pow(10,i));
    
    ll wt=w;
    ll size=0;
    
    ll lst_seg_len = -1;
    vector<ll> seg_size;
    vector<ll> seg_sum;
    while (wt > 0)
    {
        ll mx = get_mx(wt);
        ll times = floor((double)wt/mx);
        size += times;
        wt -= mx*times;

        string s = to_string(mx);

        if (lst_seg_len == -1)
        {
            seg_size.push_back(1);
            seg_sum.push_back(mx);
            lst_seg_len = s.size();
            continue;
        }

        if (s.size() == lst_seg_len)
            seg_size[seg_size.size()-1] += times,
            seg_sum[seg_sum.size()-1] += mx*times;
        else 
            seg_size.push_back(times),
            seg_sum.push_back(mx*times);
        lst_seg_len = s.size();
    }

    ll ways=1;
    for (int i=0; i<seg_size.size(); i++)
        ways *= calc(seg_size[i], seg_sum[i]);

    cout << size << ' ' << ways << endl;
}

int main()
{
    FAST;
    //  INP;
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