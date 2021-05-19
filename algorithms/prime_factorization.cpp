#include "bits/stdc++.h"
using namespace std;
#define ll long long

void prime_factors(int n)
{
    vector<int> factors;
    if (n % 2 == 0)
    {
        factors.push_back(2);
        while (n % 2 == 0)
            n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 2)
        factors.push_back(n);

    for (int i = 0; i < factors.size(); i++)
        cout << factors[i] << " ";
}

int main()
{
    prime_factors(315);
    // Answer: 3 5 7
    return 0;
}