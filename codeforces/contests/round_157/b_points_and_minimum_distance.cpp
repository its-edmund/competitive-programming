#include <bits/stdc++.h>

using namespace std;

int manhattan(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
	int n;
	cin >> n;
	vector<int> p;
	while (n--) {
		int x;
		cin >> x;
		p.push_back(x);
	}

	sort(p.begin(), p.end());

	int ans = 0;
	int prev = p[0];

	for (size_t i = 1; i < points.size(); i++) {
		ans += manhattan(points[i], prev);
		prev = points[i];
	}

	cout << ans << endl;
	for (auto point : points) {
		cout << point.first << " " << point.second << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
