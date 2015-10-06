#ifndef IIDECISIONSYSTEM_HPP_
#define IIDECISIONSYSTEM_HPP_

#include "Options.hpp"

namespace libdec {

class IDecisionSystem {
 public:
  virtual IOption * decide() const = 0;
};

}  // namespace libdec

#endif
