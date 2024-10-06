#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP 
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
  private:
	RobotomyRequestForm();
	std::string target;

  public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	virtual void execute(Bureaucrat const &executor) const;
	const std::string &getTarget() const;
};
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &obj);
#endif
