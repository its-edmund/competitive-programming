#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

unsigned long long find_mapping(unsigned long long source_val, std::vector<std::string> mapping, std::vector<std::set<int>> duplicates) {
  for (std::string map : mapping) {
    std::istringstream iss(map);
    unsigned long long destination, source, range;
    if (iss >> destination >> source >> range) {
      if (source_val >= source && source_val <= source + range - 1) {
        return destination + (source_val - source);
      }
    }
  }
  return source_val;
}

int main() {
  std::ifstream file;
  file.open("day5.txt");
  std::string input;
  unsigned long long ans = 18446744073709551;
  if (!file.is_open()) {
    std::cerr << "error" << std::endl;
    return 1;
  }

  std::vector<unsigned long long> seeds;
  std::getline(file, input);

  std::vector<std::vector<std::string>> maps(7);
  std::vector<std::set<int>> duplicates(7);

  std::istringstream iss(input.substr(input.find(':') + 1));

  unsigned long long counter = -1;

  unsigned long long seed;
  while (iss >> seed) {
    seeds.push_back(seed);
  }

  while (file) {
    std::getline(file, input);

    if (input.size() == 0) {
      counter++;
      continue;
    } else if (!isdigit(input[0])) {
      continue;
    } else {
      maps[counter].push_back(input);
    }
  }
  file.close();

  for (size_t i = 0; i < seeds.size(); i += 2) {
    std::cout << i << std::endl;
    for (unsigned long long s = seeds[i]; s < seeds[i] + seeds[i + 1]; s++) {
      unsigned long long curr = s;
      for (std::vector<std::string> map : maps) {
        curr = find_mapping(curr, map);
      }
      ans = std::min(curr, ans);
    }
  }

  std::cout << ans << std::endl;
}


