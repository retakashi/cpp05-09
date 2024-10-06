#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP 
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
  private:
	RobotomyRequestForm();
	std::string target;

  public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	void execute(Bureaucrat const &executor) const;
	const std::string &getTarget() const;
};
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &obj);
#endif
