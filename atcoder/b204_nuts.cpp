#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main () {
	int n;
	cin >> n;
	int a;
	int ans = 0;
	while(n--) {
		cin >> a;
		if (a > 10) {
			ans += a - 10;
		}
	}
	cout << ans;
}
