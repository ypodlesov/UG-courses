#include <bits/stdc++.h>

// with all questions and suggestions write to the e-mail:
// ypodlesov@gmail.com

using namespace std;

void max_heapify(vector<int> &a, int i, int heap_size);
void build_max_heap(vector<int> &a);
void heapsort(vector<int> &a);

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    heapsort(a);
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << endl;

    return 0;
}

void max_heapify(vector<int> &a, int i, int heap_size) {
    int left = i * 2 + 1, right = i * 2 + 2, largest = i;
    if (left < heap_size && a[left] > a[largest]) largest = left;
    if (right < heap_size && a[right] > a[largest]) largest = right;
    if (largest != i) {
        swap(a[largest], a[i]);
        max_heapify(a, largest, heap_size);
    }
}

void build_max_heap(vector<int> &a) {
    for (int i = a.size() / 2; i >= 0; --i) max_heapify(a, i, a.size());
}

void heapsort(vector<int> &a) {
    build_max_heap(a);
    int heap_size = a.size();
    for (int i = a.size() - 1; i > 0; --i) {
        swap(a[i], a[0]);
        --heap_size;
        max_heapify(a, 0, heap_size);
    }
}
