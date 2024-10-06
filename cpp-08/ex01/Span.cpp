#include "Span.hpp"

Span::Span(size_t n) : max_len(n) {}

Span::~Span() {}

Span::Span(const Span &other) { *this = other; }

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    this->max_len = other.max_len;
    this->ms = other.ms;
  }
  return (*this);
}

void Span::addNumber(int num) {
  if (this->ms.size() >= this->max_len)
    throw std::out_of_range("container is full");
  this->ms.insert(num);
}

long Span::shortestSpan() {
  size_t s = this->ms.size();
  if (s <= 1) throw std::out_of_range("container is too small");
  std::multiset<int>::iterator begin = this->ms.begin();
  std::multiset<int>::iterator end = this->ms.end();
  long s1 = *begin;
  begin++;
  long s2 = *begin;
  long ans = s2 - s1;
  while (1) {
    s1 = s2;
    begin++;
    if (begin == end) break;
    s2 = *begin;
    long span = s2 - s1;
    if (span < ans) ans = span;
  }
  return (ans);
}

long Span::longestSpan() {
  size_t s = this->ms.size();
  if (s <= 1) throw std::out_of_range("container is too small");
  std::multiset<int>::const_iterator begin = this->ms.begin();
  std::multiset<int>::const_reverse_iterator end = this->ms.rbegin();
  return ((long)*end - (long)*begin);
}
