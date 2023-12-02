#include <fstream>
#include <iostream>

int main() {
  std::ifstream file;
  file.open("day1.txt");
  std::string input;
  int ans = 0;
  if (!file.is_open()) {
    std::cerr << "error" << std::endl;
    return 1;
  }
}
