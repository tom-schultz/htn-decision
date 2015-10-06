#ifndef OPTIONS_HPP_
#define OPTIONS_HPP_

#include <string>
  using std::string;
#include "IHumanReadable.hpp"

namespace libdec {

class IOption : public IHumanReadable {
 public:
  virtual bool execute() = 0;
};

class IWeightedOption : public IOption {
 public:
  virtual float weight() const = 0;
};

class DumbOption : public IWeightedOption {
 public:
  DumbOption(const string &desc, const float &weight);
  float weight() const override;
  string desc() const override;
  bool execute() override;

 private:
  const string desc_;
  const float weight_;
};

}  // namespace libdec

#endif
