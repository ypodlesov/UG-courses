#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

int main() {

    int n;
    cin >> n;
    int x, y, z;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            a[i][j] = x;
        }
    }
    int min_sum = INT_MAX;
    for (int i = 0; i < n; i++) {
        int sum;
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                for (int l = j + 1; l < n; l++) {
                    if (a[i][l]) {
                        sum = a[i][j] + a[i][l] + a[j][l];
                        if (sum < min_sum) {
                            min_sum = sum;
                            x = i + 1;
                            y = j + 1;
                            z = l + 1;
                        }
                    }
                }
            }
        }
    }
    cout << x << ' ' << y << ' ' << z;

    return 0;
}
