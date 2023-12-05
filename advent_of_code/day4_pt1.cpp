#include <bits/stdc++.h>
#include <fstream>
int main() {
  std::ifstream file;
  file.open("day4.txt");
  std::string input;
  int ans = 0;
  if (!file.is_open()) {
    std::cerr << "error" << std::endl;
    return 1;
  }
  while (file) {
    std::getline(file, input);
    std::string allNumbers = input.substr(input.find(':') + 1);
    std::string winning = allNumbers.substr(0, allNumbers.find('|'));
    std::string my_numbers = allNumbers.substr(allNumbers.find('|') + 1);
    std::istringstream iss(winning);
    std::set<std::string> winning_nums;
    int score = 1;
    while (iss) {
      std::string num;
      iss >> num;
      if (num.size() != 0) {
        winning_nums.insert(num);
      }
    }
    std::istringstream my_iss(my_numbers);
    while (my_iss) {
      std::string num;
      my_iss >> num;
      if (winning_nums.find(num) != winning_nums.end()) {
        score *= 2;
      }
    }
    ans += score / 2;
  }
  file.close();
  std::cout << ans << std::endl;
}
