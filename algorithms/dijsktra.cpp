#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define V 9

/* Let us create the example graph discussed above */
int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                   {4, 0, 8, 0, 0, 0, 0, 11, 0},
                   {0, 8, 0, 7, 0, 4, 0, 0, 2},
                   {0, 0, 7, 0, 9, 14, 0, 0, 0},
                   {0, 0, 0, 9, 0, 10, 0, 0, 0},
                   {0, 0, 4, 14, 10, 0, 2, 0, 0},
                   {0, 0, 0, 0, 0, 2, 0, 1, 6},
                   {8, 11, 0, 0, 0, 0, 1, 0, 7},
                   {0, 0, 2, 0, 0, 0, 6, 7, 0}};

void print(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int vertice_min_dist(int dist[], bool spt_set[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!spt_set[v] && dist[v] <= min)
            min = dist[v],
            min_index = v;

    return min_index;
}

void dijsktra(int src)
{
    // Hold shortest distance from src to i
    int dist[V];

    // If distance from src to i is the shortest
    bool spt_set[V];

    // Init dist and spt_set
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, spt_set[i] = false;

    // dist[src] is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertice from the set of vertice
        // not yet processed.
        int u = vertice_min_dist(dist, spt_set);

        // Mark the chosen vertice as processed
        spt_set[u] = true;

        // Update dist value of adjacent vertices of u
        for (int v = 0; v < V; v++)
            if (!spt_set[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    print(dist);
}

int main()
{
    dijsktra(0);
    return 0;
}