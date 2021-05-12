#include "bits/stdc++.h"
using namespace std;

#define MAX 1000

const int arr[] = {1, 3, 5, 7, 9, 11};
const int n = 6;

// Store segment tree's nodes and lazy updates
int segment_tree[MAX];
int lazy[MAX];

// segment_tree[si]
// Starting and ending of current segment [ss...se]
// Update onrange [us...ue]
// diff - value to add to all elements in the range
void update_range_util(int si, int ss, int se, int us, int ue, int diff)
{
    // Lazy flag not 0 -> there is a pending update
    if (lazy[si] != 0)
    {
        // Apply the pending update
        segment_tree[si] += (se - ss + 1) * lazy[si];

        // Push the lazy to the leaf nodes if they exist
        if (ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        // Unset the lazy for the current node
        lazy[si] = 0;
    }

    // Out of range
    if (ss > se || ss > ue || se < us)
        return;

    // Current segment is fully in range
    if (ss >= us && se <= ue)
    {
        // Add the diff to the current node
        segment_tree[si] += (se - ss + 1) * diff;

        // Push the diff as a lazy value to 2 child nodes
        if (ss != se)
        {
            lazy[si * 2 + 1] += diff;
            lazy[si * 2 + 2] += diff;
        }
        return;
    }

    // If this segment is overlap the update range, recur for its children
    int mid = (ss + se) / 2;
    update_range_util(si * 2 + 1, ss, mid, us, ue, diff);
    update_range_util(si * 2 + 2, mid + 1, se, us, ue, diff);

    // Update this node value by the result of its children
    segment_tree[si] = segment_tree[si * 2 + 1] + segment_tree[si * 2 + 2];
}

// Update onrange [us...ue]
// diff - value to add to all elements in the range
void update_range(int us, int ue, int diff)
{
    update_range_util(0, 0, n - 1, us, ue, diff);
}

// Starting and ending of current segment [ss...se]
// Query on range arr[qs...qe]
// segment_tree[si]
int query_util(int ss, int se, int qs, int qe, int si)
{
    // Lazy flag not 0 -> there is a pending update
    if (lazy[si] != 0)
    {
        // Apply update to current segment tree node
        segment_tree[si] += (se - ss + 1) * lazy[si];

        // Push lazy value to 2 child nodes if they exist
        if (ss != se)
            lazy[si * 2 + 1] += lazy[si],
                lazy[si * 2 + 2] += lazy[si];

        // Unset the lazy of the current node
        lazy[si] = 0;
    }

    // Out of range
    if (ss > se || ss > qe || se < qs)
        return 0;

    // At this point lazy updates are done
    // We can return result of the query

    // If this segment lies in range
    if (ss >= qs && se <= qe)
        return segment_tree[si];

    // Else this segment is overlapping the range
    int mid = (ss + se) / 2;
    return query_util(ss, mid, qs, qe, 2 * si + 1) +
           query_util(mid + 1, se, qs, qe, 2 * si + 2);
}

// Query on range arr[qs...qe]
int query(int qs, int qe)
{
    return query_util(0, n - 1, qs, qe, 0);
}

// arr[ss...se]
// segment_tree[si]
void construct_st_util(int ss, int se, int si)
{
    // Range with no element
    if (ss > se)
        return;

    // Range with only one element
    if (ss == se)
    {
        segment_tree[si] = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;
    // First child node is (si * 2) + 1
    construct_st_util(ss, mid, si * 2 + 1);
    // Second child node is (si * 2) + 2
    construct_st_util(mid + 1, se, si * 2 + 2);

    // Value of current node is sum of 2 child nodes
    segment_tree[si] = segment_tree[si * 2 + 1] + segment_tree[si * 2 + 2];
}

void construct_st()
{
    // Construct segment tree from the whole array
    construct_st_util(0, n - 1, 0);
}

int main()
{
    construct_st();

    printf("Sum of values in given range = %d\n",
           query(1, 3));

    update_range(1, 5, 10);

    printf("Updated sum of values in given range = %d\n",
           query(1, 3));

    /* correct output:
    Sum of values in given range = 15
    Updated sum of values in given range = 45 
    */

    return 0;
}