#include <iostream>
#include <stack>

#include "mutantstack.hpp"
#include "testutil.hpp"

namespace ft = fortytwo;

#define PUT_HEADER() ft::print_header(__func__)

void subject_test() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it;   // = mstack.begin();
  MutantStack<int>::iterator ite;  // = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

void operatoreq_test() {
  PUT_HEADER();
  MutantStack<int> mstack;
  MutantStack<int> mstack2;
  mstack.push(5);
  mstack.push(6);
  mstack.push(7);
  mstack2 = mstack;
  for (size_t i = 0; i < 3; i++) {
    std::cout << mstack2.top() << ", ";
    mstack2.pop();
  }
  std::cout << std::endl;
}

void normal_iter_test(MutantStack<int> mstack) {
  PUT_HEADER();
  ft::iter_test(mstack.begin(), mstack.end());
}

void const_normal_iter_test(const MutantStack<int> mstack) {
  PUT_HEADER();
  ft::iter_test(mstack.begin(), mstack.end());
}

void reverse_normal_iter_test(MutantStack<int> mstack) {
  PUT_HEADER();
  ft::iter_test(mstack.rbegin(), mstack.rend());
}

void const_reverse_iter_test(const MutantStack<int> mstack) {
  PUT_HEADER();
  ft::iter_test(mstack.rbegin(), mstack.rend());
}

void mstack_init(MutantStack<int> &mstack) {
  for (int i = 0; i < 10; i++) {
    mstack.push(i);
  }
}

void iter_test() {
  MutantStack<int> mstack;

  mstack_init(mstack);
  normal_iter_test(mstack);
  const_normal_iter_test(mstack);
  reverse_normal_iter_test(mstack);
  const_reverse_iter_test(mstack);
}

int main() {
  subject_test();
  operatoreq_test();
  iter_test();
}
