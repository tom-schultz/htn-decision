#include <cstdio>
  using std::printf;
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

int main() {
  UtilitySystem ai;

  list<DumbOption> options {
    { "hunt", 1.0 },
    { "wander", 2.0 },
    { "make_noise", 1.5 },
    { "poop", 0.5 },
  };

  for(auto &option : options) {
    ai.addOption(option.desc(), &option);
  }

  IOption * choice = ai.decide();
  choice->execute();

  unordered_map<string, int> testmap;

  for(int i = 0; i < 10000000; i++) {
    choice = ai.decide();
    testmap[choice->desc()] += 1;
  }

  for(auto option : testmap) {
    printf("%s : %f\n", option.first.c_str(), (float) option.second / 100000.0);
  }

  return 0;
}
