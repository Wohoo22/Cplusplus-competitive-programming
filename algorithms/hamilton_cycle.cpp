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
    /* Check if this vertex is an adjacent 
    vertex of the previously added vertex. */
    if (graph[path[pos - 1]][v] == 0)
        return false;

    /* Check if the vertex has already been included. 
    This step can be optimized by creating
    an array of size V */
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamilton_cycle_util(int path[], int pos)
{
    // If all vertices are included in Hamilton cycle
    if (pos == V)
    {
        // If path between last point end first point exists
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices as a next candidate
    // in Hamiltonian Cycle. We don't try for 0 as
    // we included 0 as starting point in hamCycle()
    for (int v = 1; v < V; v++)
    {
        // Check if v is suitable for the current hamilton path
        if (is_hamiltonian(v, path, pos))
        {
            path[pos] = v;
            if (hamilton_cycle_util(path, pos + 1))
                return true;

            /* 
            If adding vertex v doesn't lead to a solution, 
            then remove it 
            */
            path[pos] = -1;
        }
    }
    /* If no vertex can be added to 
    Hamiltonian Cycle constructed so far, 
    then return false */
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
    // Init path
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // A hamilton cycle can start anywhere, let's assume it is 0
    path[0] = 0;

    // Find hamilton cycle
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