
// C++ program to demonstrate default behaviour of
// sort() in STL.
#include <bits/stdc++.h>
using namespace std;

class Obj
{
public:
    int val;
};

bool comp(Obj a, Obj b)
{
    // Descending objects
    return a.val > b.val;
}

int main()
{
    /*
    Sort array
    */

    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    /*Here we take two parameters, the beginning of the
    array and the length n upto which we want the array to
    be sorted*/
    sort(arr, arr + n);

    /*
    Sort vector
    */

    vector<int> v{1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    // Ascending
    sort(v.begin(), v.end());

    // Descending
    sort(v.begin(), v.end(), greater<int>());

    /*
    Sort object
    */
    vector<Obj> objects(10);
    sort(objects.begin(), objects.end(), comp);

    return 0;
}