#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    int N, m, j = 0, max_used = 0;
    vector<bool> check(10005);
    check[0] = 1;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> m;
        max_used += m;
        for (j = max_used; j >= m; --j)
            if (check[j - m]) check[j] = true;
    }
    if (max_used % 2 == 0 && check[max_used/2]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
