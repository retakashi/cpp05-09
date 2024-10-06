#include "Span.hpp"
#include <climits>
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q span");
// }

int main() {
  try {
    Span sp = Span(1000000);
    sp.addNumber(-6);
    sp.addNumber(-5);
    sp.addNumber(17);
    sp.addNumber(INT_MAX);
    sp.addNumber(INT_MIN);
    int vlen = 900000;
    std::vector<int> v(vlen);
    for (int i = 0; i < vlen;i++)
      v[i] = i;
    sp.addRangeOfIterators(v.begin(),v.end());
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp.longestSpan() << std::endl;
    Span sp2(sp);
    std::cout << "sp2 shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "sp2 longest span: " << sp.longestSpan() << std::endl;
    sp.addRangeOfIterators(v.begin(),v.end());
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}
