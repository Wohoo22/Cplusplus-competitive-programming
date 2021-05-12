#include "bits/stdc++.h"
using namespace std;

#define V 6
int graph[V][V];

void create_graph()
{
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    graph[5][2] = graph[5][0] = graph[4][0] = graph[4][1] = graph[2][3] = graph[3][1] = 1;
}

void kahn()
{
    // Store indegree of all vertices
    int indeg[V];

    // Init indeg[]
    for (int v = 0; v < V; v++)
        indeg[v] = 0;

    // Fill indeg[]
    for (int v = 0; v < V; v++)
        for (int u = 0; u < V; u++)
            if (graph[u][v])
                indeg[v]++;

    // Create a queue and add all vertice with indegree 0
    queue<int> q;

    for (int v = 0; v < V; v++)
        if (indeg[v] == 0)
            q.push(v);

    // Count of visited vertices
    int count = 0;

    // Vector to store result in topological order
    vector<int> topo;

    while (!q.empty())
    {
        // Extract and add front element in queue to the result vector
        int u = q.front();
        q.pop();
        topo.push_back(u);

        // Increase count
        count++;

        // Decrease all indegree of u's adjacent vertices by 1
        for (int v = 0; v < V; v++)
            if (graph[u][v])
                // If indegree of v becomes 0, add it to queue
                if (--indeg[v] == 0)
                    q.push(v);
    }

    // Graph can be topological sorted only if count equals v
    if (count != V)
    {
        cout << "Graph contains cycle.";
        return;
    }

    // Print
    for (int v : topo)
        cout << v << " ";
}

int main()
{
    /*
    This algorithm is for checking if a graph is a topo-graph or not
    */
    create_graph();
    kahn();
    /*
    Following is a Topological Sort
    4 5 2 0 3 1
    */
    return 0;
}