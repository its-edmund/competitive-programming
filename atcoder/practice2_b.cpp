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

void solve() {}

void print_tree() {
    for (ll i : tree) {
        cout << i << " ";
    }
    cout << "\n";
}

ll lsb(ll i) { 
    return i & -i; 
}

void insert(ll index, ll value) {
    ll sum = 0;
    ll i = index + 1;
    while (i) {
        sum += tree[i];
        i = i - lsb(i);
    }
    tree[index + 1] = sum + value;
}

void update(ll index, ll d) {
    index++;
    while (index < sza(tree)) {
        tree[index] += d;
        index = index + lsb(index);
    }
}

ll query(ll index) {
    ll sum = 0;
    index++;
    while (index) {
        sum += tree[index];
        index = index - lsb(index);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    tree.resize(n + 1, 0);
    for (ll t = 0; t < n; t++) {
        ll element;
        cin >> element;
        update(t, element);
    }

    for (ll i = 0; i < q; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            cout << query(c - 1) - query(b - 1) << "\n";
        } else {
            update(b, c);
        }
    }
}
