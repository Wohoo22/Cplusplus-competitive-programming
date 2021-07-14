#include "bits/stdc++.h"
using namespace std;

// Number of nodes
const int n = 9;
// Vector to store tree
vector<int> g[n + 1];

/*--------------------------*/

int logn = (int)ceil(log2(n));
int memo[n + 1][n];
int lev[n + 1];

void dfs(int u, int p)
{
    memo[u][0] = p;
    for (int i = 1; i <= logn; i++)
        memo[u][i] = memo[memo[u][i - 1]][i - 1];
    for (int v : g[u])
    {
        if (v != p)
        {
            lev[v] = lev[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int u, int v)
{
    if (lev[u] < lev[v])
    {
        int temp = u;
        u = v;
        v = temp;
    }
    for (int i = logn; i >= 0; i--)
    {
        if (lev[u] + (int)pow(2, i) <= lev[v])
            u = memo[u][i];
    }
    if (u == v)
        return v;
    for (int i = logn; i >= 0; i--)
    {
        if (memo[u][i] != memo[v][i])
        {
            u = memo[u][i];
            v = memo[v][i];
        }
    }

    return memo[u][0];
}

void init()
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < (int)(n / 2); j++)
            memo[i][j] = -1;
}

int main()
{
    // Add edges
    g[1].push_back(2);
    g[2].push_back(1);
    g[1].push_back(3);
    g[3].push_back(1);
    g[1].push_back(4);
    g[4].push_back(1);
    g[2].push_back(5);
    g[5].push_back(2);
    g[3].push_back(6);
    g[6].push_back(3);
    g[3].push_back(7);
    g[7].push_back(3);
    g[3].push_back(8);
    g[8].push_back(3);
    g[4].push_back(9);
    g[9].push_back(4);

    // Build memo
    dfs(1, 1);

    // Lca
    cout << "The LCA of 6 and 9 is " << lca(6, 9) << endl;
    cout << "The LCA of 5 and 9 is " << lca(5, 9) << endl;
    cout << "The LCA of 6 and 8 is " << lca(6, 8) << endl;
    cout << "The LCA of 6 and 1 is " << lca(6, 1) << endl;

    /*
    The LCA of 6 and 9 is 1
    The LCA of 5 and 9 is 1
    The LCA of 6 and 8 is 3
    The LCA of 6 and 1 is 1
    */

    return 0;
}