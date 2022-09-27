#include <bits/stdc++.h>

using namespace std;

int main() {

    stack<int> a;
    string s;
    while (1) {
        cin >> s;
        if (s == "push") {
            int key;
            cin >> key;
            a.push(key);
            cout << "ok" << endl;
        } else if (s == "size") {
            cout << a.size() << endl;
        } else if (s == "clear") {
            while (!a.empty()) a.pop();
            cout << "ok" << endl;
        } else if (s == "pop") {
            cout << a.top() << endl;
            a.pop();
        } else if (s == "back") {
            cout << a.top() << endl;
        } else if (s == "exit") {
            cout << "bye" << endl;
            break;
        }
    }

    return 0;
}
