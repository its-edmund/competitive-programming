#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;

    int ans = 0;

    for (int a3 = -100; a3 <= 100; a3++) {
        int f = 0;
        if (a3 == a2 + a1) f++;
        if (a4 == a3 + a2) f++;
        if (a5 == a4 + a3) f++;

        ans = max(f, ans);
        if (ans == 3) break;
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}