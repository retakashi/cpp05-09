#ifndef Form_HPP
# define Form_HPP
# include "Bureaucrat.hpp"
# include <fstream>
class	Bureaucrat;

class Form
{
  private:
	Form();
	const std::string name;
	const int grade_sign;
	const int grade_exec;
	bool is_signed;	

  public:
	Form(std::string name, int grade_sign, int grade_exec);
	virtual ~Form();
	Form &operator=(const Form &other);
	Form(const Form &other);
	const std::string &getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool getIsSigned() const;
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	class NotSigned : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	class FailedToOpenFile : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};
std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
