#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm",
	25, 5), target(target)
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Form::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form(other), target(other.target)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw PresidentialPardonForm::NotSigned();
	if (executor.getGrade() > this->getGradeExec())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &obj)
{
	os << "target: " << obj.getTarget() << ", name: " << obj.getName() << ", grade_sign: " << obj.getGradeSign() << ", grade_exec: " << obj.getGradeExec() << std::flush;
	if (obj.getIsSigned() == false)
		os << ", is_signed: No" << std::endl;
	else
		os << ", is_signed: Yes" << std::endl;
	return (os);
}
