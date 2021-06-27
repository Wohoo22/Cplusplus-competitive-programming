#include "bits/stdc++.h"
using namespace std;

int main()
{
    // SET

    set<int> s;

    // insert
    s.insert(10);
    s.insert(20);

    // element in set
    bool is_in = s.find(10) != s.end();
    if (is_in)
        cout << "10 in set\n";

    // loop though set
    for (auto e : s)
        cout << e << endl;

    // MAP

    map<int, int> m;

    // put
    m[1] = 10;
    m[2] = 20;

    // contains
    bool contains = m.find(1) != m.end();
    if (contains)
        cout << "1 in map\n";

    // loop through map
    for (auto const &x : m)
    {
        std::cout << x.first // string (key)
                  << ':'
                  << x.second // string's value
                  << std::endl;
    }
}
