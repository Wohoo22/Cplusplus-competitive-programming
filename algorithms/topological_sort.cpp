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

stack<int> st;
void topo_sort_util(int u, bool visited[])
{
    visited[u] = true;
    for (int v = 0; v < V; v++)
        if (graph[u][v] && !visited[v])
            topo_sort_util(v, visited);
    st.push(u);
}

void topo_sort()
{
    bool visited[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;
    for (int v = 0; v < V; v++)
        if (!visited[v])
            topo_sort_util(v, visited);

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