#ifndef IUTILITYSYSTEM_HPP_
#define IUTILITYSYSTEM_HPP_

#include <string>
  using std::string;
#include <unordered_map>
  using std::unordered_map;
#include "IDecisionSystem.hpp"

namespace libdec {

class UtilitySystem : public IDecisionSystem {
 public:
  void addOption(const string &key, IWeightedOption * option);
  void removeOption(const string &key);
  IOption * decide() const override;
  
 private:
  unordered_map<string, IWeightedOption *> options_;
};

}  // namespace libdec

#endif
