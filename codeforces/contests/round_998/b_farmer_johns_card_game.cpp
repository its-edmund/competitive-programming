#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int order[n];
    bool failed = false;
    for (int i = 0; i < n; i++) {
        int hand[m];
        for (int j = 0; j < m; j++) {
            int card;
            cin >> card;
            hand[j] = card;
        }
        if (failed) continue;
        sort(hand, hand + (sizeof(hand) / sizeof(hand[0])));

        for (int j = 1; j < m; j++) {
            if (hand[j] - hand[j - 1] != n) {
                failed = true;
            }
        }
        order[hand[0]] = i + 1;
    }

    if (failed) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << order[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}