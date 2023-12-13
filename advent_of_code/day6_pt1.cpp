#include <bits/stdc++.h>
#include <fstream>

#define ull unsigned long long

int main() {
  std::ifstream file;
  file.open("day6.txt");
  std::vector<ull> times;
  std::vector<ull> distances;
  if (!file.is_open()) {
    std::cerr << "error" << std::endl;
    return 1;
  }

  std::string line;
  ull value;
  ull ans = 1;

  // Parse times
  getline(file, line);
  std::istringstream iss(line);
  iss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');

  while (iss >> value) {
    times.push_back(value);
  }

  // Parse distances
  getline(file, line);
  iss.str(line);
  iss.clear();
  iss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
  value = 0;

  while (iss >> value) {
    distances.push_back(value);
  }

  for (ull i = 0; i < times.size(); i++) {
    ull count = 0;
    for (ull j = 0; j < times[i]; j++) {
      if ((times[i] - j) * j > distances[i]) {
        count++;
      }
    }
    ans *= count;
  }

  file.close();
  std::cout << ans << std::endl;
}
