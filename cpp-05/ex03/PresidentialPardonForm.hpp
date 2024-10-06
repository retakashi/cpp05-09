#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP
#include "Form.hpp"

class  PresidentialPardonForm : public Form
{
    private:
        PresidentialPardonForm();
	std::string target;

  public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	virtual void execute(Bureaucrat const &executor) const;
	const std::string &getTarget() const;
};
std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &obj);
#endif
