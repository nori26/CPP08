#include <climits>
#include <iostream>
#include <set>

#include "span.hpp"

int main() {
  Span s(10);
  // s.shortestSpan();
  s.addNumber(INT_MAX - 1);
  s.addNumber(INT_MIN + 1);
  std::cout << s.shortestSpan() << std::endl;
  std::cout << s.longestSpan() << std::endl;
  // s.print_storage();
}
