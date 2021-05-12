#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define MOD 1000000007

// cap_list[i] -> guys that have cap[i]
vector<int> cap_list[101];

// dp[mask][cap] -> ways to assign cap to guys
int dp[1025][101];

// Mask with all n bit set as all n guys wearing cap
int final_mask;

void read_input(int n)
{
    string temp, str;
    int x;
    getline(cin, str);
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        stringstream ss(str);

        while (ss >> temp)
        {
            stringstream s;
            s << temp;
            s >> x;

            cap_list[x].push_back(i);
        }
    }
}

// i -> cap[i]
ll count_ways_util(int mask, int i)
{
    // Every guy has his cap
    if (mask == final_mask)
        return 1;

    // Not every guy has a cap, but out of cap
    if (i > 100)
        return 0;

    // If already computed
    if (dp[mask][i] != -1)
        return dp[mask][i];

    // Ways in which this cap is not included
    ll ways = count_ways_util(mask, i + 1);

    // size is the total number of guys having cap with id i.
    int size = cap_list[i].size();

    // Assign this cap to a guy one by one, and recur for the remaining caps
    for (int j = 0; j < size; j++)
    {
        // If this guy has already had a cap, move to the next guy
        if (mask & (1 << cap_list[i][j]))
            continue;

        // Else assign him with this cap, recur for the remaining caps with the updated mask
        ways += count_ways_util(mask | (1 << cap_list[i][j]), i + 1);
        ways %= MOD;
    }

    dp[mask][i] = ways;
    return ways;
}

ll count_ways(int n)
{
    // Init final_mask
    final_mask = (1 << n) - 1;

    // Init dp[][]
    for (int i = 0; i < 1025; i++)
        for (int j = 0; j < 101; j++)
            dp[i][j] = -1;

    return count_ways_util(0, 1);
}

int main()
{
    /*
    http://www.geeksforgeeks.org/bitmasking-and-dynamic-programming-set-1-count-ways-to-assign-unique-cap-to-every-person/
    Sample Input :
    3               
    5 100 1         
    2               
    5 100
    Sample Output :
    4
    */

    // Number of guys
    int n;
    cin >> n;
    read_input(n);

    cout << "Ways: " << count_ways(n) << endl;

    return 0;
}