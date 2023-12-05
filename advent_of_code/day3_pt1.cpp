#include <bits/stdc++.h>
#include <cstdlib>
#include <fstream>

bool is_symbol(char c) { return !isdigit(c) && c != '.'; }

int main() {
  std::ifstream file;
  file.open("day3.txt");
  std::string input;
  std::vector<std::string> schematic;
  int ans = 0;
  if (!file.is_open()) {
    std::cerr << "error" << std::endl;
    return 1;
  }
  while (file) {
    std::getline(file, input);
    if (input.size()) {
      schematic.push_back(input);
    }
  }
  for (size_t i = 0; i < schematic.size(); i++) {
    for (size_t j = 0; j < schematic[0].size(); j++) {
      bool is_part = false;
      int num = 0;
      if (isdigit(schematic[i][j])) {
        if (j > 0) {
          if ((i > 0 && is_symbol(schematic[i - 1][j - 1])) ||
              is_symbol(schematic[i][j - 1]) ||
              (i < schematic[0].size() - 1 &&
               is_symbol(schematic[i + 1][j - 1]))) {
            is_part = true;
          }
        }
        while (isdigit(schematic[i][j])) {
          num = num * 10 + (schematic[i][j] - '0');
          if ((i > 0 && is_symbol(schematic[i - 1][j])) ||
              (i < schematic.size() - 1 && is_symbol(schematic[i + 1][j]))) {
            is_part = true;
          }
          j++;
        }
        if (j < schematic[0].size()) {
          if ((i > 0 && is_symbol(schematic[i - 1][j])) ||
              is_symbol(schematic[i][j]) ||
              (i < schematic[0].size() - 1 && is_symbol(schematic[i + 1][j]))) {
            is_part = true;
          }
        }
        if (is_part) {
          ans += num;
        }
      }
    }
  }
  file.close();
  std::cout << ans << std::endl;
}
