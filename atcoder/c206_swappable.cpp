#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int n;
	int total = 0;
	cin >> n;
	map<int, int> m;
	while (n--) {
		int a;
		cin >> a;
		m[a]++;
		total++;
	}

	int ans = 0;

	for (auto i : m) {
		ans += total - i.second;
	}

	cout << ans;
}
