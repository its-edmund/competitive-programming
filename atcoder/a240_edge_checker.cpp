#include <bits/stdc++.h>

# define ll long long
# define ld long double

int main() {
	int a,b;
	std::cin >> a >> b;
	if (abs(a - b) == 1 || abs(a - b) == 9) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	}
}
