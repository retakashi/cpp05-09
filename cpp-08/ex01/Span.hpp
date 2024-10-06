#pragma once
#include <algorithm>
#include <exception>
#include <iostream>
#include <list>
#include <set>

class Span {
 private:
  Span();
  size_t max_len;
  std::multiset<int> ms;

 public:
  Span(size_t n);
  ~Span();
  Span(const Span& other);
  Span& operator=(const Span& other);
  void addNumber(int num);
  long shortestSpan();
  long longestSpan();

  template <typename I>
  void addRangeOfIterators(I begin, I end) {
    while (begin != end) {
      if (this->ms.size() >= this->max_len)
        throw std::out_of_range("container is full");
      this->ms.insert(*begin);
      begin++;
    }
  }
};
