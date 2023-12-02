#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
	int n, d;
	cin >> n;
	set<int> m;
	while (n--) {
		cin >> d;
		m.insert(d);
	}
	cout << m.size() << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
