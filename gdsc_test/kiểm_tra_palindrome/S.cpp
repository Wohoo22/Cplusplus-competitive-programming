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

    void solve(int tc)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> cnt(27, 0);
        for (auto &c : s)
            cnt[c - 'a']++;
        int odd = 0;
        for (auto &c : cnt)
            if (c % 2 != 0)
                odd++;
        if (odd <= 1)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }

    int main()
    {
        FAST;
        // freopen("input05.txt", "r", stdin);
        // freopen("output05.txt", "w", stdout);
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