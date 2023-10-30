#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool vis[7][7];

void backtrack(string path, pair<int, int> curr, stack<pair<int, int> visited, int& count) {
	if (visited.size() == 47 && curr.first == 6 && curr.second == 6) {
		++count;
		return;
	}
	if (path[0] == '?') {
		for (int i = 0; i < 
	}
}

int main() {
  string n;
  cin >> n;
}
