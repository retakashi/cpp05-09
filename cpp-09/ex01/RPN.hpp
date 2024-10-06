#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <sstream>
#include <exception>
#include <climits>
class RPN
{
    private:
        RPN();
        std::string rpn;
    public:
        RPN(std::string argv);
        RPN(const RPN &other);
        ~RPN();
        RPN &operator=(const RPN &other);
        bool isValidNumber();
        int getNum(char c);
        void calculate();
        int fourArithmeticOperations(char c,std::stack<int> &s);
        int addition(std::stack<int> &s);
        int subtraction(std::stack<int> &s);
        int multiplication(std::stack<int> &s);
        int division(std::stack<int> &s);
};
#endif
