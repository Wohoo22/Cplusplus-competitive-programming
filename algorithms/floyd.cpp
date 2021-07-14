#include "bits/stdc++.h"
using namespace std;

#define V 4
#define INF 99999

int graph[V][V] = {{0, 5, INF, 10},
                   {INF, 0, 3, INF},
                   {INF, INF, 0, 1},
                   {INF, INF, INF, 0}};

void print(int dist[V][V])
{
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            cout << "(" << u << "," << v << ")"
                 << " = " << dist[u][v] << endl;
}

void floyd()
{
    int dist[V][V];
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            dist[u][v] = graph[u][v];
    for (int k = 0; k < V; k++)
        for (int u = 0; u < V; u++)
            for (int v = 0; v < V; v++)
                dist[u][v] = min(
                    dist[u][v],
                    dist[u][k] + dist[k][v]);

    print(dist);
}

int main()
{
    floyd();
    /*
    Following matrix shows the shortest distances between every pair of vertices
       |  0      1      2      3
    -----------------------------
    0  |  0      5      8      9
    1  | INF     0      3      4
    2  | INF    INF     0      1
    3  | INF    INF    INF     0
    */
    return 0;
}