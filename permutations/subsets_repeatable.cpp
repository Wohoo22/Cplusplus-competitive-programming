#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets;

void CombinationRepetitionUtil(int chosen[], vector<int> &arr,
					int index, int r, int start, int end)
{
	if (index == r)
	{
        vector<int> ss;
		for (int i = 0; i < r; i++) {
            ss.push_back(arr[chosen[i]]);
        }

        for (int i = 0; i < r; i++) 
            cout<<" "<< arr[chosen[i]];
         cout<<"\n";
         
        subsets.push_back(ss);
		return;
	}
	for (int i = start; i <= end; i++)
	{
		chosen[index] = i;
		CombinationRepetitionUtil(chosen, arr, index + 1,
											r, i, end);
	}
	return;
}

void CombinationRepetition(vector<int> &arr, int n, int r)
{
    subsets.clear();
	int chosen[r+1];
	CombinationRepetitionUtil(chosen, arr, 0, r, 0, n-1);
}

int main()
{
	vector<int> arr = {1, 2, 3, 4};
	int n = 4;
	int r = 2;
	CombinationRepetition(arr, n, r);
	return 0;
}
