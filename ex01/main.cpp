#include <climits>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

#include "color.hpp"
#include "span.hpp"

const size_t g_max_width = 30;

void print_header(std::string funcname) {
  size_t len = funcname.size();

  if (len > g_max_width) {
    std::cerr << "header too long" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  size_t padding_size = g_max_width - len;
  size_t front_padding_size = padding_size / 2;
  size_t back_padding_size = padding_size - front_padding_size;

  std::cout << CYAN_BOLD_UNDELINE
            << "\n=============" << std::string(front_padding_size, ' ')
            << funcname << std::string(back_padding_size, ' ')
            << "=============\n"
            << RESET_COLOR << RESET_UNDERLINE << std::endl;
}

void print_span(Span &span) {
  std::cout << "storage : ";
  span.print_storage();
  std::cout << "shotest : " << span.shortestSpan() << "\n";
  std::cout << "longest : " << span.longestSpan() << std::endl << std::endl;
}

void empty_add_test() {
  print_header(__func__);
  try {
    Span s(0);
    s.addNumber(1);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void empty_short_span_test() {
  print_header(__func__);
  try {
    Span s(0);
    s.shortestSpan();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void empty_long_span_test() {
  print_header(__func__);
  try {
    Span s(0);
    s.longestSpan();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void exceed_add_test() {
  print_header(__func__);
  try {
    Span s(1);
    s.addNumber(1);
    s.addNumber(2);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
void exceed_add_duplicate_test() {
  print_header(__func__);
  try {
    Span s(1);
    s.addNumber(1);
    s.addNumber(1);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void one_elem_short_span_test() {
  print_header(__func__);
  try {
    Span s(1);
    s.addNumber(1);
    s.shortestSpan();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void one_elem_long_span_test() {
  print_header(__func__);
  try {
    Span s(1);
    s.addNumber(1);
    s.longestSpan();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void basic_span_test() {
  print_header(__func__);
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
  print_header(__func__);
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
  print_header(__func__);
  try {
    Span s(3);
    s.addNumber(1);
    s.addNumber(1);
    s.addNumber(5);
    print_span(s);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void edge_value_test() {
  print_header(__func__);
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
  print_header(__func__);
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
  print_header(__func__);
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
  print_header(__func__);
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
  print_header(__func__);
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
  print_header(__func__);
  try {
    Span s(9000000);
    for (int i = 0; i < 9000000; i++) s.addNumber(i);
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
