#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

vector<ll> tree;
int n;

void solve() {
    
}

void debug() {
	for (ll i : tree) {
		cout << i << " ";
	}
	cout << "\n";
}

void build() {
	for (int i = 0; i < n; i++) {
		int element;
		cin >> element;
		tree[n + i] = element;
	}

	for (int i = n - 1; i > 0; i--) {
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
}

void update(int i, int val) {
	tree[n + i] = val;

	int temp = (n + i) / 2;
	while (temp > 0) {
		tree[temp] = tree[temp * 2] + tree[temp * 2 + 1];
		temp /= 2;
	}
}

ll query(int l, int r) {
	ll ans = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			ans += tree[l];
			l++;
		}
		if (r & 1) {
			r--;
			ans += tree[r];
		}
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int m;
    cin >> n >> m;
    tree.resize(2 * n, 0);
	build();
	while (m--) {
		int o, i, v;
		cin >> o >> i >> v;
		if (o == 1) {
			update(i, v);
		} else {
			cout << query(i, v) << "\n";
		}
	}
}
