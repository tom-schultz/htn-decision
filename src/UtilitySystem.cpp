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

void UtilitySystem::addOption(const string &key, IWeightedOption * option) {
  options_[key] = option;
}

void UtilitySystem::removeOption(const string &key) {
  options_.erase(key);
}

IOption * UtilitySystem::decide() const {
  float sum = 0;

  for(auto option : options_) {
    sum += option.second->weight();
  }

  random_device rd;
  mt19937 mt(rd());
  uniform_real_distribution<float> dist(0.0, sum);
  float num = dist(mt);

  for(auto option : options_) {
    if(num < option.second->weight()) {
      return option.second;
    }

    num -= option.second->weight();
  }

  throw new logic_error("UtilitySystem::decide() reached the end of the options and didn't return.");
}

}
