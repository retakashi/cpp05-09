#pragma once

#include <deque>
#include <stack>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q mutantstack");
// }

template <typename T, typename Sequence = std::deque<T> >
class MutantStack : public std::stack<T, Sequence> {
 public:
  MutantStack(){};
  MutantStack(const MutantStack &other) { *this = other; }
  MutantStack &operator=(const MutantStack &other) {
    if (this != &other) {
      std::stack<T, Sequence>::operator=(other);
    }
    return (*this);
  }
  ~MutantStack(){};
  typedef typename Sequence::iterator iterator;
  typedef typename Sequence::const_iterator const_iterator;
  typedef typename Sequence::reverse_iterator reverse_iterator;
  typedef typename Sequence::const_reverse_iterator const_reverse_iterator;
  typename Sequence::iterator begin() throw() { return this->c.begin(); }
  typename Sequence::iterator end() throw() { return this->c.end(); }
  typename Sequence::reverse_iterator rbegin() throw() { return this->c.rbegin(); }
  typename Sequence::reverse_iterator rend() throw() { return this->c.rend(); }
};
