#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    map<int, int> board;
    vector<int> board_order;

    while (n--) {
        int x;
        cin >> x;
        board[x]++;
        board_order.push_back(x);
    }

    int ans = 0;

    for (int i = 0; i < board_order.size(); i++) {
        int num = board_order[i];
        if (board[num] < 1) continue;
        board[num]--;
        if (board[k - num] > 0) {
            board[k - num]--;
            ans++;
        }
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