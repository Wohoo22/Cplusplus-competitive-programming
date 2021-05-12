#include "bits/stdc++.h"
using namespace std;

#define V 5
#define E 8

// Every edge has three values (u, v, w) where
// the edge is from vertex u to v. And weight
// of the edge is w.
int graph[][3] = {
    {0, 1, -1},
    {0, 2, 4},
    {1, 2, 3},
    {1, 3, 2},
    {1, 4, 2},
    {3, 2, 5},
    {3, 1, 1},
    {4, 3, -3}};

void bellman_ford(int src)
{
    // Init distance of all vertices is INF
    int dis[V];
    for (int i = 0; i < V; i++)
        dis[i] = INT_MAX;

    // Init distance of source as 0
    dis[src] = 0;

    // A path from src to any other vertice can have at most V-1 edges
    for (int i = 0; i < V - 1; i++)
    {
        for (int e = 0; e < E; e++)
        {
            int u = graph[e][0], v = graph[e][1];
            int w = graph[e][2];
            if (dis[u] != INT_MAX && dis[u] + w < dis[v])
                dis[v] = dis[u] + w;
        }
    }

    // Print
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dis[i] << endl;
}

int main()
{
    bellman_ford(0);
    /*
    Vertex Distance from Source
    0        0
    1        -1
    2        2
    3        -2
    4        1
    */
    return 0;
}