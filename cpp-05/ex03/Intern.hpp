#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
    Form *makeForm(const std::string &form_name, const std::string &target);
    class InvalidFormNameException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};
#endif
