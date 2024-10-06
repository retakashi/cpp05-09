#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Too few arguments" << std::endl;
    return (EXIT_FAILURE);
  }
  int i = 1;
  while (argv[i] != NULL) {
      ScalarConverter::convert((const std::string)argv[i]);
      std::cout << std::endl;
    i++;
  }
  return (0);
}
