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
template <class T>
typedef void (*f_append)(typename &T);

// void vector_test() {
//   std::vector<int> empty;
//   std::vector<int> v;
//   std::vector<int> mult_v;
//   const std::vector<int> &const_empty = empty;
//   const std::vector<int> &const_v = v;
//   const std::vector<int> &const_mult_v = mult_v;

//   print_header(__func__);
//   ft::eftest(empty, 0);

//   v.push_back(0);
//   ft::eftest(v, 0);

//   push_n_back(mult_v, 3);
//   ft::ef_n_test(mult_v, 3);
//   ft::eftest(mult_v, 3);

//   /* const test */
//   print_header(std::string("const ") + __func__);
//   ft::eftest(const_empty, 0);
//   ft::eftest(const_v, 1);
//   ft::ef_n_test(const_mult_v, 3);
//   ft::eftest(const_mult_v, 3);
// }
}  // namespace ft
#endif
