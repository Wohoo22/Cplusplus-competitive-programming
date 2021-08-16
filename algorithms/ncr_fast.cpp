#include <bits/stdc++.h>
#define ll long long
const int N = 1000001;
using namespace std;

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

ll binomial(ll N, ll R, ll p)
{
	ll ans = ((fact[N] * factorial_num_inverse[R])
			% p * factorial_num_inverse[N - R])
			% p;
	return ans;
}

int main()
{
	ll p = 1000000007;
	inverse_of_number(p);
	inverse_of_factorial(p);
	factorial(p);

	// 1st query
	ll N = 15;
	ll R = 4;
	cout << binomial(N, R, p) << endl;

	// 2nd query
	N = 20;
	R = 3;
	cout << binomial(N, R, p) << endl;

	return 0;
}
