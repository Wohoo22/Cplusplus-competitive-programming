#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define V 6
int graph[V][V];

void create_graph()
{
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    graph[5][2] = graph[5][0] = graph[4][0] = graph[4][1] = graph[2][3] = graph[3][1] = 1;
}

// Save the order after topo-sorted
stack<int> st;
void topo_sort_util(int u, bool visited[])
{
    // Mark u as visited
    visited[u] = true;

    // Dfs
    for (int v = 0; v < V; v++)
        if (graph[u][v] && !visited[v])
            topo_sort_util(v, visited);

    // Push u to stack after visiting all its neighbor
    st.push(u);
}

void topo_sort()
{

    // Save visited vertices
    bool visited[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;

    // Dfs
    for (int v = 0; v < V; v++)
        if (!visited[v])
            topo_sort_util(v, visited);

    // Print
    while (!st.empty())
        cout << st.top() << " ",
            st.pop();
}

int main()
{
    create_graph();
    topo_sort();

    /*
    Following is a Topological Sort of the given graph 
    5 4 2 3 1 0 
    */

    return 0;
}