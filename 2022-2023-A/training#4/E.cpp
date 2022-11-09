#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int 
main() 
{
    int n;
    cin >> n;
    vector<int> a(n);
    ll left_sum = 0;
    ll right_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        right_sum += a[i];
    }
    ll delta = right_sum + 1;
    int idx = -1;
    for (int i = 0; i < n; ++i) {
        left_sum += a[i];
        right_sum -= a[i];
        if (abs(right_sum - left_sum) < delta) {
            delta = abs(right_sum - left_sum);
            idx = i;
        }
    }
    cout << idx + 1 << endl;


    return 0;
}



