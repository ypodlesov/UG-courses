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

const double C = 0.99;
int n, m, base;

int sub(vector<vector<int>> &a, int x, int y) {
    int cnt = 0;
    for (int i = x + 1; i <= n; ++i) {
        for (int j = y + 1; j <= m; ++j) {
            if (a[x][y] == a[i][j] && a[x][y] == a[i][y] && a[x][y] == a[x][j]) ++cnt;
        }
    }
    return cnt;
}

int count_bad(vector<vector<int>> &a) {
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            cnt += sub(a, i, j);
        }
    }
    return cnt;
}

void print(vector<vector<int>> &a) {
    for (int i = 0; i <= n; ++i) {
        cout << "{";
        for (int j = 0; j <= m; ++j) {
            cout << a[i][j];
            if (j < m) cout << ", ";
        }
        if (i < n) cout << "},\n";
        else cout << "}\n";
    }
}

void gen(vector<vector<int>> &a) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = rand() % base + 1;
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

double rnd() {
    return double(rand()) / RAND_MAX;
}

int main() {

    cin >> n >> m >> base;
    clock_t start = clock();
    vector<vector<int>> a;
    int cur;
    while (true) {
        int k = 5000;
        double t = 1;
        a.assign(n+1, vector<int>(m+1));
        gen(a);
        cur = count_bad(a);
        while (k-- && cur > 0) {
            t *= C;
            int x = rand() % n + 1, y = rand() % m + 1;
            int tmp = a[x][y];
            while (tmp == a[x][y]) tmp = rand() % base + 1;
            int old = a[x][y];
            a[x][y] = tmp;
            int delta = update(a, x, y, old);
            if (exp(double(-delta) / t)) cur += delta;
            else a[x][y] = old;
        }
        if (cur == 0) break;
    }
    // cout << count_bad(a) << endl;
    print(a);



    clock_t end = clock();
    cout << (long double)(end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}
