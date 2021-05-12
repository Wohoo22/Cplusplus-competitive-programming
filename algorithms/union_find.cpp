#include "bits/stdc++.h"
using namespace std;

#define V 3
int graph[V][V] = {{0, 1, 1},
                   {1, 0, 1},
                   {1, 1, 0}};

int get_root(int root[], int u)
{
    if (root[u] == -1)
        return u;
    return get_root(root, root[u]);
}

void union_root(int root[], int u, int v)
{
    root[u] = v;
}

bool isCycle()
{
    // Save root of each node
    int root[V];
    for (int v = 0; v < V; v++)
        root[v] = -1;

    // Loop through all edges of graph
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            if (graph[u][v])
            {
                int x = get_root(root, u);
                int y = get_root(root, v);

                // If 2 vertices have the same root, they form a cycle
                if (x == y)
                    return true;

                // Union 2 roots of 2 vertices
                union_root(root, u, v);
            }
    return false;
}

int main()
{
    /*
    Detect cycle in a Graph using union find
    */
    if (isCycle())
        cout << "Graph contains cycle." << endl;
    else
        cout << "Graph doesn't contain cycle." << endl;

    return 0;
}