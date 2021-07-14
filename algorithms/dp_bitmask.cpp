#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define MOD 1000000007

vector<int> cap_list[101];

int dp[1025][101];

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

ll count_ways_util(int mask, int i)
{
    if (mask == final_mask)
        return 1;
    if (i > 100)
        return 0;
    if (dp[mask][i] != -1)
        return dp[mask][i];
    ll ways = count_ways_util(mask, i + 1);
    int size = cap_list[i].size();
    for (int j = 0; j < size; j++)
    {
        if (mask & (1 << cap_list[i][j]))
            continue;
        ways += count_ways_util(mask | (1 << cap_list[i][j]), i + 1);
        ways %= MOD;
    }

    dp[mask][i] = ways;
    return ways;
}

ll count_ways(int n)
{
    final_mask = (1 << n) - 1;
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