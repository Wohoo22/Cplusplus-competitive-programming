#include "bits/stdc++.h"
using namespace std;

#define V 5

int graph[V][V] = {
    {0, 0, 1, 1, 0},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0}};

// Keep track of the discovering time of a vertice
int ID;

void tarjan_util(int v,                                               // current vertice
                 int disc[], int low[], bool in_st[], stack<int> &st) // immutable objects
{
    // Assign an id to v
    disc[v] = low[v] = ++ID;

    // Add v to stack
    st.push(v);
    in_st[v] = true;

    // Vist all neighbors u of v
    for (int u = 0; u < V; u++)
    {
        if (graph[v][u] > 0)
        {
            // If u is not visited
            if (disc[u] == -1)
            {
                // Find low link of u
                tarjan_util(u, disc, low, in_st, st);
                low[v] = min(low[v], low[u]);
            }
            // If u is in the stack
            else if (in_st[u])
            {
                // Update low for v
                low[v] = min(low[v], disc[u]);
            }
        }
    }

    // Print the SCC
    if (low[v] == disc[v])
    {
        int top;
        while (st.top() != v)
        {
            // Pop from stack
            top = st.top();
            st.pop();
            in_st[top] = false;

            // Print
            cout << top << " ";
        }
        // Pop last item
        top = st.top();
        st.pop();
        in_st[top] = false;

        // Print last item
        cout << top << endl;
    }
}

void tarjan()
{
    // Save disc of each node
    int disc[V];
    // Save low link value of each node
    int low[V];
    // Save elements that are in the stack
    bool in_st[V];

    // Init disc[] low[] in_st[]
    for (int v = 0; v < V; v++)
    {
        disc[v] = low[v] = -1;
        in_st[v] = false;
    }

    // Stack
    stack<int> st;

    // Init static id
    ID = 0;

    // Find SCC
    for (int v = 0; v < V; v++)
    {
        if (disc[v] == -1)
            tarjan_util(v, disc, low, in_st, st);
    }
}

int main()
{
    tarjan();
    return 0;
}