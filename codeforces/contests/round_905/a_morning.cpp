#include <bits/stdc++.h>

using namespace std;

void solve() {
	string a;
	cin >> a;
	int ans = 4;
	int prev = 1;
	for (size_t i = 0; i < 4; i++) {
		int num = a[i] - '0';
		if (a[i] == '0') {
			num = 10;
		}
		ans += abs(num - prev);
		prev = num;
	}
	cout << ans << endl;

}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
