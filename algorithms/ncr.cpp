#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll power(ll x, int y, int p)
{
	ll res = 1;
	x = x % p; 
	while (y > 0) {
		if (y & 1) res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

ll mod_inverse(ll n, int p)
{
	return power(n, p - 2, p);
}

ll ncr(ll n, int r, int p)
{
	if (n < r) return 0;
	if (r == 0) return 1;
	ll fac[n + 1]; fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % p;
	return (fac[n] * mod_inverse(fac[r], p) % p * mod_inverse(fac[n - r], p) % p) % p;
}

int main()
{
	int n = 10, r = 2, p = 13;
	cout << "Value of nCr % p is "
		<< ncr(n, r, p);
	return 0;
}
