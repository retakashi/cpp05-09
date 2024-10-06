#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm",
	72, 45), target(target)
{
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other),
	target(other.target)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw RobotomyRequestForm::NotSigned();
	if (executor.getGrade() > this->getGradeExec())
		throw RobotomyRequestForm::GradeTooLowException();
	std::cout << "vrrr..." << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int ret = std::rand();
	if (ret % 2 == 0)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " has failed to be robotomized" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &obj)
{
	os << "target: " << obj.getTarget() << ", name: " << obj.getName() << ", grade_sign: " << obj.getGradeSign() << ", grade_exec: " << obj.getGradeExec();
	if (obj.getIsSigned() == false)
		os << ", is_signed: No" << std::endl;
	else
		os << ", is_signed: Yes" << std::endl;
	return (os);
}
