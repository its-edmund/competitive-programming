#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
	int a,b,c;
	cin >> a >> b >> c;
	if (c < a) {
		if ((a/c+1) * c <= b) {
			cout << (a/c+1)*c << endl;
		} else {
			cout << -1 << endl;
		}
	} else if (a==c) {
		if (c <= b) {
			cout << c << endl;
		} else {
			cout << -1 << endl;
		}
	} else {
		if (c < b) {
			cout << c << endl;
		} else {
			cout << -1 << endl;
		}
	}
}
