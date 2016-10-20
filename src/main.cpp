#include <cstdio>
  using std::printf;
#include <ctime>
#include <list>
  using std::list;
#include <string>
  using std::string;
#include <unordered_map>
  using std::unordered_map;
#include "Options.hpp"
  using libdec::DumbOption;
  using libdec::IOption;
#include "UtilitySystem.hpp"
  using libdec::UtilitySystem;

int iterations = 10000;

int main() {
  std::clock_t start = std::clock();
  UtilitySystem ai;

  list<DumbOption> options {
    { "dog", 6.0 },
    { "cat", 3.0 },
    { "sloth", 1.0 },
  };

  for(auto &option : options) {
    ai.addOption(option.desc(), &option);
  }

  unordered_map<string, int> testmap;
  

  for(int i = 0; i < iterations; i++) {
    auto choice = ai.decide();
    testmap[choice->desc()] += 1;
  }
  

  for(auto option : testmap) {
    printf("%s : %f\n", option.first.c_str(), (float) option.second / (float)iterations);
  }
  std::clock_t end = std::clock();

  printf("Time: %f ms\n", (end - start) / (double)(CLOCKS_PER_SEC));

  return 0;
}
