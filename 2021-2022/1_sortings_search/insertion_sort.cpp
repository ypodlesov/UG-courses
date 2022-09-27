#include <bits/stdc++.h>

// with all questions and suggestions write to the e-mail:
// ypodlesov@gmail.com

using namespace std;

void insertion_sort(vector<int> &a);

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    insertion_sort(a);
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << endl;
    return 0;
}

void insertion_sort(vector<int> &a) {
    for (int i = 1; i < a.size(); ++i) {
        int x = a[i], j = i - 1;
        while (j >= 0 && x < a[j]) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = x;
    }
}
