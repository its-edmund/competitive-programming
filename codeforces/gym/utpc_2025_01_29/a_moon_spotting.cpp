#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    string s;
    string output;
    cin >> s;
    if (s == "0") {
        output = "New moon";
    } else if (s == "100") {
        output = "Full moon";
    } else {
        int percent = std::stoi(s.substr(0, s.length() - 1));
        if (s[s.length() - 1] == 'R') {
            if (percent == 50) {
                output = "First quarter";
            } else if (percent > 50) {
                output = "Waxing gibbous";
            } else {
                output = "Waxing crescent";
            }
        } else {
            if (percent == 50) {
                output = "Third quarter";
            } else if (percent > 50) {
                output = "Waning gibbous";
            } else {
                output = "Waning crescent";
            }
        }
    }
    cout << output << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}
