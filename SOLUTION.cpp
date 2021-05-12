#include "bits/stdc++.h"
using namespace std;

bool graph[101][101];
int M;
int N;

bool can_match(int u, bool seen[], int match[])
{
    for (int v = 1; v <= N; v++)
    {
        if (graph[u][v] && !seen[v])
        {
            seen[v] = true;

            if (match[v] == -1 || can_match(match[v], seen, match))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

void max_bipartite_matching()
{
    // Array to keep track of jobs that are assigned to a applicant
    int match[N + 1];

    // Init match[]
    for (int i = 1; i <= N; i++)
        match[i] = -1;

    // Count of jobs assigned to applicants
    int result = 0;
    for (int u = 1; u <= M; u++)
    {
        bool seen[N + 1];
        // Mark all jobs as not seen for the next applicant
        for (int v = 1; v <= N; v++)
            seen[v] = false;

        // Find if applicant u can get any job
        can_match(u, seen, match);
    }

    int count = 0;

    for (int i = 1; i <= N; i++)
        if (match[i] != -1)
            count++;

    cout << count << endl;
    for (int i = 1; i <= N; i++)
        if (match[i] != -1)
            cout << match[i] << " " << i << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("SOLUTION.INP", "r", stdin);
    // freopen("SOLUTION.OUT", "w", stdout);

    cin >> M >> N;

    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            graph[i][j] = false;

    string line;
    getline(cin, line);
    int x, y;
    string tmp;
    while (getline(cin, line))
    {
        stringstream ss(line);
        tmp = "";
        ss >> x >> y;
        graph[x][y] = true;
    }
    max_bipartite_matching();

    return 0;
}