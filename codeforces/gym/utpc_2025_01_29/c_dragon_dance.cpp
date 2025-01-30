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
    int n, k;
    cin >> n >> k;
    int ans = 1;

    int curr_streak = 1;
    int prev_height;

    cin >> prev_height;
    for (int t = 1; t < n; t++) {
        int curr_height;
        cin >> curr_height;
        if (std::abs(prev_height - curr_height) > k) {
            ans = max(curr_streak, ans);
            curr_streak = 1;
        } else {
            curr_streak++;
        }
        prev_height = curr_height;
    }

    ans = max(curr_streak, ans);

    cout << ans << "\n";
}
