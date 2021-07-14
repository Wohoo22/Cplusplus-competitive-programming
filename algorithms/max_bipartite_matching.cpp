#include "bits/stdc++.h"
using namespace std;

// M is number of applicants
// N is number of jobs
#define M 6
#define N 6

bool graph[M][N] = {{0, 1, 1, 0, 0, 0},
                    {1, 0, 0, 1, 0, 0},
                    {0, 0, 1, 0, 0, 0},
                    {0, 0, 1, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1}};

bool can_match(int u, bool seen[], int match[])
{
    for (int v = 0; v < N; v++)
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

int max_bipartite_matching()
{
    int match[N];
    for (int i = 0; i < N; i++)
        match[i] = -1;
    int result = 0;
    for (int u = 0; u < M; u++)
    {
        bool seen[N];
        for (int v = 0; v < N; v++)
            seen[v] = false;
        if (can_match(u, seen, match))
            result++;
    }
    return result;
}

int main()
{
    /* Correct output:
    Maximum number of applicants that can get job is 5
    */
    cout << "Max bipartite matching: " << max_bipartite_matching();
    return 0;
}