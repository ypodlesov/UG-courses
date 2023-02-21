#include <bits/stdc++.h>
using namespace std;

struct edge {
    short a, b, cost;
};

int main() {

    int n;
    cin >> n;
    vector<edge> e;
    vector<int> d(n+1, INT_MAX);
    d[1] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++) d[j] = min(d[j], d[i] + ((179*i + 719*j) % 1000) - 500);

    cout << d[n];

    return 0;
}
