#include <bits/stdc++.h>
using namespace std;

struct edge {
    int a, b, cost;
};

int main() {

    int n, y;
    cin >> n;
    vector<edge> e;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> y;
            if (y < 100000) e.push_back({i, j, y});
        }
    }

    vector<int> d(n, 0);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto & j : e) {
            if (d[j.b] > d[j.a] + j.cost) {
                d[j.b] = max(INT_MIN, d[j.a] + j.cost);
                p[j.b] = j.a;
                x = j.b;
            }
        }
    }

    if (x == -1) cout << "NO";
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) x = p[x];
        vector<int> w(1, x);
        for (int u = p[x]; ; u = p[u]) {
            w.push_back(u);
            if (u == x) break;
        }
        cout << w.size() << endl;
        reverse(w.begin(), w.end());
        for (int i : w) cout << i + 1 << ' ';
    }

    return 0;
}
