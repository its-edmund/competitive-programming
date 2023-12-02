#include <bits/stdc++.h>
#include <climits>
#include <vector>

int main() {
  std::ifstream file;
  file.open("input.txt");
  std::string input;
  std::vector<std::string> numbers = {"one", "two",   "three", "four", "five",
                                      "six", "seven", "eight", "nine"};
  int ans = 0;
  if (!file.is_open()) {
    std::cerr << "error" << std::endl;
    return 1;
  }
  while (file) {
    std::getline(file, input);
    size_t earliest = INT_MAX;
    int number = 0;
    int next_number = 0;

    if (input.size() == 0) {
      break;
    }

    for (std::string s : numbers) {
      size_t found = input.find(s);
      if (found != std::string::npos && found < earliest) {
        earliest = found;
        auto it = find(numbers.begin(), numbers.end(), s);
        number = it - numbers.begin() + 1;
      }
    }

    for (size_t i = 0; i < input.size(); i++) {
      if (i >= earliest) {
        break;
      }
      if (isdigit(input.at(i))) {
        number = (input.at(i) - '0');
        break;
      }
    }

    next_number = 10 * number;

    int latest = -1;

    for (std::string s : numbers) {
      int found = input.rfind(s);
      if (found != std::string::npos && found > latest) {
        latest = found;
        auto it = find(numbers.begin(), numbers.end(), s);
        number = it - numbers.begin() + 1;
      }
    }

    for (int i = input.size() - 1; i >= 0; i--) {
      if (i < latest) {
        break;
      }
      if (isdigit(input.at(i))) {
        number = (input.at(i) - '0');
        break;
      }
    }

    next_number += number;

    ans += next_number;
  }
  file.close();
  std::cout << ans << std::endl;
}
