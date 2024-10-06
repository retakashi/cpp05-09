#include "RPN.hpp"

RPN::RPN(std::string argv) : rpn(argv){}
RPN::RPN(const RPN &other) { *this = other; }
RPN::~RPN(){}
RPN &RPN::operator=(const RPN &other) {
  if (this != &other) {
    this->rpn = other.rpn;
  }
  return (*this);
}

bool RPN::isValidNumber() {
  for (size_t i = 0; this->rpn[i] != '\0'; i++) {
    if (std::isdigit(this->rpn[0]) == false)
      return (false);
    if (this->rpn[i] == '-' && std::isdigit(this->rpn[i + 1]) == true) return (false);
    if (std::isdigit(this->rpn[i]) == true &&
        isspace(this->rpn[i + 1]) == false)
      return (false);
  }
  return (true);
}

int RPN::getNum(char c) {
  std::stringstream ss;
  int ret = 0;
  ss << c;
  ss >> ret;
  return (ret);
}

int RPN::fourArithmeticOperations(char c,std::stack<int> &s) {
  int ret = 0;
  switch (c) {
    case '+':
      ret = addition(s);
      break;
    case '-':
      ret = subtraction(s);
      break;
    case '*':
      ret = multiplication(s);
      break;
    case '/':
      ret = division(s);
      break;
    default:
      break;
  }
  return (ret);
}

//num2 + num
int RPN::addition(std::stack<int> &s) {
  int num = 0;
  int num2 = 0;
  num = s.top();
  s.pop();
  if (s.empty()) {
    std::cout << "Error" << std::endl;
    return (-1);
  }
  num2 = s.top();
  if (num2 > 0 && (INT_MAX - num2) < num) {
    std::cout << "Exceeded INT_MAX" << std::endl;
    return (-1);
  }
  s.pop();
  num2 += num;
  s.push(num2);
  return (0);
}

//num2 - num
int RPN::subtraction(std::stack<int> &s) {
  int num = 0;
  int num2 = 0;
  num = s.top();
  s.pop();
  if (s.empty()) {
    std::cout << "Error" << std::endl;
    return (-1);
  }
  num2 = s.top();
  if (num2 < 0 && (INT_MIN + num) > num2) {
    std::cout << "Exceeded INT_MIN" << std::endl;
    return (-1);
  }
  s.pop();
  num2 -= num;
  s.push(num2);
  return (0);
}

//num2 * num
int RPN::multiplication(std::stack<int> &s) {
  int num = 0;
  int num2 = 0;
  num = s.top();
  s.pop();
  if (s.empty()) {
    std::cout << "Error" << std::endl;
    return (-1);
  }
  num2 = s.top();
  if (num2 > 0 && num > 0 && (INT_MAX / num) < num2) {
    std::cout << "Exceeded INT_MAX" << std::endl;
    return (-1);
  }
  if (num2 < 0 && num > 0 && (INT_MIN / num) > num2) {
    std::cout << "Exceeded INT_MIN" << std::endl;
    return (-1);
  }
  s.pop();
  num2 *= num;
  s.push(num2);
  return (0);
}

//num2 / num
int RPN::division(std::stack<int> &s) {
  int num = 0;
  int num2 = 0;
  num = s.top();
  s.pop();
  if (s.empty()) {
    std::cout << "Error" << std::endl;
    return (-1);
  }
  num2 = s.top();
  if (num == 0) {
    std::cout << "Division by zero" << std::endl;
    return (-1);
  }
  s.pop();
  num2 /= num;
  s.push(num2);
  return (0);
}

void RPN::calculate() {
  if (isValidNumber() == false) {
    std::cout << "Error" << std::endl;
    throw std::exception();
  }
  std::stack<int> s;
  size_t i = 0;
  std::string fao = "+-*/";
  while (this->rpn[i] != '\0') {
    if (std::isdigit(this->rpn[i]) == true)
        s.push(getNum(this->rpn[i]));
    else if (fao.find(this->rpn[i]) != std::string::npos &&
               fourArithmeticOperations(this->rpn[i],s) == -1)
      throw std::exception();
    i++;
  }
  if (s.size() != 1) {
    std::cout << "Error" << std::endl;
    throw std::exception();
  }
  std::cout << s.top() << std::endl;
}
