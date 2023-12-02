#include <bits/stdc++.H>

using namespace std;

void solve() {
	int x, y, k;
	cin >> x >> y >> k;
	if (y <= x) {
		cout << x << endl;
	} else {
		if (y - x <= k) {
			cout << y << endl;;
		} else {
			cout << y + (y - (x + k)) << endl;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
