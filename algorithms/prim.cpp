#include <bits/stdc++.h>
using namespace std;

#define V 5

const int graph[V][V] = {{0, 2, 0, 6, 0},
                         {2, 0, 3, 8, 5},
                         {0, 3, 0, 0, 7},
                         {6, 8, 0, 0, 9},
                         {0, 5, 7, 9, 0}};

void print_mst(int parent[])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        if (parent[i] != -1)
            cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

int min_key(int key[], bool mst_set[])
{
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++)
        if (mst_set[v] == false // v not in mstSet[]
            && key[v] < min)    // dist(v,MST) is minimum
            min = key[v],
            min_index = v;

    return min_index;
}

void prim()
{
    // array to store constructed MST
    int parent[V];

    // Key values to pick minimum weight edge in cut
    int key[V];

    // To represent set of vertices included in MST
    bool mst_set[V];

    // Initialize all keys as INFINITE, mst_set[i] as False
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX,
        mst_set[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // MST contains V vertices
    for (int i = 0; i < V; i++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = min_key(key, mst_set);

        // Add the picked vertice to the MST
        mst_set[u] = true;

        // Update key value and parent index of Adjacents[u]
        // Consider only those vertices which is not in MST
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] > 0          // edge between u,v
                && mst_set[v] == false   // v not in MST
                && graph[u][v] < key[v]) // d(u,v) < key[v]
                parent[v] = u,
                key[v] = graph[u][v];
        }
    }

    print_mst(parent);
}

int main()
{
    /*
    CORRECT OUTPUT:

    Edge    Weight
    0 - 1   2 
    1 - 2   3 
    0 - 3   6 
    1 - 4   5 

    */

    prim();

    return 0;
}