#ifndef TESTUTIL_HPP
#define TESTUTIL_HPP

#include <string>

namespace fortytwo {
void print_header(std::string funcname);

template <typename Iter>
void iter_test(Iter begin, Iter end) {
  for (; begin != end; begin++) {
    std::cout << *begin << ", ";
  }
  std::cout << std::endl;
}
}  // namespace fortytwo
#endif
