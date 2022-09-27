#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000
#define PB push_back
#define f first
#define s second

vector<pair<char,double>> nums;

int main() {

    FILE *in;
    in = fopen("input.txt", "r");
    char oper = 'b', ch;
    double num = 0;
    int mode = 0;
    while (fscanf(in, "%c", &ch) > 0) {
        if (!((ch - '0' >= 0 && ch - '0' < 10) || ch == '.' || ch == '+' || ch == '-' || ch == '*')) continue;
        if (ch - '0' >= 0 && ch - '0' < 10) {
            double tmp = (double)(ch - '0');
            if (!mode) num = num * 10 + tmp;
            else num += tmp * pow(10, mode), --mode;
        } else if (ch == '.') mode = -1;
        else {
            nums.PB({oper, num});
            num = 0, mode = 0;
            if (ch == '+') oper = '+';
            else if (ch == '-') oper = '-';
            else if (ch == '*') oper = '*';
        }
    }
    nums.PB({oper, num});
    vector<vector<string>> dp(nums.size() + 1);



    // for (int i = 0; i < nums.size(); ++i) cout << nums[i].f << ": " << nums[i].s << endl;

    fclose(in);

    return 0;
}
