#include "RPN.hpp"

int main(int argc, char** argv) {
  if (argc != 2) return 0;
  try {
    RPN p(argv[1]);
    p.calculate();
  } catch (const std::exception& e) {
  }
  return 0;
}
