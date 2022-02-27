#ifndef TEST_HPP
#define TEST_HPP
#include "easyfind.hpp"

namespace ft {

template <class T>
void print_content(const T &container) {
  typedef typename T::const_iterator Iter;

  std::cout << "\ncontents : ";
  if (container.empty()) {
    std::cout << "empty";
  } else {
    for (Iter i = container.begin(), end = container.end(); i != end; i++) {
      std::cout << *i << ", ";
    }
  }
  std::cout << std::endl;
}

template <class T>
void eftest(const T &container, int n) {
  try {
    print_content(container);
    std::cout << "target   : " << n << std::endl;
    std::cout << "result   : " << *easyfind(container, n) << std::endl;
  } catch (std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }
}

template <class T>
void ef_n_test(const T &container, size_t n) {
  for (size_t i = 0; i < n; i++) {
    eftest(container, i);
  }
}
}  // namespace ft
#endif
