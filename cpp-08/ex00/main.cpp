#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q easyfind");
// }

int main() {
  std::cout << "\n<< vector test >>" << std::endl;
  int vlen = 10000000;
  std::vector<int> v(vlen);
  for (int i = 0; i < vlen; i++) v[i] = i;
  std::vector<int>::const_iterator vbegin = v.begin();
  std::vector<int>::const_iterator vret = easyfind(v, 10000000);
  if (vret == v.end())
    std::cout << "not found" << std::endl;
  else
    std::cout << "found index: " << vret - vbegin << std::endl;

  std::cout << "\n<< list test >>" << std::endl;
  int llen = 100;
  std::list<int> l;
  for (int i = 0; i < llen; i++) {
      l.push_front(i);
  }
  std::list<int>::const_iterator lbegin = l.begin();
  std::list<int>::const_iterator lret = easyfind(l, 5);
  if (lret == l.end())
    std::cout << "not found" << std::endl;
  else
    std::cout << "found index: " << std::distance(lbegin, lret) << std::endl;

  std::cout << "\n<< deque test >>" << std::endl;
  int dlen = 10;
  std::deque<int> d;
  for (int i = 0; i < dlen; i++) d.push_back(i);
  std::deque<int>::const_iterator dbegin = d.begin();
  std::deque<int>::const_iterator dret = easyfind(d, 8);
  if (dret == d.end())
    std::cout << "not found" << std::endl;
  else
    std::cout << "found index: " << std::distance(dbegin, dret) << std::endl;
  return (0);
}
