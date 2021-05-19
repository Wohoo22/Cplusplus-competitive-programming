#include "bits/stdc++.h"
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> x(1, 0);
    vector<int> y(1, 0);

    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        if (v == 1)
            x.push_back(i);
        else
            y.push_back(i);
    }

    if (x.size() == 1)
    {
        cout << 0;
        return;
    }

    vector<vector<int>> dp(x.size(), vector<int>(y.size(), 1e9));
    for (int i = 0; i < y.size(); i++)
        dp[0][i] = 0;

    for (int i = 1; i < x.size(); i++)
        for (int j = i; j < y.size(); j++)
            dp[i][j] = min(
                dp[i][j - 1],
                dp[i - 1][j - 1] + abs(x[i] - y[j]));

    cout << dp[x.size() - 1][y.size() - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("SOLUTION.INP", "r", stdin);
    solve();
    return 0;
}