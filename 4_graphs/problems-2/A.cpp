#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

vector<vector<int>> a(505, vector<int>(505));
vector<pair<int,int>> b;

int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j]) b.emplace_back(i,j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!a[i][j]) {
                int res = INT_MAX;
                for (auto & k : b) res = min(res, abs(i - k.f) + abs(j - k.s));
                cout << res << ' ';
            } else cout << 0 << ' ';
        }
        cout << endl;
    }

    return 0;
}
