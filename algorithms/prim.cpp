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
        if (mst_set[v] == false && key[v] < min)
            min = key[v],
            min_index = v;

    return min_index;
}

void prim()
{
    int parent[V];
    int key[V];
    bool mst_set[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX,
        mst_set[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V; i++)
    {
        int u = min_key(key, mst_set);

        mst_set[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] > 0 && mst_set[v] == false && graph[u][v] < key[v])
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