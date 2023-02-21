#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    int n;
    cin >> n;
    vector<int> cost(n+1), d(n+1);
    for (int i = 1; i <= n; ++i) cin >> cost[i];
    d[1] = cost[1];
    d[2] = cost[2];
    for (int i = 3; i <= n; ++i) d[i] = min(d[i-1], d[i-2]) + cost[i];
    cout << d[n];

    return 0;
}
