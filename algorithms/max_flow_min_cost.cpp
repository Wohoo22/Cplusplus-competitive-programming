#include "bits/stdc++.h"
using namespace std;
#define V 5
int cap[V][V] = {{0, 3, 1, 0, 3},
                 {0, 0, 2, 0, 0},
                 {0, 0, 0, 1, 6},
                 {0, 0, 0, 0, 2},
                 {0, 0, 0, 0, 0}};

int cost[V][V] = {{0, 1, 0, 0, 2},
                  {0, 0, 0, 3, 0},
                  {0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 1},
                  {0, 0, 0, 0, 0}};

void max_flow()
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SOLUTION.INP", "r", stdin);
    max_flow();
    return 0;
}