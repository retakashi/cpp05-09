#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
	PresidentialPardonForm();
	std::string target;

  public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	void execute(Bureaucrat const &executor) const;
	const std::string &getTarget() const;
};
std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &obj);
#endif
