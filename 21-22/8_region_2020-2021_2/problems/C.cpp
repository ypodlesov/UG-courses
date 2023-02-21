// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second

int n, m, c;
const double C = 0.99;

int sub(const vector<vector<int>> &a, int x, int y) {
    int cnt = 0;
    for (int i = x + 1; i <= n; ++i) {
        for (int j = y + 1; j <= m; ++j) {
            if (a[x][y] == a[i][j] && a[x][y] == a[i][y] && a[x][y] == a[x][j]) ++cnt;
        }
    }
    return cnt;
}

int count_bad(const vector<vector<int>> &a) {
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            cnt += sub(a, i, j);
        }
    }
    return cnt;
}

void gen(vector<vector<int>> &a) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i].PB(rand() % c + 1);
        }
    }
}

int update(const vector<vector<int>> &a, int x, int y, int old) {
    int delta = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == x) continue;
        for (int j = 1; j <= m; ++j) {
            if (j == y) continue;
            if (a[x][y] == a[i][j] && a[x][y] == a[i][y] && a[x][y] == a[x][j]) ++delta;
            else {
                if (old == a[i][j] && old == a[i][y] && old == a[x][j]) --delta;
            }
        }
    }
    return delta;
}

int main() {

    cin >> n >> m >> c;
    vector<vector<int>> a;
    if (c == 2) {
        int cur;
        while (true) {
            int k = 5000;
            double t = 1;
            a.assign(n+1, vector<int>(1));
            gen(a);
            cur = count_bad(a);
            while (k-- && cur > 0) {
                t *= C;
                int x = rand() % n + 1, y = rand() % m + 1;
                int tmp = a[x][y];
                while (tmp == a[x][y]) tmp = rand() % c + 1;
                int old = a[x][y];
                a[x][y] = tmp;
                int delta = update(a, x, y, old);
                if (exp(double(-delta) / t)) cur += delta;
                else a[x][y] = old;
            }
            if (cur == 0) break;
        }
    } else {
        a = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 2, 3, 1, 3, 2, 2, 1, 2, 1, 3},
            {0, 2, 3, 3, 2, 3, 1, 1, 3, 2, 1},
            {0, 3, 2, 3, 1, 2, 3, 1, 1, 2, 2},
            {0, 3, 1, 2, 3, 1, 2, 3, 3, 2, 1},
            {0, 1, 3, 2, 2, 2, 3, 3, 1, 1, 1},
            {0, 1, 2, 3, 2, 1, 1, 3, 2, 3, 3},
            {0, 1, 1, 2, 3, 3, 3, 1, 2, 3, 2},
            {0, 3, 3, 1, 2, 1, 2, 2, 1, 3, 2},
            {0, 3, 1, 1, 1, 3, 1, 2, 2, 2, 3},
            {0, 2, 2, 2, 1, 1, 3, 2, 3, 1, 3}
        };
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}


// {2, 2, 2, 1, 1, 1},
// {1, 2, 1, 2, 1, 2},
// {2, 1, 1, 2, 2, 1},
// {1, 1, 2, 1, 2, 2}
