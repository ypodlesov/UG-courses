#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back

int w[102];
bool able[102][52][5002];
vector<int> b, c;

int main() {

    able[0][0][0] = true;
    int n, m = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
       cin >> w[i];
       m += w[i];
    }
    if (m % 2 != 0 || n % 2 != 0) {
       cout << "No solution\n";
       return 0;
    } else m /= 2;

    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k <= min(i, n / 2); ++k){
            for (int j = 0; j <= m; ++j) {
                able[i][k][j] = able[i - 1][k][j];
                if (k > 0 && j >= w[i]) able[i][k][j] |= able[i - 1][k - 1][j - w[i]];
            }
        }
    }
    if (able[n][n/2][m] == true) {
       int cnt = n/2;
       for (int i = n; i >= 1; --i) {
           if (cnt > 0 && m >= w[i] && able[i - 1][cnt - 1][m - w[i]]) {
               b.PB(i);
               --cnt;
               m -= w[i];
           } else c.PB(i);
       }
       for (int i = 0; i < c.size(); ++i) cout << c[i] << ' ';
       cout << endl;
       for(int i = 0; i < b.size(); ++i) cout << b[i] << ' ';
    } else cout << "No solution";

    return 0;
}
