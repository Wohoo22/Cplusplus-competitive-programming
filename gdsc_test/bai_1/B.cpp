#include "bits/stdc++.h"
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INP freopen("S.INP", "r", stdin);
#define ll long long
#define mod 1000000007
ll get_last(int x, int n) { 
    return x % (int)pow(10, n); 
}
ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp % 2 == 1) 
            res = (res * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return res;
}
ll madd(ll a, ll b) {
    return (a + b) % mod;
}
ll msub(ll a, ll b) {
    return (((a - b) % mod) + mod) % mod;
}
ll mmul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

/* ---------------------------------- END TEMPLATE ---------------------------------- */

void subsetsUtil(vector<int> &A, vector<vector<int>> &res,
				 vector<int> &subset, int index)
{
	res.push_back(subset);
	for (int i = index; i < A.size(); i++)
	{
		subset.push_back(A[i]);
		subsetsUtil(A, res, subset, i + 1);
		subset.pop_back();
	}
	return;
}

vector<vector<int>> subsets(vector<int> &A)
{
	vector<int> subset;
	vector<vector<int>> res;
	int index = 0;
	subsetsUtil(A, res, subset, index);
	return res;
}

int calc(vector<int> choose, vector<pair<int,int>> sets) {
    vector<bool> chosen(10000, false);
    int ans = 0;
    for (auto &x : choose) {
        pair<int,int> set = sets[x];
        if (chosen[set.first] || chosen[set.second])
            continue;
        chosen[set.first] = true;
        chosen[set.second] = true;
        ans++;
    }
    return ans;
}

void solve(int tc)
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	vector<pair<int,int>> sets;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			if (abs(a[i] - a[j]) == k)
				sets.push_back({a[i], a[j]});

	vector<int> indexes;
    for (int i=0; i<sets.size(); i++)
        indexes.push_back(i);
    vector<vector<int>> choose = subsets(indexes);
    int ans = 0;
    for (auto &chs : choose) {
        ans = max(ans, calc(chs, sets));
    }

    cout << ans << endl;
}

int main()
{
    FAST;
    // INP;
    int t = 1;
    cin >> t;
    for (int i=1; i<=t; i++)
        solve(i);
    return 0;
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/