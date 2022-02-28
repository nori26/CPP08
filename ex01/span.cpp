#include "span.hpp"

#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <utility>

typedef std::set<int>::iterator SetIter;
typedef std::pair<SetIter, bool> Pair;
namespace {
SetIter next(SetIter iter) { return (++iter); }
SetIter prev(SetIter iter) { return (--iter); }
}  // namespace
Span::Span(unsigned int N)
    : capacity(N), added(), shortest_span(UINT_MAX), has_duplicate(false) {}

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
    std::cout << "cap error" << std::endl;
    return;  // exception
  }
  Pair result = storage.insert(num);
  SetIter place = result.first;
  bool is_duplicate = result.second == false;
  has_duplicate |= is_duplicate;
  added++;
  update_shotest_span(place);
}

unsigned int Span::shortestSpan() const {
  if (added < 2) {
    std::cout << "span error" << std::endl;
    return UINT_MAX;  // exception
  }
  return shortest_span;
}

unsigned int Span::longestSpan() const {
  if (added < 2) {
    std::cout << "span error" << std::endl;
    return UINT_MAX;  // exception
  }
  int min_value = *storage.begin();
  int max_value = *--storage.end();
  return max_value - min_value;
}

void Span::update_shotest_span(SetIter place) {
  if (has_duplicate) {
    shortest_span = 0;
    return;
  }
  if (storage.size() < 2) {
    return;
  }
  unsigned int prev_span = get_prev_span(place);
  unsigned int next_span = get_next_span(place);
  unsigned int latest_span = std::min(prev_span, next_span);

  if (latest_span < shortest_span) shortest_span = latest_span;
}

unsigned int Span::get_prev_span(SetIter now) {
  if (now == storage.begin()) {
    return (UINT_MAX);
  }
  int lower = *prev(now);
  int upper = *now;
  unsigned int span = upper - lower;
  return (span);
}

unsigned int Span::get_next_span(SetIter now) {
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
    std::cout << *i << ",";
  }
  std::cout << std::endl;
}
