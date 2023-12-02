#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	unordered_map<char, int> f;
	string word;
	cin >> word;
	for (auto c : word) {
		f[c]++;
	}
	int extra = 0;
	for (const auto& t : f) {
		extra += t.second % 2;
	}
	if (extra - 1 == k || extra == k || ((k - extra - 1) % 2 == 0) || (k - extra) % 2 == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
