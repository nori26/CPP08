#ifndef SPAN_HPP
#define SPAN_HPP
#include <set>
#include <stdexcept>
#include <utility>
#include <vector>

class Span {
 private:
  typedef std::set<int>::iterator SetIter;
  typedef std::pair<SetIter, bool> Pair;

  unsigned int capacity;
  unsigned int added;
  unsigned int shortest_span;
  std::set<int> storage;
  unsigned int get_prev_span(SetIter place) const;
  unsigned int get_next_span(SetIter place) const;
  void update_shotest_span(Pair result);

 public:
  Span(unsigned int N);
  ~Span();
  Span(Span const &other);
  Span &operator=(Span const &other);

  void addNumber(int num);
  void addNumber(std::vector<int>::iterator begin,
                 std::vector<int>::iterator end);
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;
  void print_storage() const;

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
