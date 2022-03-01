#include "span.hpp"

#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <stdexcept>
#include <utility>
#include <vector>

typedef std::set<int>::iterator SetIter;

namespace {
SetIter next(SetIter iter) { return (++iter); }
SetIter prev(SetIter iter) { return (--iter); }
}  // namespace

Span::Span() : capacity(), added(), shortest_span(UINT_MAX) {}
Span::Span(unsigned int N) : capacity(N), added(), shortest_span(UINT_MAX) {}

Span::~Span() {}

Span::Span(Span const &other) { *this = other; }

Span &Span::operator=(Span const &other) {
  if (this == &other) {
    return *this;
  }
  capacity = other.capacity;
  added = other.added;
  shortest_span = other.shortest_span;
  storage = other.storage;
  return *this;
}

void Span::addNumber(int num) {
  if (added == capacity) {
    throw Span::TooManyElemException("too many elements");
  }
  added++;
  Pair result = storage.insert(num);
  update_shotest_span(result);
}

void Span::addNumber(std::vector<int>::iterator begin,
                     std::vector<int>::iterator end) {
  for (std::vector<int>::iterator itr = begin; itr != end; itr++) {
    int n = *itr;
    addNumber(n);
  }
}

unsigned int Span::shortestSpan() const {
  if (added < 2) {
    throw Span::TooFewElemException("too few elements");
  }
  return shortest_span;
}

unsigned int Span::longestSpan() const {
  if (added < 2) {
    throw Span::TooFewElemException("too few elements");
  }
  int min_value = *storage.begin();
  int max_value = *--storage.end();
  return max_value - min_value;
}

void Span::update_shotest_span(Pair result) {
  SetIter added_place = result.first;
  bool is_duplicate = result.second == false;

  if (is_duplicate) {
    shortest_span = 0;
    return;
  }
  if (storage.size() < 2) {
    return;
  }
  unsigned int prev_side_span = get_prev_span(added_place);
  unsigned int next_side_span = get_next_span(added_place);
  unsigned int new_span = std::min(prev_side_span, next_side_span);

  if (new_span < shortest_span) shortest_span = new_span;
}

unsigned int Span::get_prev_span(SetIter now) const {
  if (now == storage.begin()) {
    return (UINT_MAX);
  }
  int lower = *prev(now);
  int upper = *now;
  unsigned int span = upper - lower;
  return (span);
}

unsigned int Span::get_next_span(SetIter now) const {
  if (next(now) == storage.end()) {
    return (UINT_MAX);
  }
  int lower = *now;
  int upper = *next(now);
  unsigned int span = upper - lower;
  return (span);
}

void Span::print_storage() const {
  for (SetIter i = storage.begin(), end = storage.end(); i != end; i++) {
    std::cout << *i << ", ";
  }
  std::cout << std::endl;
}

Span::TooManyElemException::TooManyElemException(const std::string &msg)
    : std::runtime_error(msg) {}
Span::TooFewElemException::TooFewElemException(const std::string &msg)
    : std::runtime_error(msg) {}
