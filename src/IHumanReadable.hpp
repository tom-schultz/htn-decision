#ifndef IHUMANREADABLE_HPP_
#define IHUMANREADABLE_HPP_

#include <string>
  using std::string;

namespace libdec {

class IHumanReadable {
 public:
  virtual string desc() const = 0;
};

}  // namespace libdec

#endif
