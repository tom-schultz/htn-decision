#include "Options.hpp"
#include <stdexcept>
  using std::logic_error;
#include <string>
  using std::string;

namespace libdec {

DumbOption::DumbOption(const string &desc, const float &weight)
    : desc_(desc), weight_(weight) {
  if (weight < 0) {
    throw new logic_error("Option weights must be positive");
  }
}

float DumbOption::weight() const {
  return weight_;
}

string DumbOption::desc() const {
  return desc_;
}

bool DumbOption::execute() {
  printf("%s\n", desc_.c_str());
}

}  // namespace libdec
