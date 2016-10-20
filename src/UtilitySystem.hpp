#ifndef IUTILITYSYSTEM_HPP_
#define IUTILITYSYSTEM_HPP_

#include <random>
  using std::mt19937;
  using std::uniform_real_distribution;
#include <string>
  using std::string;
#include <unordered_map>
  using std::unordered_map;
#include "IDecisionSystem.hpp"

namespace libdec {

class UtilitySystem : public IDecisionSystem {
 public:
  UtilitySystem();
  void addOption(const string &key, IWeightedOption * option);
  void removeOption(const string &key);
  IOption * decide() const override;
  
 private:
  unordered_map<string, IWeightedOption *> options_;
  float sum;
  mt19937 * mt;
  uniform_real_distribution<float> * dist;
};

}  // namespace libdec

#endif
