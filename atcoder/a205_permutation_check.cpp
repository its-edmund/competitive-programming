#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;
	unordered_set<int> h;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if(h.find(a)!=h.end() || a > n) {
			cout << "No" << endl;
			return 0;
		}
		h.insert(a);
	}
	cout << "Yes" << endl;
}
