#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back

ll n, sum;
vector<int> w(65);
set<int> unused;

vector<int> form_heap(vector<vector<int>> &dp) {
    vector<int> heap;
    int t_sum = sum / 3, t_n = n;
    while (t_n) {
        if (t_sum >= w[t_n] && dp[t_n-1][t_sum-w[t_n]] && unused.find(t_n) != unused.end()) {
            heap.PB(t_n);
            t_sum -= w[t_n];
            unused.erase(unused.find(t_n));
            --t_n;
        } else --t_n;
    }
    return heap;
}

vector<int> keep_dp() {
    vector<vector<int>> dp(n+1, vector<int>(sum+1));
    for (int i = 0; i <= n; ++i) dp[i][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j >= w[i] && unused.find(i) != unused.end()) dp[i][j] |= dp[i-1][j-w[i]];
        }
    }
    return form_heap(dp);
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        sum += w[i];
        unused.insert(i);
    }
    if (sum % 3) {
        cout << "No solution\n";
        return 0;
    }
    vector<vector<int>> answers;
    for (int i = 0; i < 3; ++i) {
        answers.PB(keep_dp());
        if (answers.back().size() == 0) {
            cout << "No solution\n";
            return 0;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < answers[i].size(); ++j) cout << answers[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
