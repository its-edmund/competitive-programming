#include <bits/stdc++.h>
#include <fstream>
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
    std::cout << input << std::endl;
  }
  file.close();
  std::cout << ans << std::endl;
}
