#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 private:
 public:
  typedef typename std::stack<T>::container_type container;
  typedef typename container::iterator iterator;
  typedef typename container::reverse_iterator reverse_iterator;
  MutantStack(){};
  ~MutantStack(){};
  MutantStack(MutantStack const &other) { *this = other; };
  MutantStack &operator=(MutantStack const &other) {
    {
      if (this != &other) {
        std::stack<T>::operator=(other);
      }
      return *this;
    }
  }
  iterator begin() { return this->c.begin(); };
  iterator end() { return this->c.end(); };
  reverse_iterator rbegin() { return this->c.rbegin(); };
  reverse_iterator rend() { return this->c.rend(); };
};

#endif
