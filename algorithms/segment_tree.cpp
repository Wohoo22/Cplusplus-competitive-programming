#include <stdio.h>
#include <math.h>
#define MAX 1000

int tree[MAX] = {0}; 
int lazy[MAX] = {0}; 
int a[] = {1, 3, 5, 7, 9, 11};
int n = 6;

void update_range_util(int si, int ss, int se, int us,
                       int ue, int diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se - ss + 1) * lazy[si];
        if (ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss > se || ss > ue || se < us)
        return;
    if (ss >= us && se <= ue)
    {
        tree[si] += (se - ss + 1) * diff;
        if (ss != se)
        {
            lazy[si * 2 + 1] += diff;
            lazy[si * 2 + 2] += diff;
        }
        return;
    }

    int mid = (ss + se) / 2;
    update_range_util(si * 2 + 1, ss, mid, us, ue, diff);
    update_range_util(si * 2 + 2, mid + 1, se, us, ue, diff);

    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void update_range(int us, int ue, int diff)
{
    update_range_util(0, 0, n - 1, us, ue, diff);
}

int query_util(int ss, int se, int qs, int qe, int si)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se - ss + 1) * lazy[si];
        if (ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss > se || ss > qe || se < qs)
        return 0;
    if (ss >= qs && se <= qe)
        return tree[si];
    int mid = (ss + se) / 2;
    return query_util(ss, mid, qs, qe, 2 * si + 1) +
           query_util(mid + 1, se, qs, qe, 2 * si + 2);
}

int query(int qs, int qe)
{
    return query_util(0, n - 1, qs, qe, 0);
}

void construct_st_util(int ss, int se, int si)
{
    if (ss > se)
        return;
    if (ss == se)
    {
        tree[si] = a[ss];
        return;
    }
    int mid = (ss + se) / 2;
    construct_st_util(ss, mid, si * 2 + 1);
    construct_st_util(mid + 1, se, si * 2 + 2);

    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void construct_st()
{
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

    /*
    Sum of values in given range = 15
    Updated sum of values in given range = 45 
    */

    return 0;
}
