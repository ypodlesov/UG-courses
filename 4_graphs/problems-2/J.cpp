#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

struct edge {
    int a, b, cost;
};

void ford_bell(int n, vector<edge> &e, vector<int> &d, int b) {
    d[b] = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (auto & i : e) {
            if (d[i.a] < INT_MAX) {
                if (d[i.b] > d[i.a] + i.cost) {
                    d[i.b] = d[i.a] + i.cost;
                    flag = true;
                }
            }
        }
    }
}

int main() {

    int n, m, x, y, cost;
    cin >> n >> m;
    vector<edge> e;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> cost;
        e.push_back({x-1, y-1, cost});
    }
    vector<int> d(n, INT_MAX);
    ford_bell(n, e, d, 0);
    for (int i = 0; i < n; i++) {
        if (d[i] < INT_MAX) cout << d[i] << ' ';
        else cout << 30000 << ' ';
    }

    return 0;
}
