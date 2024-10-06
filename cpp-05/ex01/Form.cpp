#include "Form.hpp"

Form::Form(std::string name, int grade_sign, int grade_exec) : name(name),
	grade_sign(grade_sign), grade_exec(grade_exec), is_signed(false)
{
	if (this->grade_sign < 1 || this->grade_exec < 1)
		throw Form::GradeTooHighException();
	if (this->grade_sign > 150 || this->grade_exec > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form Default constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		std::string &tmp = const_cast<std::string&> (this->name);
		tmp = other.name;
		int &s_tmp = const_cast<int&>(this->grade_sign);
		s_tmp = other.grade_sign;
		int &e_tmp = const_cast<int&>(this->grade_exec);
		e_tmp = other.grade_exec;
		this->is_signed = other.is_signed;
	}
	return (*this);
}

Form::Form(const Form &other) : name(other.name), grade_sign(other.grade_sign),
	grade_exec(other.grade_exec), is_signed(other.is_signed)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too hight");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const std::string &Form::getName() const
{
	return (this->name);
}

int Form::getGradeSign() const
{
	return (this->grade_sign);
}

int Form::getGradeExec() const
{
	return (this->grade_exec);
}

bool Form::getIsSigned() const
{
	return (this->is_signed);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign() || bureaucrat.getGrade() > this->getGradeExec())
		throw Form::GradeTooLowException();
	this->is_signed = true;
	std::cout << this->name << " was signed by " << bureaucrat.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "form's name: " << obj.getName() << ", grade_sign: " << obj.getGradeSign() << ", grade_exec: " << obj.getGradeExec();
	if (obj.getIsSigned() == false)
		os << ", is_signed: No" << std::endl;
	else
		os << ", is_signed: Yes" << std::endl;
	return (os);
}
