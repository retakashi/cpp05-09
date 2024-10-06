#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &str) {
  try {
    char ans;
    ans = ScalarConverter::stoc(str);
    std::cout << ans << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    int ans;
    ans = ScalarConverter::ft_stoi(str);
    std::cout << ans << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    float ans;
    ans = ScalarConverter::ft_stof(str);
    ScalarConverter::outputFloat(ans);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    double ans;
    ans = ScalarConverter::ft_stod(str);
    ScalarConverter::outputDouble(ans);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}

char ScalarConverter::stoc(const std::string &str) {
  int ret;
  char ans;
  ret = ft_stoi(str);
  if (32 > ret || ret > 126) throw std::out_of_range("Non displayable");
  ans = static_cast<char>(ret);
  return (ans);
}

int ScalarConverter::ft_stoi(const std::string &str) {
  int ans;
  try {
    ans = std::stoi(str);
  } catch (std::exception &e) {
    throw std::out_of_range("impossible");
  }
  return (ans);
}

float ScalarConverter::ft_stof(const std::string &str) {
  float ans;
  try {
    ans = std::stof(str);
  } catch (std::invalid_argument) {
    throw std::out_of_range("nanf");
  } catch (std::out_of_range) {
    if (str[0] == '-')
      throw std::out_of_range("-inff");
    else
      throw std::out_of_range("+inff");
  }
  return (ans);
}

double ScalarConverter::ft_stod(const std::string &str) {
  double ans;
  try {
    ans = std::stod(str);
  } catch (std::invalid_argument) {
    throw std::out_of_range("nan");
  } catch (std::out_of_range) {
    if (str[0] == '-')
      throw std::out_of_range("-inf");
    else
      throw std::out_of_range("+inf");
  }
  return (ans);
}

void ScalarConverter::outputFloat(const float n) {
  std::stringstream ss;
  std::string str;
  ss << n;
  ss >> str;
  if (str == "nan")
    throw std::out_of_range("nanf");
  if (str == "-inf")
    throw std::out_of_range("-inff");
  if (str == "inf")
    throw std::out_of_range("+inff");
  std::string::size_type p_pos;
  p_pos = str.find(".");
  if (p_pos == std::string::npos) std::cout << str << ".0f" << std::endl;
  else
  std::cout << str << "f" << std::endl;
}

void ScalarConverter::outputDouble(const double n) {
  std::stringstream ss;
  std::string str;
  ss << n;
  ss >> str;
  if (str == "nan")
    throw std::out_of_range("nan");
  if (str == "-inf")
    throw std::out_of_range("-inf");
  if (str == "inf")
    throw std::out_of_range("+inf");
  std::string::size_type p_pos;
  p_pos = str.find(".");
  if (p_pos == std::string::npos) std::cout << str << ".0" << std::endl;
  else std::cout << str << std::endl;
}
