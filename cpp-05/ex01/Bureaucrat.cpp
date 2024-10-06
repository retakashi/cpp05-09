#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->grade = other.grade;
		std::string &tmp = const_cast<std::string&> (this->name);
		tmp = other.name;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

// const _NOEXCEPT(c++11~) == const throw()(C++98)
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade is too hight");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade is too low");
}

const std::string &Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::setGrade(int new_grade)
{
	if (new_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (new_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = new_grade;	
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << std::flush;
		std::cerr << e.what() << '\n';
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << "bureaucrat's name: " << obj.getName() << ", bureaucrat grade : " << obj.getGrade() << std::endl;
	return (os);
}
