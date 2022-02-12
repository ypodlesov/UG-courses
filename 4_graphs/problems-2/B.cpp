#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

void bfs(int x, int y, vector<vector<bool>> &used, vector<vector<int>> &d) {
    queue<pair<int,int>> q;
    q.push({x,y});
    used[x][y] = true;
    while (!q.empty()) {
        pair<int,int> v = q.front();
        q.pop();
        pair<int,int> to;

        to.f =  v.f + 2; // 1
        to.s =  v.s + 1;
        if (to.f <= 8 && to.f >= 1 && to.s <= 8 && to.s >= 1) {
            if (!used[to.f][to.s]) {
                used[to.f][to.s] = true;
                q.push(to);
                d[to.f][to.s] = d[v.f][v.s] + 1;
            }
        }

        to.f =  v.f + 2; // 2
        to.s =  v.s - 1;
        if (to.f <= 8 && to.f >= 1 && to.s <= 8 && to.s >= 1) {
            if (!used[to.f][to.s]) {
                used[to.f][to.s] = true;
                q.push(to);
                d[to.f][to.s] = d[v.f][v.s] + 1;
            }
        }

        to.f =  v.f + 1; // 3
        to.s =  v.s + 2;
        if (to.f <= 8 && to.f >= 1 && to.s <= 8 && to.s >= 1) {
            if (!used[to.f][to.s]) {
                used[to.f][to.s] = true;
                q.push(to);
                d[to.f][to.s] = d[v.f][v.s] + 1;
            }
        }

        to.f =  v.f + 1; // 4
        to.s =  v.s - 2;
        if (to.f <= 8 && to.f >= 1 && to.s <= 8 && to.s >= 1) {
            if (!used[to.f][to.s]) {
                used[to.f][to.s] = true;
                q.push(to);
                d[to.f][to.s] = d[v.f][v.s] + 1;
            }
        }

        to.f =  v.f - 2; // 5
        to.s =  v.s + 1;
        if (to.f <= 8 && to.f >= 1 && to.s <= 8 && to.s >= 1) {
            if (!used[to.f][to.s]) {
                used[to.f][to.s] = true;
                q.push(to);
                d[to.f][to.s] = d[v.f][v.s] + 1;
            }
        }

        to.f =  v.f - 2; // 6
        to.s =  v.s - 1;
        if (to.f <= 8 && to.f >= 1 && to.s <= 8 && to.s >= 1) {
            if (!used[to.f][to.s]) {
                used[to.f][to.s] = true;
                q.push(to);
                d[to.f][to.s] = d[v.f][v.s] + 1;
            }
        }

        to.f =  v.f - 1; // 7
        to.s =  v.s + 2;
        if (to.f <= 8 && to.f >= 1 && to.s <= 8 && to.s >= 1) {
            if (!used[to.f][to.s]) {
                used[to.f][to.s] = true;
                q.push(to);
                d[to.f][to.s] = d[v.f][v.s] + 1;
            }
        }

        to.f =  v.f - 1; // 8
        to.s =  v.s - 2;
        if (to.f <= 8 && to.f >= 1 && to.s <= 8 && to.s >= 1) {
            if (!used[to.f][to.s]) {
                used[to.f][to.s] = true;
                q.push(to);
                d[to.f][to.s] = d[v.f][v.s] + 1;
            }
        }

    }
}


int main() {

    char ch1, ch2;
    int posy1, posy2;
    int posx1, posx2;
    cin >> ch1 >> posy1 >> ch2 >> posy2;
    posx1 = ch1 - 'a';
    posx2 = ch2 - 'a';
    vector<vector<bool>> used1(10, vector<bool>(10, false)), used2(10, vector<bool>(10, false));
    vector<vector<int>> d1(10, vector<int>(10, 0)), d2(10, vector<int>(10, 0));
    bfs(posx1, posy1, used1, d1), bfs(posx2, posy2, used2, d2);
    int ans = INT_MAX;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            if (d1[i][j] == d2[i][j]) ans = min(ans, d1[i][j]);

    (ans != INT_MAX) ? cout << ans << endl : cout << -1 << endl;

    return 0;
}
