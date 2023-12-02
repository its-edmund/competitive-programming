#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream file;
  file.open("day1.txt");
  std::string input;
  int ans = 0;
  if (!file.is_open()) {
    std::cerr << "error" << std::endl;
    return 1;
  }
  while (file) {
    std::getline(file, input);
    std::string num = "";
    for (size_t i = 0; i < input.size(); i++) {
      if (isdigit(input.at(i))) {
        num += input.at(i);
        break;
      }
    }

    for (int i = input.size() - 1; i >= 0; i--) {
      if (isdigit(input.at(i))) {
        num += input.at(i);
        break;
      }
    }

    ans += atoi(num.c_str());
  }
  file.close();
  std::cout << ans << std::endl;
}
