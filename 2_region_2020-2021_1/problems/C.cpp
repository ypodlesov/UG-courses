#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define l blocks[i].f
#define a blocks[i-1].f
#define b blocks[i+1].f
#define X blocks[i-1].s
#define Y blocks[i+1].s


string str;
vector<pair<int,char>> blocks;

int digits(int n) {
    int res = 0;
    while(n) ++res, n /= 10;
    return res;
}

bool ten_pow(int n) {
    if (n < 10) return false;
    while(n / 10) {
        if (n % 10) return false;
        n /= 10;
    }
    if (n == 1) return true;
    return false;
}

int pow_num(int n) {
    int res = 0;
    while (n / 10) n /= 10, ++res;
    return res;
}

int binpow (int num, int n) {
	int res = 1;
	while (n) {
		if (n & 1) res *= num, --n;
		else num *= num, n >>= 1;
    }
	return res;
}

char choose_char(char ch) {
    if (ch == 'A') return 'G';
    if (ch == 'G') return 'C';
    if (ch == 'C') return 'T';
    return 'A';
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cur = 0;
    char ch;
    while (cin >> ch) {
        if (ch - '0' > 11) {
            blocks.emplace_back(max(1, cur), ch);
            cur = 0;
        } else cur = cur * 10 + ch - '0';
    }

    // minimize (deleting):
    int ans = 0, m = 0;
    cur = 0;
    for (int i = 0; i < blocks.size(); ++i) {
        if (l == 1) {
            if (i == 0 || i == blocks.size() - 1 || X != Y) {
                if (!m) m = 1, ans = cur + 1;
            } else if (i > 0 && i < blocks.size() - 1 && X == Y) {
                int res = digits(a) + digits(b) - digits(a + b);
                if (m < res + 2) m = res + 2, ans = cur + 1;
            }
        } else if (l == 2) {
            if (!m) m = 1, ans = cur + 1;
        } else if (l > 2) {
            if (ten_pow(l)) {
                if (!m) m = 1, ans = cur + 1;
            }
        }
        cur += l;
    }
    cout << 2 << ' ' << max(ans, 1) << endl;

    // maximize (insertion):
    ans = 0, m = 0, cur = 0;
    char ans_ch;
    for (int i = 0; i < blocks.size(); ++i) {
        int t = pow_num(l);
        if (l == 1) {
            if (!m) {
                m = 1;
                ans_ch = choose_char(blocks[i].s);
                ans = cur + 1;
            }
        } else if (l == 2) {
            if (!m) {
                m = 1;
                ans_ch = choose_char(blocks[i].s);
                ans = cur + 1;
            }
        } else if (l == 3) {
            if (m < 2) {
                m = 2;
                ans_ch = choose_char(blocks[i].s);
                ans = cur + 1;
            }
        } else if (l >= 4 && l < 10) {
            if (m < 3) {
                m = 3;
                ans_ch = choose_char(blocks[i].s);
                ans = cur + 2;
            }
        } else if (t) { // need to know t
            int var = binpow(10, t);
            // cout << t << ' ' << var << endl;
            if (l >= var * 2  && l < var * 10) {
                if (m < t + 3) {
                    m = t + 3;
                    ans_ch = choose_char(blocks[i].s);
                    ans = cur + var;
                }
            } else if (l >= var + var/10 && l < 2 * var) {
                if (m < t + 2) {
                    m = t + 2;
                    ans_ch = choose_char(blocks[i].s);
                    ans = cur + var/10;
                }
            } else if (l >= var && l < var + var/10) {
                if (m < t + 1) {
                    m = t + 1;
                    ans_ch = choose_char(blocks[i].s);
                    ans = cur + var/10 + 1;
                }
            }
        }
        cur += l;
    }
    cout << 1 << ' ' << ans << ' ' << ans_ch << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
