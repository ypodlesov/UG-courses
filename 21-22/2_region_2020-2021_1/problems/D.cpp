#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define mod 100003
#define PB push_back
#define f first
#define s second

bool flag;
int n, m, slen, last_d = -1;
int l_dist[2] = {-10, -10}, r_dist[2] = {INF+5, INF+5};
set<int> d_potential;
vector<set<int>> ans(mod);

int hsh(ll a, ll b) {
    return (abs(a + 7) * 103 + abs(b + 11) * 97) % mod;
}

int main() {

    scanf("%d", &n);
    vector<vector<int>> for_check(n);
    vector<int> len(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &m, &len[i]);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &slen);
            for_check[i].PB(slen);
        }
        int tmp_l = *for_check[i].begin(), tmp_r = len[i] - for_check[i].back();

        if (l_dist[0] < tmp_l) l_dist[1] = l_dist[0], l_dist[0] = tmp_l;
        else if (l_dist[1] < tmp_l) l_dist[1] = tmp_l;
        if (r_dist[0] > tmp_r) r_dist[1] = r_dist[0], r_dist[0] = tmp_r;
        else if (r_dist[1] > tmp_r) r_dist[1] = tmp_r;

        ans[hsh((ll)tmp_l, (ll)tmp_r)].insert(i+1);
    }
    for (auto i : for_check) {
        for (int j = 1; j < i.size(); ++j) {
            if (last_d == -1) last_d = i[j] - i[j-1];
            else if (last_d != i[j] - i[j-1]) {
                printf("No\n");
                return 0;
            }
        }
    }
    if (last_d != -1) d_potential.insert(last_d);
    if (d_potential.size() == 0) {
        for (int i = 0; i <= min(1, (int)for_check.size() - 1); ++i)
            for (int j = 0; j <= min(1, (int)for_check.size() - 1); ++j)
                if (l_dist[i] != -10 && r_dist[j] != INF+5) d_potential.insert(l_dist[i] + r_dist[j]);
    }
    for (auto d : d_potential) {
        if (flag) break;
        int start = -10, cnt = 0, spec_cnt = 0;
        unordered_map<int,pair<int,int>> deg;
        unordered_map<int,multiset<int>> g;

        for (int i = 0; i < n; ++i) {
            int tmp_l = max(-1, d - *for_check[i].begin());
            int tmp_r = (len[i] - for_check[i].back() > d) ? -2 : len[i] - for_check[i].back();
            g[tmp_l].insert(tmp_r);
            ++deg[tmp_r].f, ++deg[tmp_l].s;
        }

        for (auto i : deg) {
            if (abs(i.s.f - i.s.s) > 1) ++cnt;
            if (i.s.f != i.s.s) ++spec_cnt;
        }
        if (cnt || spec_cnt > 2) continue;
        start = d - l_dist[0];
        for (auto i : deg) {
            if (i.s.s == i.s.f + 1) {
                start = i.f;
                break;
            }
        }
        // Euler cycle ladies & gentlemen:
        stack<int> vs;
        vector<int> euler_path;
        vs.push(start);
        while (!vs.empty()) {
            int v = vs.top();
            if (deg[v].s == 0) {
                euler_path.PB(v);
                vs.pop();
            } else {
                int u = *g[v].begin();
                vs.push(u);
                --deg[v].s, --deg[u].f;
                g[v].erase(g[v].begin());
            }
        }
        // reverse(euler_path.begin(), euler_path.end());
        if (euler_path.size() == n+1) {
            printf("Yes\n");
            flag = true;
        } else continue;
        for (int i = euler_path.size() - 1; i > 0; --i) {
            int h = hsh((ll)(d - euler_path[i]), (ll)(euler_path[i-1]));
            if (euler_path[i] == -1) {
                for (int j = 0; j < n; ++j)
                    if (*for_check[j].begin() > d) printf("%d ", j+1);
                continue;
            }
            if (euler_path[i-1] == -2) {
                for (int j = 0; j < n; ++j)
                    if (len[j] - for_check[j].back() > d) printf("%d ", j+1);
                continue;
            }
            for (auto j : ans[h]) {
                if (euler_path[i] == d - *for_check[j-1].begin() && euler_path[i-1] == len[j-1] - for_check[j-1].back()) {
                    cout << j << ' ';
                    ans[h].erase(j);
                    break;
                }
            }
        }
        printf("\n");
    }
    if (!flag) printf("No\n");

    return 0;
}
