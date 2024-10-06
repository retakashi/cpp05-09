#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class ScalarConverter {
 private:
  ScalarConverter();

 public:
  static void convert(const std::string &str);
  static char stoc(const std::string &str);
  static int ft_stoi(const std::string &str);
  static float ft_stof(const std::string &str);
  static double ft_stod(const std::string &str);
  static void outputFloat(const float n);
  static void outputDouble(const double n);
};
#endif
