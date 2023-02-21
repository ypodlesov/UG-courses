#include <bits/stdc++.h>

using namespace std;
#define ll long long

using namespace std;


int main() {

    int n;
    cin >> n;
    vector<int> d(n+1, 0);
    d[1] = 0;
    d[2] = 1;
    for (int i = 3; i <= n; ++i) {
        d[i] = d[i-1] + 1;
        if (i % 2 == 0 && i % 3 == 0) {
            d[i] = min(d[i], min(d[i/2] + 1, d[i/3] + 1));
        } else if (i % 2 == 0) {
            d[i] = min(d[i], d[i/2] + 1);
        } else if (i % 3 == 0) {
            d[i] = min(d[i], d[i/3] + 1);
        }
    }
    int x = n;
    deque<int> w;
    while (x != 1) {
        if (x % 2 == 0 && x % 3 == 0) {
            if (d[x-1] < d[x/2]) {
                if (d[x-1] < d[x/3]) {
                    x--;
                    w.push_front(1);
                } else {
                    x /= 3;
                    w.push_front(3);
                }
            } else {
                if (d[x/2] < d[x/3]) {
                    x /= 2;
                    w.push_front(2);
                } else {
                    x /= 3;
                    w.push_front(3);
                }
            }
        } else if (x % 2 == 0) {
            if (d[x/2] < d[x-1]) {
                x /= 2;
                w.push_front(2);
            } else {
                x--;
                w.push_front(1);
            }
        } else if (x % 3 == 0) {
            if (d[x/3] < d[x-1]) {
                x /= 3;
                w.push_front(3);
            } else {
                x--;
                w.push_front(1);
            }
        } else {
            x--;
            w.push_front(1);
        }
    }
    for (auto & i : w) cout << i;


    return 0;
}
