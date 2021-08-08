#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INP freopen("S.INP", "r", stdin);
#define ll long long
#define MOD 1000000007
#define CI \
    int ci(char c) { return c - 'a'; }
#define CUTLAST \
    int cut_last(int x, int n) { return x % (int)pow(10, n); }
#define IC \
    char ic(int i) { return "abcdefghijklmnopqrstuvwxyz"[i]; }

/*
    RANDOM:
    rand() % (max – min + 1)
*/

int n, m;
int matrix[109][109];
vector<vector<pair<int,int>>> result;

vector<pair<int,int>> make_group(int ro, int co) {
    return {{ro+1,co},{ro+1,co+1},{ro,co+1},{ro,co}};
}

int count(vector<pair<int,int>> group) {
    int cnt = 0;
    for (int i=0; i<4; i++)
        if (matrix[group[i].first][group[i].second] == 1)
            cnt++;
    return cnt;   
}

void save3(vector<pair<int,int>> group) {
    vector<pair<int,int>> changed;
    for (auto &p : group) {
        if (matrix[p.first][p.second] == 1)
        {
            matrix[p.first][p.second] = 0;
            changed.push_back(p);
        }
    }
    result.push_back(changed);
}

void save2(vector<pair<int,int>> group) {
    vector<pair<int,int>> changed;
    int one = 0;
    for (int i=0; i<4; i++) {
        if (matrix[group[i].first][group[i].second] == 1) {
            matrix[group[i].first][group[i].second] = 0;
            one = i;
            changed.push_back(group[i]);
            break;
        }
    }
    for (int i=0; i<4; i++) {
        if (i != one && matrix[group[i].first][group[i].second] == 0) {
            matrix[group[i].first][group[i].second] = 1;
            changed.push_back(group[i]);
        }
    }
    result.push_back(changed);
    save3(group);
}

void save1(vector<pair<int,int>> group) {
    vector<pair<int,int>> changed;
    int one = 0;
    for (int i=0; i<4; i++) {
        if (matrix[group[i].first][group[i].second] == 1) {
            matrix[group[i].first][group[i].second] = 0;
            one = i;
            changed.push_back(group[i]);
            break;
        }
    }
    int remain = 2;
    for (int i=0; i<4; i++) {
        if (i != one && remain > 0) {
            matrix[group[i].first][group[i].second] = 1;
            changed.push_back(group[i]);
            remain--;
        }
    }
    result.push_back(changed);
    save2(group);
}

void save4(vector<pair<int,int>> group) {
    vector<pair<int,int>> changed;
    for (int i=0; i<3; i++)
    {
        matrix[group[i].first][group[i].second] = 0;
        changed.push_back(group[i]);
    }   
    result.push_back(changed);
    save1(group);
}

void save(vector<pair<int,int>> group) {
    int cnt = count(group);
    if (cnt == 1) save1(group);
    if (cnt == 2) save2(group);
    if (cnt == 3) save3(group);
    if (cnt == 4) save4(group);
}

void rv(int ro, int co) {
    if (matrix[ro][co] == 1)
        matrix[ro][co] = 0;
    else 
        matrix[ro][co] = 1;
}

void do_three(int ro1, int co1, int ro2, int co2, int ro3, int co3) {
    rv(ro1,co1);
    rv(ro2,co2);
    rv(ro3,co3);
    result.push_back({
        {ro1,co1},
        {ro2,co2},
        {ro3,co3}
    });
}

void do_last_two(int ro1, int co1, int ro2, int co2) {
    if (matrix[ro1][co1] == 1 && matrix[ro2][co2] == 1)
        do_three(ro1, co1, ro2, co2, ro1-1, co1);
    else if (matrix[ro1][co1] == 1) 
        do_three(ro1, co1, ro1-1, co1, ro1-1, co1+1);
    else if (matrix[ro2][co2] == 1)
        do_three(ro2, co2, ro1-1, co1, ro1-1, co1+1);
}

void solve()
{
    result.clear();
    for (int ro=n-1; ro>=2; ro--) {
        // pass 1
        for (int co=0; co<=m-3; co++) {
            if (co < m-3) {
                if(matrix[ro][co] == 1)
                    do_three(
                        ro, co,
                        ro, co+1,
                        ro-1, co
                    );
            } else {
                int cnt = 0;
                if (matrix[ro][co+1] == 0) cnt++;
                if (matrix[ro][co+2] == 0) cnt++;

                if (matrix[ro][co] == 1) {
                    if (cnt == 0) {
                        do_three(
                            ro, co,
                            ro, co+1,
                            ro-1, co
                        );
                    } else {
                        do_three(
                            ro, co,
                            ro-1, co,
                            ro-1, co+1
                        );
                    }
                } else {
                    if (cnt == 0) {
                        do_three(
                            ro, co+1,
                            ro-1, co,
                            ro-1, co+1
                        );
                    } else {
                        do_three(
                            ro, co,
                            ro-1, co, 
                            ro-1, co+1
                        );
                        do_three(
                            ro, co,
                            ro-1, co, 
                            ro-1, co+1
                        );
                    }
                }
            }
        }
        // pass 2
        do_last_two(ro,m-2, ro, m-1);
    }


    for (int co=0; co<m-1; co++) {
        vector<pair<int,int>> group = {
            {0, co}, {0, co+1}, {1, co}, {1, co+1}
        };
        if (count(group) == 3)
            save(group);
    }

    for (int co=0; co<=m-1; co+=2) {
        if (co + 1 >= m)
            break;
        save({
            {0,co},
            {0,co+1},
            {1,co},
            {1,co+1}
        });
    }

    if (m % 2 != 0) {
        save({
            {0,m-1},
            {0,m-2},
            {1,m-1},
            {1,m-2}
        });
    }



    // cout << result.size() << endl;
    // for (int i=0; i<result.size(); i++)
    // {
    //     for (int j=0; j<3; j++)
    //         cout << result[i][j].first + 1 << ' ' << result[i][j].second + 1 << ' ';
    //     cout << endl;
    // }
}

int input_matrix[109][109];


bool ok(int n, int m) {
    if (result.size() > m * n) {
        cout << "FAIL\n";
        cout << n << ' ' <<  m << endl;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++){
                cout << input_matrix[i][j];
            }
            cout << endl;
        }
        cout << "result size: " << result.size() << endl;
        return false;
    }
    return true;
}

void check() {
    int t = 10000;
    while(t--) {
        n = rnd.next(2, 20);
        m = rnd.next(2, 20);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int p = rnd.next(0, 1);
                input_matrix[i][j] = p;
                matrix[i][j] = p;
            }
        }
        solve();
        if (!ok(n, m))
            break;
    }
}

int main()
{
    check();
}
/* 
    [Linux] Set/Unset read-only:
    sudo chattr +i TEMPLATE.cpp
    sudo chattr -i TEMPLATE.cpp
*/