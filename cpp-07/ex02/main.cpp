#include <ctime>
#include <iostream>
#include <string>

#include "Array.hpp"

#define MAX_VAL 10

int main(int, char **) {
  try {
    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
    std::cout << "\n[ Array<int> test ] " << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
      const int value = rand();
      numbers[i] = value;
      mirror[i] = value;
      std::cout << "numbers[" << i << "]: " << numbers[i] << std::endl;
      std::cout << "mirror[" << i << "]: " << mirror[i] << std::endl;
    }
    std::cout << "\n[copy test]" << std::endl;
    Array<int> copy(5);
    std::cout << "copy size before: " << copy.size() << std::endl;
    copy = numbers;
    std::cout << "copy size after: " << copy.size() << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
      std::cout << "copy[" << i << "]: " << copy[i] << std::endl;
    {
      Array<int> tmp = numbers;
      std::cout << "numbers size: " << numbers.size() << std::endl;
      Array<int> test(tmp);
      std::cout << "test size: " << test.size() << std::endl;
    }
    for (int i = 0; i < MAX_VAL; i++) {
      if (mirror[i] != numbers[i]) {
        std::cerr << "didn't save the same value!!" << std::endl;
        return 1;
      }
    }
    try {
      numbers[-2] = 0;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
    try {
      numbers[MAX_VAL] = 0;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++) {
      numbers[i] = rand();
    }
    delete[] mirror;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}
