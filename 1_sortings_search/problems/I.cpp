#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool cmp(int a, int b) {
    return a > b;
}

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), cmp);
    int sum = 0;
    for (int i = 0; i < a.size(); ++i) {
        if ((i + 1) % 3) sum += a[i];
    }
    cout << sum << endl;

    return 0;
}
