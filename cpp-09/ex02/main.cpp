#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  try
  {
     PmergeMe p(argc,argv);
     p.startSort();
  }
  catch(const std::exception& e)
  {
  }
  return 0;
}
