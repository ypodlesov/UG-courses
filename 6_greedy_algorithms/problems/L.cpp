#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define PF push_front
#define ff first
#define ss second

struct event {
    int type, time, id;
};

int n;
ll ans;
vector<event> events;
vector<int> c, p;
vector<ll> res;
deque<int> way;

bool cmp(event &a, event &b) {
    return (a.time < b.time) || (a.time == b.time && a.type == false && b.type == true);
}

int main() {

    cin >> n;
    c.assign(n, 0), res.assign(n, 0), p.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        int s, t;
        cin >> s >> t >> c[i];
        events.PB({1, s, i});
        events.PB({0, s+t, i});
    }
    sort(events.begin(), events.end(), cmp);
    int last = -1;
    for (int i = 0; i < 2 * n; ++i) {
        int idx = events[i].id;
        if (events[i].type) {
            res[idx] = ans;
            p[idx] = last;
        } else {
            if (res[idx] + c[idx] > ans) {
                ans = res[idx] + c[idx];
                last = idx;
            }
        }
    }
    while (last != -1) way.PF(last+1), last = p[last];
    cout << ans << endl << way.size() << endl;
    for (auto i : way) cout << i << ' ';
    cout << endl;

    return 0;
}
