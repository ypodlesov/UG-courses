#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    int n;
    cin >> n;
    vector<int> a(n), length(n, 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) length[i] = max(length[i], length[j] + 1);
        }
    }
    cout << *max_element(length.begin(), length.end()) << endl;

    return 0;
}
