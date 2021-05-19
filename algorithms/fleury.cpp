#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define V 5
#define E 10
int graph[V][V] = {{0, 1, 1, 1, 1},
                   {1, 0, 1, 1, 0},
                   {1, 1, 0, 1, 0},
                   {1, 1, 1, 0, 1},
                   {1, 0, 0, 1, 0}};

int tmp_graph[V][V];

void init_tmp_graph()
{
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            tmp_graph[i][j] = graph[i][j];
}

int find_start_vertex()
{
    for (int i = 0; i < V; i++)
    {
        int deg = 0;
        for (int j = 0; j < V; j++)
            if (tmp_graph[i][j])
                deg++;
        // Return if degree is odd
        if (deg % 2 != 0)
            return i;
    }
    return 0;
}

bool is_bridge(int u, int v)
{
    int deg = 0;
    for (int i = 0; i < V; i++)
        if (tmp_graph[v][i])
            deg++;
    if (deg > 1)
        return false;
    return true;
}

void fleury_util(int u, int edges)
{
    for (int v = 0; v < V; v++)
    {
        if (tmp_graph[u][v])
        {
            // When (u,v) edge is present and not forming a bridge
            if (edges <= 1 || !is_bridge(u, v))
            {
                // Remove edge from graph
                // !!! ALERT !!! modify this if the graph is a directed graph.
                tmp_graph[u][v] = tmp_graph[v][u] = 0;
                // Reduce edge
                edges--;

                // Print edge
                cout << u << " - " << v << endl;

                // Call for next vertice
                fleury_util(v, edges);
            }
        }
    }
}

int count_edges()
{
    int count = 0;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (graph[i][j])
                count++;
    return count;
}

void fleury()
{
    init_tmp_graph();
    int edges = count_edges();
    int start = find_start_vertex();
    fleury_util(start, edges);
}

int main()
{
    fleury();
    return 0;
    // Output:
    /*
        1 - 0
    0 - 2
    2 - 1
    1 - 3
    3 - 0
    0 - 4
    4 - 3
    */
}