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


const ll N = 200005;
ll pow_2[N * 2];

ll factorial_num_inverse[N + 1];
ll natural_num_inverse[N + 1];
ll fact[N + 1];

void inverse_of_number(ll p)
{
	natural_num_inverse[0] = natural_num_inverse[1] = 1;
	for (int i = 2; i <= N; i++)
		natural_num_inverse[i] = natural_num_inverse[p % i] * (p - p / i) % p;
}

void inverse_of_factorial(ll p)
{
	factorial_num_inverse[0] = factorial_num_inverse[1] = 1;
	for (int i = 2; i <= N; i++)
		factorial_num_inverse[i] = (natural_num_inverse[i] * factorial_num_inverse[i - 1]) % p;
}

void factorial(ll p)
{
	fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = (fact[i - 1] * i) % p;
	}
}

ll ncr(ll N, ll R, ll p)
{
	ll ans = ((fact[N] * factorial_num_inverse[R])
			% p * factorial_num_inverse[N - R])
			% p;
	return ans;
}


void precompute() {
    ll a=1;
    pow_2[0]=1;
    pow_2[1]=2;
    for (ll i=2; i<=N*2; i++) 
        pow_2[i] = (pow_2[i-1] * 2) % MOD;
    inverse_of_number(MOD);
    inverse_of_factorial(MOD);
    factorial(MOD);
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << pow_2[k] << endl;
        return;
    }

    if (n % 2 != 0) {
        ll tt = 1;  
        for (ll i=0; i<=n-1; i+=2) {
            tt += ncr(n, i, MOD) % MOD;
            tt %= MOD;
        }
        ll ans = 1;
        for (ll i=0; i<k; i++) {
            ans *= tt % MOD;
            ans %= MOD;
        }
        cout << ans << endl;
    } else {
        ll tt = 0;
        for (ll i=0; i<=n-2; i++) {
            tt += ncr(n, i, MOD) % MOD;
            tt %= MOD;
        }
        ll ncr_pow[k+1];
        ncr_pow[0] = 1;
        for (ll i=1; i<=k; i++) {
            ncr_pow[i] = ncr_pow[i-1] * (tt % MOD);
            ncr_pow[i] %= MOD;
        }
        ll ans = ncr_pow[k];
        for (int i=1; i<=k; i++) {
            ans += ((ncr_pow[k-i] % MOD) * (pow_2[2 * i - 2] % MOD)) % MOD;
            ans %= MOD;
        }
        cout << ans << endl;
    }
}

int main()
{
    FAST;   
    // INP;
    int t;
    cin >> t;
    precompute();
    while (t--)
        solve();
    return 0;
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/