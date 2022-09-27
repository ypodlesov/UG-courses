#include <bits/stdc++.h>

using namespace std;

#define ll long long
//#define f first
//#define s second
//#define sp_ceil 998244353
//#define sp_floor -1000000000 - 7

using namespace std;

void f(int n, int l) {
    vector<int> a;
    while (n != 0) {
        a.push_back(n%2);
        n /= 2;
    }
    while (a.size() < l) a.push_back(0);
    reverse(a.begin(), a.end());
    for (auto & i : a) cout << i;
    cout << endl;
}

void func(vector<int> &a, vector<bool> &used, int n) {
    if (a.size() == n) {
        for (auto & i : a) cout << i;
        cout << endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                a.push_back(i);
                used[i] = true;
                func(a, used, n);
                a.pop_back();
                used[i] = false;
            }
        }
    }
}


int main() {

    int n;
    cin >> n;
    vector<int> a;
    vector<bool> used(n+1, false);
    func(a, used, n);

    return 0;
}
