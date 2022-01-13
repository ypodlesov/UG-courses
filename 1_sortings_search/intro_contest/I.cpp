#include <bits/stdc++.h>

using namespace std;

vector<int> z_func(string s);

int main(void) {

    string s;
    cin >> s;
    vector<int> z = z_func(s);
    for (int i = 0; i < z.size(); ++i) cout << z[i] << ' ';
    cout << endl;

    return 0;
}



vector<int> z_func(string s) {
    vector<int> z(s.size());
    z[0] = s.size();
    for (int i = 1, l = 0, r = 0; i < z.size(); ++i) {
        z[i] = max(0, min(z[i - l], r - i));
        while (i + z[i] < z.size() && s[i + z[i]] == s[z[i]]) ++z[i];
        if (i + z[i] > r) {
            l = i;
            r = l + z[l];
        }
    }
    return z;
}
