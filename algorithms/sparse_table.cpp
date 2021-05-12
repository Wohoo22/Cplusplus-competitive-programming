#include "bits/stdc++.h"
using namespace std;

const int a[] = {7, 2, 3, 0, 5, 10, 3, 12, 18};
const int n = 9;

int sparse_table[n][n];

void build_sparse_table()
{
    // Init value for intervals with length 1
    for (int i = 0; i < n; i++)
        sparse_table[i][0] = a[i];

    // Computes values from smaller to bigger intervals
    // (1 << n) == 2^n
    for (int j = 1; (1 << j) <= n; j++)
    {
        // Compute minimum value for all intervals with size 2^j
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            // sparse_table[1][2^4]
            sparse_table[i][j] = min(
                sparse_table[i][j - 1],                   // sparse_table[1][2^3]
                sparse_table[i + (1 << (j - 1))][j - 1]); // sparse_table[1+2^3][2^3]
        }
    }
}

int query(int L, int R)
{
    // Highest power of 2 -> P
    // P <= (R-L+1)
    int P = (int)log2(R - L + 1);

    return min(
        sparse_table[L][P],
        sparse_table[R - (1 << P) + 1][P]);
}

int main()
{
    // Range minimum query by sparse table

    build_sparse_table();
    cout << query(0, 4) << endl;
    cout << query(4, 7) << endl;
    cout << query(7, 8) << endl;

    /*
    Minimum of [0, 4] is 0
    Minimum of [4, 7] is 3
    Minimum of [7, 8] is 12
    */

    return 0;
}