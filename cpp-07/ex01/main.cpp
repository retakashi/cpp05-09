#include "iter.hpp"

int main()
{
  try
  {
    std::string str[3] = {"hello", "world", "!!!"};
    int arr[5] = {1, 2, 3, 4, 5};
    const char *str2 = "hello";
    const int* const a = new int[6]();

    std::cout << "<< std::string[] result >> " << std::endl;
    ::iter(str, 3, &func<std::string>);
    std::cout << "<< int[] result >>" << std::endl;
    ::iter(arr, 5, &func<int>);
    std::cout << "<< const char* result >> " << std::endl;
    ::iter(str2, 5, &funcConst<char>);
    std::cout << "<< const int* const result >> " << std::endl;
    ::iter(a, 5, &funcConst<int>);
    delete[] a;
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << e.what() << '\n';
  }
  return 0;
}
