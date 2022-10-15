#include <bits/stdc++.h>

using namespace std;

void solve() 
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2) {
        cout << "=\n";
    } else if (s1.back() == 'L' && (s2.back() == 'M' || s2.back() == 'S')) {
        cout << ">\n";
    } else if (s1.back() == 'M' && s2.back() == 'L') {
        cout << "<\n";
    } else if (s1.back() == 'S' && (s2.back() == 'M' || s2.back() == 'L')) {
        cout << "<\n";
    } else if (s1.back() == 'M' && s2.back() == 'S') {
        cout << ">\n";
    } else if (s2.back() == 'L' && (s1.back() == 'M' || s1.back() == 'S')) {
        cout << "<\n";
    } else if (s2.back() == 'M' && s1.back() == 'L') {
        cout << ">\n";
    } else if (s2.back() == 'S' && (s1.back() == 'M' || s1.back() == 'L')) {
        cout << ">\n";
    } else if (s2.back() == 'M' && s1.back() == 'S') {
        cout << "<\n";
    } else {
        if (s1.back() == 'S') {
            if (s1.size() > s2.size()) {
                cout << "<\n";
            } else {
                cout << ">\n";
            }
        } else {
            if (s1.size() > s2.size()) {
                cout << ">\n";
            } else {
                cout << "<\n";
            }
        }
    }

}

int
main() 
{

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
