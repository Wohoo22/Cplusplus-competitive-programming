#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define V 5

bool graph[V][V] = {{0, 1, 0, 1, 0},
                    {1, 0, 1, 1, 1},
                    {0, 1, 0, 0, 1},
                    {1, 1, 0, 0, 1},
                    {0, 1, 1, 1, 0}};

bool is_hamiltonian(int v, int path[], int pos)
{
    if (graph[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamilton_cycle_util(int path[], int pos)
{
    if (pos == V)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++)
    {
        if (is_hamiltonian(v, path, pos))
        {
            path[pos] = v;
            if (hamilton_cycle_util(path, pos + 1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

void print_hamilton_cycle(int path[])
{
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
}

bool hamilton_cycle()
{
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
    path[0] = 0;
    if (hamilton_cycle_util(path, 1))
    {
        print_hamilton_cycle(path);
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    hamilton_cycle();
    // Output should be:  0  1  2  4  3
    return 0;
}