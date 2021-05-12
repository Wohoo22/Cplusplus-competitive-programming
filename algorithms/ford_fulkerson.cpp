#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define V 6
int graph[V][V] = {
    {0, 16, 13, 0, 0, 0},
    {0, 0, 10, 12, 0, 0},
    {0, 4, 0, 0, 14, 0},
    {0, 0, 9, 0, 0, 20},
    {0, 0, 0, 7, 0, 4},
    {0, 0, 0, 0, 0, 0}};

void dfs(int u, bool visited[V], int rgraph[V][V])
{
    visited[u] = true;
    for (int v = 0; v < V; v++)
        if (rgraph[u][v] && !visited[v])
            dfs(v, visited, rgraph);
}

// Addition: find min s-t cut
void min_cut(int rgraph[V][V], int s)
{
    bool visited[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;

    // Find vertices reachable from s
    dfs(s, visited, rgraph);

    // Edge from a reachable vertice to non-reachable vertice
    // in the original graph is in a min s-t cut
    cout << "Min s-t cut is:" << endl;
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            if (visited[u] && !visited[v] && graph[u][v])
                // Edge (u,v) is belong to a min s-t cut
                cout << u << " - " << v << endl;
}

// ford-fulkerson bfs
bool bfs(int rgraph[V][V], int s, int t, int parent[])
{
    // Visited vertices
    bool visited[V];
    // Init visted[]
    for (int v = 0; v < V; v++)
        visited[v] = false;

    // Standard BFS
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = s;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
            if (!visited[v] && rgraph[u][v])
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
    }
    return false;
}

void ford_fulkerson(int s, int t)
{
    int rgraph[V][V];

    // Copy graph to rgraph
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            rgraph[u][v] = graph[u][v];

    // Array to store path
    int parent[V];

    int max_flow = 0;

    // While there is a augmenting path from source to sink
    while (bfs(rgraph, s, t, parent))
    {
        // Find possible flow of augmenting path
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
        }
        // Update residual graph
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    // Print max-flow
    cout << "Max-flow is " << max_flow << endl;

    // Addition: find min s-t cut
    min_cut(rgraph, s);
}

int main()
{
    ford_fulkerson(0, 5);
    /* Correct output:
    Max-flow is 23
    Min s-t cut is:
    1 - 3
    4 - 3
    4 - 5
    */
    return 0;
}