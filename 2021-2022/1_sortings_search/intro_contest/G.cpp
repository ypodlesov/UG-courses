#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define f first
#define s second
#define sp_ceil 1000000000 + 7
#define sp_floor -1000000000 - 7

int main() {

    int n, k;
    cin >> n >> k;
    set<int> endings;
    vector<int> beginnings(n + 1);
    vector<pair<int,int>> ans;
    while (k--) {
        int type;
        cin >> type;
        if (type & 1) {
            int left, right;
            cin >> left >> right;
            bool flag = true;
            if (endings.lower_bound(left) != endings.end())
                if (beginnings[*endings.lower_bound(left)] <= right) flag = false;
            if (flag) {
                ans.emplace_back(1, 0);
                endings.insert(right);
                beginnings[right] = left;
            } else {
                ans.emplace_back(0, 1);
            }
        } else {
            int elem;
            cin >> elem;
            bool flag = false;
            if (endings.lower_bound(elem) != endings.end())
                if (beginnings[*endings.lower_bound(elem)] <= elem) flag = true;
            if (flag) {
                ans.emplace_back(beginnings[*endings.lower_bound(elem)], *endings.lower_bound(elem));
                beginnings[*endings.lower_bound(elem)] = 0;
                endings.erase(endings.lower_bound(elem));
            } else {
                ans.emplace_back(0, 0);
            }
        }
    }
    for (auto & i : ans) {
        if (i.f == 0 && i.s == 0) cout << i.f << ' ' << i.s << endl;
        else if (i.f == 0 || (i.f == 1 && i.s == 0)) cout << i.f << endl;
        else cout << i.f << ' ' << i.s << endl;
    }


    return 0;

}
