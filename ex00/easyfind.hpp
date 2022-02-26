#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>

namespace ft {
template <typename T>
typename T::iterator easyfind(T container, int target) {
  typedef typename T::iterator Iter;
  Iter begin = container.begin();
  Iter end = container.end();
  // Iter place = std::find()
  (void)end;
  (void)begin;
  (void)target;
  return (end);
}
}  // namespace ft
#endif
