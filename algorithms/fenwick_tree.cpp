#include "bits/stdc++.h"
using namespace std;

#define N 12
int arr[N] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};

int fenwick_tree[N + 1];

int query_fenwick_tree(int index)
{
    // Index in fenwick tree is 1 more than array index
    index++;
    int ans = 0;
    // Traverse all ancestors of fenwick_tree[index]
    while (index > 0)
    {
        ans += fenwick_tree[index];
        index -= index & (-index);
    }
    return ans;
}

void update_fenwick_tree(int index, int value)
{
    // Index in fenwick tree is 1 more than array index
    index++;
    // Traverse all ancestor and add value
    while (index <= N)
    {
        fenwick_tree[index] += value;
        index += index & (-index);
    }
}

void construct_fenwick_tree()
{
    for (int i = 1; i <= N; i++)
        fenwick_tree[i] = 0;
    for (int i = 0; i < N; i++)
        update_fenwick_tree(i, arr[i]);
}

int main()
{
    /*
    Must-remember: (x & -x)
    */
    construct_fenwick_tree();
    cout << "Sum [0..5] = " << query_fenwick_tree(5) << endl;
    arr[3] += 6;
    update_fenwick_tree(3, 6);
    cout << "Sum [0..5] after update = " << query_fenwick_tree(5) << endl;
    /*
    [Correct output]
    Sum of elements in arr[0..5] is 12
    Sum of elements in arr[0..5] after update is 18
    */
    return 0;
}