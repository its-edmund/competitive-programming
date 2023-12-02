#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
	int n, x;
	int ans = 0;
	cin >> n >> x;
	int min, max;
	for (int i=0; i<n; i++) {
		int a;
		cin >> a;
		if (i == 0) {
			min = a;
			max = a;
		} else {
			if (a <= max && a >= min) {
				continue;
			} else if (a > max) {
				if(a-min > x * 2) {
					ans++;
					min = a;
					max = a;
				} else {
					max = a;
				}
			} else if (a < min) {
				if (max - a > x * 2) {
					ans++;
					min = a;
					max = a;
				} else {
					min = a;
				}
			}
		}
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;

	while(t--){
		solve();
	}
}
