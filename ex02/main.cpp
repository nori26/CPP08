#include <iostream>
#include <stack>

#include "mutantstack.hpp"
#include "testutil.hpp"

namespace ft = fortytwo;

#define PUT_HEADER() ft::print_header(__func__)

int main() {
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
  // std::stack<int> stack1;
  // std::stack<int> stack2;
  // stack1.push(1);
  // stack2 = stack1;
  // std::cout << stack2.top() << std::endl;
}
