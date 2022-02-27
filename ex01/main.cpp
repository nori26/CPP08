#include <iostream>
#include <set>

#include "span.hpp"

int main() {
  Span s(10);
  s.shortestSpan();
  s.addNumber(10);
  s.addNumber(1);
  std::cout << s.shortestSpan() << std::endl;
  s.print_storage();
}
