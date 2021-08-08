// C++ Program to print all combination of size r in
// an array of size n
#include "bits/stdc++.h"
using namespace std;

void combination_util(int arr[], int n, int r, int index,
					int data[], int i,  vector<vector<int>> res)
{
	if (index == r) {
		for (int j = 0; j < r; j++)
			printf("%d ", data[j]);
		printf("\n");

        vector<int> ans;
        for (int j = 0; j < r; j++)
            ans.push_back(data[j]);
        res.push_back(ans);

		return;
	}

	if (i >= n)
		return;

	data[index] = arr[i];
	combination_util(arr, n, r, index + 1, data, i + 1, res);

	combination_util(arr, n, r, index, data, i + 1, res);
}

void gen_combination_util(int arr[], int n, int r, vector<vector<int>> res)
{
	int data[r];
	combination_util(arr, n, r, 0, data, 0, res);
}

vector<vector<int>> gen_combination(vector<int> arr, int r) {
    int a[arr.size()];
    for (int i=0; i<arr.size(); i++)
        a[i] = arr[i];

    vector<vector<int>> res;
    gen_combination_util(a,arr.size(), r, res);
    return res;
}

int main()
{
    vector<int> arr = { 10, 20, 30, 40, 50 };
	int r = 3;
	gen_combination(arr,  r);
	return 0;
}
