#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back

int a[102];
bool able[102][52][5002];
vector<int> b, c;

int main() {

    able[0][0][0] = true;
    int n, m = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
       cin >> a[i];
       m += a[i];
    }
    if (m % 2 != 0 || n % 2 != 0) {
       cout << "No solution";
       return 0;
    } else m /= 2;

    for (int i = 1; i <= n; ++i) {
        for (int cnt = 0; cnt <= min(i, n / 2); ++cnt){
            for (int sum = 0; sum <= m; ++sum) {
                able[i][cnt][sum] = able[i - 1][cnt][sum];
                if (cnt > 0 && sum >= a[i] && able[i - 1][cnt - 1][sum - a[i]]) able[i][cnt][sum] = true;
            }
        }
    }
    if (able[n][n/2][m] == true) {
       int cnt = n/2;
       for (int i = n; i >= 1; --i) {
           if (cnt > 0 && m >= a[i] && able[i - 1][cnt - 1][m - a[i]]) {
               b.PB(i);
               --cnt;
               m -= a[i];
           } else c.PB(i);
       }
       for (int i = 0; i < c.size(); ++i) cout << c[i] << ' ';
       cout << endl;
       for(int i = 0; i < b.size(); ++i) cout << b[i] << ' ';
    } else cout << "No solution";

    return 0;
}
