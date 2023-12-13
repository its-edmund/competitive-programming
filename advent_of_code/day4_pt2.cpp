#include <bits/stdc++.h>
#include <fstream>

int count_matching(std::string line) {
    std::string allNumbers = line.substr(line.find(':') + 1);
    std::string winning = allNumbers.substr(0, allNumbers.find('|'));
    std::string my_numbers = allNumbers.substr(allNumbers.find('|') + 1);
    std::istringstream iss(winning);
    std::set<std::string> winning_nums;
    int count = 0;
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
        count++;
      }
    }
    return count;
}

int main() {
  std::ifstream file;
  file.open("day4.txt");
  std::string input;
  std::map<int, int> freq;
  int ans = 0;
  int line = 1;
  if (!file.is_open()) {
    std::cerr << "error" << std::endl;
    return 1;
  }
  while (file) {
    std::getline(file, input);
    if (input.size() == 0) {
      break;
    }
    int num_matching = count_matching(input);
    freq[line] += 1;
    for (int i = 1; i <= num_matching; i++) {
      freq[line + i] += freq[line];
    }
    ans += freq[line];
    line++;
  }
  file.close();
  std::cout << ans << std::endl;
}

