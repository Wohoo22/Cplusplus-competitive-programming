#include <bits/stdc++.h>
using namespace std;

#define V 6

int graph[V][V] = {{0, 3, 0, 0, 6, 5},
                   {3, 0, 1, 0, 0, 4},
                   {0, 1, 0, 6, 0, 4},
                   {0, 0, 6, 0, 8, 5},
                   {6, 0, 0, 8, 0, 2},
                   {5, 4, 4, 5, 2, 0}};

void print_mst(vector<pair<int, int>> mst_e, vector<int> mst_w)
{
    int min_w = 0;
    for (int i = 0; i < V - 1; i++)
    {
        cout << "Edge: " << mst_e[i].first << "-" << mst_e[i].second << " "
             << "cost: " << mst_w[i] << endl;
        min_w += mst_w[i];
    }
    cout << "Minimum Weight is " << min_w << endl;
}

int find_parent(int v, int parent[])
{
    while (parent[v] >= 0)
        v = parent[v];
    return v;
}

void kruskal()
{
    int parent[V];

    for (int v = 0; v < V; v++)
        parent[v] = -1;

    vector<pair<int, int>> mst_e;

    vector<int> mst_w;

    int mst_size = 0;
    while (mst_size < V - 1)
    {
        int min_w = INT_MAX;
        pair<int, int> min_edge;

        for (int u = 0; u < V; u++)
            for (int v = 0; v < V; v++)
                if (graph[u][v] > 0 && graph[u][v] < min_w)
                    min_w = graph[u][v],
                    min_edge.first = u,
                    min_edge.second = v;

        int u = find_parent(min_edge.first, parent);
        int v = find_parent(min_edge.second, parent);

        if (u != v)
        {
            parent[v] = u;

            mst_e.push_back(min_edge);
            mst_w.push_back(graph[min_edge.first][min_edge.second]);

            mst_size++;
        }

        graph[min_edge.first][min_edge.second] = INT_MAX;
    }

    print_mst(mst_e, mst_w);
}

int main()
{
    /* Let the given graph is :
     (1)____1___(2)
    /  \       /  \
   3    4     4    6
  /      \   /      \
 /        \ /        \
(0)___5___(5)____5___(3)
 \         |         /
  \        |        /
   \       |       /
    \      2      /
     6     |     8
      \    |    /
       \   |   /
        \  |  /
         \ | /
          (4)
    */

    /*
    Output :
    Edge: 0-1 cost: 3
    Edge: 1-2 cost: 1
    Edge: 1-5 cost: 4
    Edge: 5-4 cost: 2
    Edge: 5-3 cost: 5
    Minimum Weight is 15
    */

    kruskal();

    return 0;
}