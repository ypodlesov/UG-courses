#include <bits/stdc++.h>

// with all questions and suggestions write to the e-mail:
// ypodlesov@gmail.com

using namespace std;

void quicksort(vector<int> &a, int left, int right);
int partition(vector<int> &a, int left, int right);

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << endl;
    return 0;
}

void quicksort(vector<int> &a, int left, int right) {
    if (left >= right) return;
    int m = partition(a, left, right);
    quicksort(a, left, m - 1);
    quicksort(a, m + 1, right);
}

int partition(vector<int> &a, int left, int right) {
    int x = a[right];
    int j = left - 1;
    for (int i = left; i < right; ++i) {
        if (a[i] <= x) {
            ++j;
            swap(a[j], a[i]);
        }
    }
    ++j;
    swap(a[j], a[right]);
    return j;
}
