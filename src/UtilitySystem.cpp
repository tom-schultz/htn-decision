#include "UtilitySystem.hpp"
#include <random>
  using std::mt19937;
  using std::random_device;
  using std::uniform_real_distribution;
#include <stdexcept>
  using std::logic_error;
#include <string>
  using std::string;

namespace libdec {

UtilitySystem::UtilitySystem() {
  random_device rd;
  mt = new mt19937(rd());
}

void UtilitySystem::addOption(const string &key, IWeightedOption * option) {
  sum = 0;
  options_[key] = option;

  for(auto option : options_) {
    sum += option.second->weight();
  }

  dist = new uniform_real_distribution<float>(0.0, sum);
}

void UtilitySystem::removeOption(const string &key) {
  options_.erase(key);
}

IOption * UtilitySystem::decide() const {
  float num = (*dist)(*mt);
  //float num = 3.0;

  for(auto option : options_) {
    if(num < option.second->weight()) {
      return option.second;
    }

    num -= option.second->weight();
  }

  throw new logic_error("UtilitySystem::decide() reached the end of the options and didn't return.");
}

}
