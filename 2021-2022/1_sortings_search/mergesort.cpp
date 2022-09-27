#include <bits/stdc++.h>

// with all questions and suggestions write to the e-mail:
// ypodlesov@gmail.com

using namespace std;

void merge(vector<int> &a, int left, int right, int mid);
void merge_sort(vector<int> &a, int left, int right);

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << endl;

    return 0;
}

void merge(vector<int> &a, int left, int right, int mid) {
    vector<int> b(mid - left + 1);
    vector<int> c(right - mid);
    for (int i = 0; i < b.size(); ++i) b[i] = a[i + left];
    for (int i = 0; i < c.size(); ++i) c[i] = a[i + mid + 1];
    int i = 0, j = 0, k = left;
    while (i < b.size() && j < c.size()) {
        if (b[i] < c[j]) {
            a[k] = b[i];
            ++i;
        } else {
            a[k] = c[j];
            ++j;
        }
        ++k;
    }
    while (i < b.size()) {
        a[k] = b[i];
        ++k;
        ++i;
    }
    while (j < c.size()) {
        a[k] = c[j];
        ++k;
        ++j;
    }
}

void merge_sort(vector<int> &a, int left, int right) {
    if (left == right) return;
    int mid = (left + right) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a, left, right, mid);
}
