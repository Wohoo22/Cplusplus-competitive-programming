#include "bits/stdc++.h"
using namespace std;

int partition(int arr[], int l, int r, int k);

int find_median(int arr[], int n)
{
    sort(arr, arr + n);
    return arr[n / 2];
}

int kth_smallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r - l + 1;

        int i, median[(n + 4) / 5];
        for (i = 0; i < n / 5; i++)
            median[i] = find_median(arr + l + i * 5, 5);
        if (i * 5 < n)
        {
            median[i] = find_median(arr + l + i * 5, n % 5);
            i++;
        }

        int med_of_med = (i == 1) ? median[i - 1] : kth_smallest(median, 0, i - 1, i / 2);

        int pos = partition(arr, l, r, med_of_med);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kth_smallest(arr, l, pos - 1, k);

        return kth_smallest(arr, pos + 1, r, k - pos + l - 1);
    }

    return INT_MAX;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r, int x)
{
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;
    swap(&arr[i], &arr[r]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = 7;
    int k = 4;
    cout << "Result: " << kth_smallest(arr, 0, n - 1, k) << endl;
    // Result = 7
    return 0;
}