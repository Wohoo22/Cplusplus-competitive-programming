#include "bits/stdc++.h"
using namespace std;

#define V 5

int graph[V][V] = {
    {0, 0, 1, 1, 0},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0}};

int ID;

void tarjan_util(int v,                                               
                 int disc[], int low[], bool in_st[], stack<int> &st) 
{
    disc[v] = low[v] = ++ID;
    st.push(v);
    in_st[v] = true;
    for (int u = 0; u < V; u++)
    {
        if (graph[v][u] > 0)
        {
            if (disc[u] == -1)
            {
                tarjan_util(u, disc, low, in_st, st);
                low[v] = min(low[v], low[u]);
            }
            else if (in_st[u])
            {
                low[v] = min(low[v], disc[u]);
            }
        }
    }
    if (low[v] == disc[v])
    {
        int top;
        while (st.top() != v)
        {
            top = st.top();
            st.pop();
            in_st[top] = false;
            cout << top << " ";
        }
        top = st.top();
        st.pop();
        in_st[top] = false;

        cout << top << endl;
    }
}

void tarjan()
{
    int disc[V];
    int low[V];
    bool in_st[V];

    for (int v = 0; v < V; v++)
    {
        disc[v] = low[v] = -1;
        in_st[v] = false;
    }

    stack<int> st;

    ID = 0;

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