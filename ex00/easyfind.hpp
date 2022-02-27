#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <stdexcept>
namespace ft {

// template <typename T>
// typename T::iterator easyfind(T &container, int target) {
//   typedef typename T::iterator Iter;

//   Iter begin = container.begin();
//   Iter end = container.end();
//   Iter place = std::find(begin, end, target);

//   if (place == end) {
//     throw std::runtime_error("number not exist in container");
//   } else
//     return (place);
// }

template <class T>
typename T::const_iterator easyfind(const T &container, int target) {
  typedef typename T::const_iterator ConstIter;

  ConstIter begin = container.begin();
  ConstIter end = container.end();
  ConstIter place = std::find(begin, end, target);

  if (place == end) {
    throw std::runtime_error("number not exist in container");
  } else
    return (place);
}
}  // namespace ft
#endif
