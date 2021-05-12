#include "bits/stdc++.h"
using namespace std;

// M is number of applicants
// N is number of jobs
#define M 6
#define N 6

// Bipartite graph of M and N
bool graph[M][N] = {{0, 1, 1, 0, 0, 0},
                    {1, 0, 0, 1, 0, 0},
                    {0, 0, 1, 0, 0, 0},
                    {0, 0, 1, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1}};

bool can_match(int u, bool seen[], int match[])
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        // If applicant u is interested in
        // job v and v is not visited
        if (graph[u][v] && !seen[v])
        {
            seen[v] = true;

            // If job 'v' is not assigned to an
            // applicant OR previously assigned
            // applicant for job v (which is matchR[v])
            // has an alternate job available.
            // Since v is marked as visited in
            // the above line, matchR[v] in the following
            // recursive call will not get job 'v' again
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
    // Array to keep track of jobs that are assigned to a applicant
    int match[N];

    // Init match[]
    for (int i = 0; i < N; i++)
        match[i] = -1;

    // Count of jobs assigned to applicants
    int result = 0;
    for (int u = 0; u < M; u++)
    {
        bool seen[N];
        // Mark all jobs as not seen for the next applicant
        for (int v = 0; v < N; v++)
            seen[v] = false;

        // Find if applicant u can get any job
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