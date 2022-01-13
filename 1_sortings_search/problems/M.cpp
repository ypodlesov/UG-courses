#include<bits/stdc++.h>

using namespace std;

short n, k;
int a[10002];

bool pos(int x) {
    int ip = 1;
    int able = 1;
    for (int i = 2; i <= n && able < k; i++) {
        if (a[i] - a[ip] >= x) {
            ip = i;
            able++;
        }
    }
    if (able >= k)
        return true;
    else
        return false;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 0;
    int r = a[n] - a[1] + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (pos(m)) {
            l = m;
        } else  {
            r = m;
        }
    }
    cout << l;
    return 0;
}
