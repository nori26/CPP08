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
  typedef typename container::const_iterator const_iterator;
  typedef typename container::const_reverse_iterator const_reverse_iterator;

  MutantStack(){};
  ~MutantStack(){};
  MutantStack(MutantStack const &other) { *this = other; };
  MutantStack &operator=(MutantStack const &other) {
    {
      if (this != &other) {
        std::stack<T>::operator=(other);
      }
    }
    return *this;
  }
  iterator begin() { return this->c.begin(); };
  iterator end() { return this->c.end(); };
  const_iterator begin() const { return this->c.begin(); };
  const_iterator end() const { return this->c.end(); };
  reverse_iterator rbegin() { return this->c.rbegin(); };
  reverse_iterator rend() { return this->c.rend(); };
  const_reverse_iterator rbegin() const { return this->c.rbegin(); };
  const_reverse_iterator rend() const { return this->c.rend(); };
};

#endif
