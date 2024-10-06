#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Default constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern Copy constructor called" << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern Copy assignment operator called" << std::endl;
    if (this != &other)
    {
    }
        return (*this);
}

Form *Intern::makeForm(const std::string &form_name, const std::string &target)
{
    Form *f_ptr = NULL;
    enum {s,r,p};
    std::string str[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    const int total = 3;
    int i = 0;
    while (i < total && form_name != str[i])
        i++;
    if (i == total)
        throw Intern::InvalidFormNameException();
    try
    {
        switch(i)
        {
            case(s):
                f_ptr = new ShrubberyCreationForm(target);
                break;
            case(r):
                f_ptr = new RobotomyRequestForm(target);
                break;
            case(p):
                f_ptr = new PresidentialPardonForm(target);
                break; 
        }
    }
    catch(std::bad_alloc &e)
    {
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
    return (f_ptr);
}

const char *Intern::InvalidFormNameException::what() const throw()
{
	return ("Invalid form name. Please enter one of the following: \nshrubbery creation \nrobotomy request \npresidential pardon");
}
