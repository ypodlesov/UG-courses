#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define ff first
#define ss second

int n, num, res;
vector<vector<char>> c;
vector<vector<int>> a;

int main() {

    cin >> n;
    c.assign(n+1, vector<char>(n+1, 0)), a.assign(n+1, vector<int>(n+1, 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> c[i][j];
            if (c[i][j] == 'C') ++num;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (res > num / 2) break;
        for (int j = 1; j <= n; ++j) {
            if (c[i][j] == 'C') ++res;
            if (res <= num / 2) a[i][j] = 1;
            else break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cout << a[i][j];
        cout << endl;
    }

    return 0;
}
