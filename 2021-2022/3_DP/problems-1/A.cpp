#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n+5, 0);
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    for (int i = 4; i <= n+3; i+=2) {
       a[i] = a[i/2] + 1;
       a[i-1] = a[i] + a[(i-2)/2];
    }
    cout << a[n];

    return 0;
}
