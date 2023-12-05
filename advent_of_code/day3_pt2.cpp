#include <bits/stdc++.h>
#include <cstdlib>
#include <fstream>

using namespace std;

int get_number(std::vector<std::string> schematic, int i, int j) {
  std::string number(1, schematic[i][j]);
  int temp = j - 1;
  while (temp > -1 && isdigit(schematic[i][temp])) {
    number = schematic[i][temp] + number;
    temp--;
  }
  temp = j + 1;
  while (temp < schematic[i].size() && isdigit(schematic[i][temp])) {
    number += schematic[i][temp];
    temp++;
  }
  return stoi(number);
}

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
      if (schematic[i][j] == '*') {
        int adj = 0;
        int num = 1;
        if (i > 0 && isdigit(schematic[i - 1][j])) {
          adj++;
          num *= get_number(schematic, i - 1, j);
        } else {
          if (i > 0 && j > 0 && isdigit(schematic[i - 1][j - 1])) {
            adj++;
            num *= get_number(schematic, i - 1, j - 1);
          }
          if (i > 0 && j < schematic[i].size() && isdigit(schematic[i - 1][j + 1])) {
            adj++;
            num *= get_number(schematic, i - 1, j + 1);
          }
        }
        if (i < schematic.size() - 1 && isdigit(schematic[i + 1][j])) {
          adj++;
          num *= get_number(schematic, i + 1, j);
        } else {
          if (i < schematic.size() - 1 && j > 0 && isdigit(schematic[i + 1][j - 1])) {
            adj++;
            num *= get_number(schematic, i + 1, j - 1);
          }
          if (i < schematic.size() - 1 && j < schematic[i].size() && isdigit(schematic[i + 1][j + 1])) {
            adj++;
            num *= get_number(schematic, i + 1, j + 1);
          }
        }
        if (j > 0 && isdigit(schematic[i][j - 1])) {
          adj++;
          num *= get_number(schematic, i, j - 1);
        }
        if (j < schematic[i].size() - 1 && isdigit(schematic[i][j + 1])) {
          adj++;
          num *= get_number(schematic, i, j + 1);
        }
        if (adj == 2) {
          ans += num;
        }
      }
    }
  }
  file.close();
  std::cout << ans << std::endl;
}
