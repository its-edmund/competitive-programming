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

ll fact(ll n) {
    if (n == 0) {
        return 1;
    }

    ll ans = 1;
    for (ll i = 2; i <= n; i++) {
        ans *= i;
        ans %= MOD;
    }
    return ans;
}

ll n_choose_k(ll n, ll k) {
    cout << "fact(" << n << "): " << fact(n) << "\n";
    cout << "fact(" << k << "): " << fact(k) << "\n";
    return fact(n) / (fact(k) * fact(n - k));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> cols;
    ll ans = 1;
    for (int t = 1; t <= m; t++) {
        int col;
        cin >> col;
        cols.push_back(col);
    }

    for (int col : cols) {
        cout << n_choose_k(col, n) << "\n";
        ans *= n_choose_k(col, n);
        ans %= MOD;
    }

    cout << ans << "\n";
}
