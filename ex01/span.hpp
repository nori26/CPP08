#ifndef SPAN_HPP
#define SPAN_HPP
#include <set>
#include <stdexcept>
#include <utility>

class Span {
 private:
  typedef std::set<int>::iterator SetIter;
  typedef std::pair<SetIter, bool> Pair;

  unsigned int capacity;
  unsigned int added;
  unsigned int shortest_span;
  std::set<int> storage;
  unsigned int get_prev_span(SetIter place);
  unsigned int get_next_span(SetIter place);
  void update_shotest_span(Pair result);

 public:
  Span(unsigned int N);
  ~Span();
  Span(Span const &other);
  Span &operator=(Span const &other);
  void addNumber(int num);
  void print_storage() const;
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;

  class TooManyElemException : public std::runtime_error {
   public:
    TooManyElemException(const std::string &msg = "too many elements");
  };
  class TooFewElemException : public std::runtime_error {
   public:
    TooFewElemException(const std::string &msg = "too few elements");
  };
};
#endif
