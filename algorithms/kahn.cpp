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
    int indeg[V];
    for (int v = 0; v < V; v++)
        indeg[v] = 0;
    for (int v = 0; v < V; v++)
        for (int u = 0; u < V; u++)
            if (graph[u][v])
                indeg[v]++;
    queue<int> q;
    for (int v = 0; v < V; v++)
        if (indeg[v] == 0)
            q.push(v);
    int count = 0;
    vector<int> topo;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        count++;
        for (int v = 0; v < V; v++)
            if (graph[u][v])
                if (--indeg[v] == 0)
                    q.push(v);
    }
    if (count != V)
    {
        cout << "Graph contains cycle.";
        return;
    }
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