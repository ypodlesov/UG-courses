#include <bits/stdc++.h>
using namespace std;

#define id get<2>(a[i])
#define region get<1>(a[i])
#define score get<0>(a[i])

int n, M, r, parts = 0;
vector<tuple<int,int,int>> a;
vector<int> regs(100005, 0);

int count(int ball) {
    int i = 0;
    vector<bool> regions(r+1, false);
    while (i < a.size() && score >= ball) {
        regions[region] = true;
        ++i;
    }
    int num = i;
    for (int j = 1; j <= r; ++j) {
        if (!regions[j] && regs[j] == 1) {
            ++num;
            regions[j] = true;
        }
    }
    num += parts;
    return num <= M;
}

int main() {

    cin >> n >> M >> r;
    for (int i = 0; i < n; ++i) {
        int idx, reg, sc, part;
        cin >> idx >> reg >> sc >> part;
        if (regs[reg] != -1) regs[reg] = 1;
        if (part) ++parts, regs[reg] = -1;
        else a.push_back({sc, reg, idx});
    }
    sort(a.rbegin(), a.rend());
    int l = 1, r = 2000000000;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (count(m)) r = m;
        else l = m;
    }
    cout << l + 1 << endl;

    return 0;
}
