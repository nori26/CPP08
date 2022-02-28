#include <climits>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

#include "span.hpp"
#include "testutil.hpp"

namespace ft = fortytwo;

#define PUT_HEADER() ft::print_header(__func__)

void print_span(const Span &span) {
  std::cout << "storage : ";
  span.print_storage();
  std::cout << "shotest : " << span.shortestSpan() << "\n";
  std::cout << "longest : " << span.longestSpan() << std::endl << std::endl;
}

void empty_add_test() {
  PUT_HEADER();
  try {
    Span s(0);
    s.addNumber(1);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void empty_short_span_test() {
  PUT_HEADER();
  try {
    Span s(0);
    s.shortestSpan();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void empty_long_span_test() {
  PUT_HEADER();
  try {
    Span s(0);
    s.longestSpan();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void exceed_add_test() {
  PUT_HEADER();
  try {
    Span s(1);
    s.addNumber(1);
    s.addNumber(2);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
void exceed_add_duplicate_test() {
  PUT_HEADER();
  try {
    Span s(1);
    s.addNumber(1);
    s.addNumber(1);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void one_elem_short_span_test() {
  PUT_HEADER();
  try {
    Span s(1);
    s.addNumber(1);
    s.shortestSpan();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void one_elem_long_span_test() {
  PUT_HEADER();
  try {
    Span s(1);
    s.addNumber(1);
    s.longestSpan();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void basic_span_test() {
  PUT_HEADER();
  try {
    Span s(2);
    s.addNumber(1);
    s.addNumber(2);
    print_span(s);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void only_duplicate_span_test() {
  PUT_HEADER();
  try {
    Span s(2);
    s.addNumber(1);
    s.addNumber(1);
    print_span(s);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void duplicate_span_test() {
  PUT_HEADER();
  try {
    Span s(4);
    s.addNumber(1);
    s.addNumber(1);
    s.addNumber(5);
    s.addNumber(5);
    print_span(s);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void edge_value_test() {
  PUT_HEADER();
  try {
    Span s(4);
    s.addNumber(INT_MAX);
    s.addNumber(INT_MIN);
    print_span(s);

    s.addNumber(0);
    print_span(s);

    s.addNumber(1);
    print_span(s);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void itr_basic_span_test() {
  PUT_HEADER();
  try {
    Span s(2);
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    s.addNumber(v.begin(), v.end());
    print_span(s);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void itr_only_duplicate_span_test() {
  PUT_HEADER();
  try {
    Span s(2);
    std::vector<int> v;
    v.push_back(1);
    v.push_back(1);
    s.addNumber(v.begin(), v.end());
    print_span(s);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void itr_duplicate_span_test() {
  PUT_HEADER();
  try {
    Span s(3);
    std::vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(5);
    s.addNumber(v.begin(), v.end());
    print_span(s);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void itr_edge_value_test() {
  PUT_HEADER();
  try {
    Span s(10);
    std::vector<int> v;
    v.push_back(INT_MAX);
    v.push_back(INT_MIN);
    s.addNumber(v.begin(), v.end());
    print_span(s);

    v.push_back(0);
    s.addNumber(--v.end(), v.end());
    print_span(s);

    v.push_back(1);
    s.addNumber(--v.end(), v.end());
    print_span(s);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void large_test() {
  PUT_HEADER();
  try {
    Span s(9000001);
    for (int i = 1111; i < 9000000; i++) s.addNumber(i);
    s.addNumber(INT_MAX);
    std::cout << "shotest : " << s.shortestSpan() << "\n";
    std::cout << "longest : " << s.longestSpan() << std::endl << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void exception_test() {
  empty_add_test();
  empty_short_span_test();
  empty_long_span_test();
  exceed_add_test();
  exceed_add_duplicate_test();
  one_elem_short_span_test();
  one_elem_long_span_test();
}

void regular_test() {
  basic_span_test();
  only_duplicate_span_test();
  duplicate_span_test();
  edge_value_test();
}

void iterator_test() {
  itr_basic_span_test();
  itr_only_duplicate_span_test();
  itr_duplicate_span_test();
  itr_edge_value_test();
}

int main() {
  exception_test();
  regular_test();
  iterator_test();
  large_test();
}
