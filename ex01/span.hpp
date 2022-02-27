#ifndef SPAN_HPP
#define SPAN_HPP
#include <set>
class Span {
 private:
  unsigned int capacity;
  unsigned int added;
  unsigned int shortest_span;
  bool has_duplicate;
  std::set<int> storage;
  unsigned int get_prev_span(std::set<int>::iterator place);
  unsigned int get_next_span(std::set<int>::iterator place);
  void update_shotest_span(std::set<int>::iterator place);

 public:
  Span(unsigned int N);
  ~Span();
  Span(Span const &other);
  Span &operator=(Span const &other);
  void addNumber(int num);
  void print_storage() const;
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;
};
#endif
