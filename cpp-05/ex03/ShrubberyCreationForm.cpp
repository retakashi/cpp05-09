#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm",
	145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Form::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form(other),
	target(other.target)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw ShrubberyCreationForm::NotSigned();
	if (executor.getGrade() > this->getGradeExec())
		throw ShrubberyCreationForm::GradeTooLowException();
	std::string file_name;
	file_name = this->target;
	std::ofstream ofs;
	file_name = file_name.append("_shrubbery");
	ofs.open(file_name);
	if (!ofs)
		throw ShrubberyCreationForm::FailedToOpenFile();
	ofs << TREE_ASCII_ART;
	ofs << TREE_ASCII_ART;	
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj)
{
	os << "target: " << obj.getTarget() << ", name: " << obj.getName() << ", grade_sign: " << obj.getGradeSign() << ", grade_exec: " << obj.getGradeExec() << std::flush;
	if (obj.getIsSigned() == false)
		os << ", is_signed: No" << std::endl;
	else
		os << ", is_signed: Yes" << std::endl;
	return (os);
}
