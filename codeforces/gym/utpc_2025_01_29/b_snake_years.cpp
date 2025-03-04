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
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string num;
    while(n--) {
        char c;
        cin >> c;
        num += c;
    }

    ll ans = 0;

    std::sort(num.begin(), num.end());

    do {
        if (num[0] == '0') {
            continue;
        }
        int num_val = std::stoi(num);
        if (num_val % 12 == 9) ans++;
    } while (std::next_permutation(num.begin(), num.end()));

    cout << ans << "\n";
}
