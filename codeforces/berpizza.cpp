#include <bits/stdc++.h>

using namespace std;

int count;

void solve() {
	int q;
	cin >> q;
	priority_queue<pair<int, int>> id;
	priority_queue<pair<int, int>> price;
	if(q==1){
		int m;
		cin >> m;
		id.push({count, m})
		price.push({m, count})
		count++;
	}
}

int main() {
	int t;
	cin >> t;
	count = 0;
	while(t--) {
		solve();
	}
}
