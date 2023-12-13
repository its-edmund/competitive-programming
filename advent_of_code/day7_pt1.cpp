#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#define ull unsigned long long

enum Hands {
  HIGH_CARD,
  ONE_PAIR,
  TWO_PAIR,
  THREE_OF_A_KIND,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  FIVE_OF_A_KIND
};

bool card_comparator(char a, char b) {
  std::string cards = "23456789TJQKA";
  return cards.find(a) > cards.find(b);
}

Hands parse_hand(std::string hand) {
  std::map<char, int> freq;
  for (char card : hand) {
    freq[card]++;
  }

  std::map<std::string, int>::iterator it;
  std::vector<std::pair<int, char>> sorted_freq;

  for (auto const& [key, value] : freq) {
    sorted_freq.push_back({value, key});
  }

  std::sort(sorted_freq.begin(), sorted_freq.end(), [](std::pair<int, char> a, std::pair<int, char> b) { return a.first > b.first; });

  if (sorted_freq[0].first == 5) {
    return FIVE_OF_A_KIND;
  } else if (sorted_freq[0].first == 4) {
    return FOUR_OF_A_KIND;
  } else if (sorted_freq[0].first == 3) {
    if (sorted_freq[1].first == 2) {
      return FULL_HOUSE;
    } else {
      return THREE_OF_A_KIND;
    }
  } else if (sorted_freq[0].first == 2) {
    if (sorted_freq[1].first == 2) {
      return TWO_PAIR;
    } else {
      return ONE_PAIR;
    }
  } else {
    return HIGH_CARD;
  }
}


int main() {
  std::ifstream file("day7.txt");

  if (!file.is_open()) {
    std::cerr << "error" << std::endl;
    return 1;
  }

  std::string line;
  std::vector<std::string> sorted_hand;
  std::vector<std::pair<std::string, ull>> map;

  while (file) {
    getline(file, line);
    if (line.size() == 0) {
      break;
    }
    std::istringstream iss(line);
    std::string hand;
    ull value;

    iss >> hand >> value;
    sorted_hand.push_back(hand);
    map.push_back({ hand, value });
  }

  std::sort(map.begin(), map.end(), [](const std::pair<std::string, ull> &a, const std::pair<std::string, ull> &b) {
      Hands hand_a = parse_hand(a.first);
      Hands hand_b = parse_hand(b.first);
      std::string cards = "J23456789TQKA";
      if (hand_a != hand_b) {
        return hand_a > hand_b;
      } else {
        for (int i = 0; i < 5; i++) {
          if (a.first[i] != b.first[i]) {
            return cards.find(a.first[i]) > cards.find(b.first[i]);
          }
        }
      }
      return false;
    });

  ull ans = 0;

  // for (auto s : map) {
  //   std::cout << s.first << " " << s.second << std::endl;
  // }
  //
  for (size_t i = map.size(); i > 0; i--) {
    std::cout << map[map.size() - i].first << ": " << i << "*" << map[map.size() - i].second << std::endl;
    ans += i * map[map.size() - i].second;
  }

  std::cout << ans << std::endl;
}
