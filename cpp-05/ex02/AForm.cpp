#include "AForm.hpp"

AForm::AForm(std::string name, int grade_sign, int grade_exec) : name(name),
	grade_sign(grade_sign), grade_exec(grade_exec), is_signed(false)
{
	if (this->grade_sign < 1)
		throw AForm::GradeTooHighException();
	if (this->grade_sign > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), grade_sign(other.grade_sign),
	grade_exec(other.grade_exec), is_signed(other.is_signed)
{
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm Copy assignment operator called" << std::endl;
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

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too hight");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::NotSigned::what() const throw()
{
	return ("This form is not signed");
}

const char *AForm::FailedToOpenFile::what() const throw()
{
	return ("Failed to open out file");
}

const std::string &AForm::getName() const
{
	return (this->name);
}

int AForm::getGradeSign() const
{
	return (this->grade_sign);
}

int AForm::getGradeExec() const
{
	return (this->grade_exec);
}

bool AForm::getIsSigned() const
{
	return (this->is_signed);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();
	this->is_signed = true;
	std::cout << this->name << " was signed by " << bureaucrat.getName() << std::endl;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->is_signed == false)
		throw AForm::NotSigned();
	if (executor.getGrade() > this->grade_exec)
		throw AForm::GradeTooLowException();
	std::cout << "AForm's execute function" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << "AForm's name: " << obj.getName() << ", grade_sign: " << obj.getGradeSign() << ", grade_exec: " << obj.getGradeExec();
	if (obj.getIsSigned() == false)
		os << ", is_signed: No" << std::endl;
	else
		os << ", is_signed: Yes" << std::endl;
	return (os);
}
