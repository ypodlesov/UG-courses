#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;
    vector<long long> a(n);
    priority_queue<long long> Q1, Q2;
    long long S = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        Q2.push(a[i]);
        S += a[i];
    }
    Q1.push(S);
    while (!Q1.empty() && !Q2.empty()) {
        long long q1 = Q1.top();
        long long q2 = Q2.top();
        if (q1 == q2) {
            Q1.pop();
            Q2.pop();
        } else if (q1 < q2) {
            cout << "NO\n";
            return;
        } else {
            Q1.pop();
            long long p1 = q1 / 2;
            long long p2 = (q1 + 1) / 2;
            Q1.push(p1);
            Q1.push(p2);
        }
    }
    cout << "YES\n";
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
