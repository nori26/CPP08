#include <easyfind.hpp>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

#include "color.hpp"
#include "test.hpp"

const size_t g_max_width = 20;

void print_header(std::string funcname) {
  size_t len = funcname.size();

  if (len > g_max_width) {
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

void push_n_back(std::vector<int> &v, size_t n) {
  for (size_t i = 0; i < n; i++) {
    v.push_back(i);
  }
}

void insert_n(std::set<int> &, size_t n) {
  for (size_t i = 0; i < n; i++) {
    s.insert(i);
  }
}

void vector_test() {
  std::vector<int> empty;
  std::vector<int> v;
  std::vector<int> mult_v;
  const std::vector<int> &const_empty = empty;
  const std::vector<int> &const_v = v;
  const std::vector<int> &const_mult_v = mult_v;

  print_header(__func__);
  ft::eftest(empty, 0);

  v.push_back(0);
  ft::eftest(v, 0);

  push_n_back(mult_v, 3);
  ft::ef_n_test(mult_v, 3);
  ft::eftest(mult_v, 3);

  /* const test */
  print_header(std::string("const ") + __func__);
  ft::eftest(const_empty, 0);
  ft::eftest(const_v, 1);
  ft::ef_n_test(const_mult_v, 3);
  ft::eftest(const_mult_v, 3);
}

void set_test() {
  std::set<int> empty;
  std::set<int> set;
  std::set<int> mult_set;
  const std::set<int> &const_empty = empty;
  const std::set<int> &const_set = set;
  const std::set<int> &const_mult_set = mult_set;

  print_header(__func__);
  ft::eftest(empty, 0);

  set.insert(0);
  ft::eftest(set, 0);

  insert_n(mult_set, 3);
  ft::ef_n_test(mult_set, 3);
  ft::eftest(mult_set, 3);

  /* const test */
  print_header(std::string("const ") + __func__);
  ft::eftest(const_empty, 0);
  ft::eftest(const_set, 1);
  ft::ef_n_test(const_mult_set, 3);
  ft::eftest(const_mult_set, 3);
}

int main() { vector_test(); }
