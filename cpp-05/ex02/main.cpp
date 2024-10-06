#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define TITLE(str) std::cout << "\n" << str << std::endl;
#define CATCH catch(const std::exception& e){ std::cerr << e.what() << '\n';}

int	main(void)
{
	try
	{
		TITLE("<< instance test >>")
		ShrubberyCreationForm s("s_target");
		std::cout << s;
		RobotomyRequestForm r("r_target");
		std::cout << r;
		PresidentialPardonForm p("p_target");
		std::cout << p;
		Bureaucrat b1("b1",10);
	}
	CATCH
	try
	{
		TITLE("<< copy test >>")
		TITLE("<< bureaucrat >>")
		Bureaucrat b1("b1",10);
		Bureaucrat b2("b2",20);
		std::cout << b2;
		b2 = b1;
		std::cout << b2;
		Bureaucrat b3 = b2;
		std::cout << b2;
		TITLE("\n<< shrubbery >>")
		ShrubberyCreationForm s1("s_target");
		b1.signForm(s1);
		ShrubberyCreationForm s2 = s1;
		std::cout << s2;
		TITLE("\n<< robotomy >>")
		RobotomyRequestForm r1("r_target");
		b1.signForm(r1);
		RobotomyRequestForm r2 = r1;
		std::cout << r2;
		TITLE("\n<< presidential >>")
		PresidentialPardonForm p1("p_target");
		b1.signForm(p1);
		PresidentialPardonForm p2 = p1;
		std::cout << p2;
		std::cout << std::endl;
		try
		{
			TITLE("\n<< shrubbery test >>")
			s1.beSigned(b1);
			b1.executeForm(s1);
			TITLE("\n<< robotomy test >>")
			r1.beSigned(b1);
			b1.executeForm(r1);
			TITLE("\n<< presidential test >>")
			b1.setGrade(1);
			p1.beSigned(b1);
			b1.executeForm(p1);
		}
		CATCH
		try
		{
			TITLE("\n<<  shrubbery test 2(executeForm fail)>>")
			b1.setGrade(145);
			std::cout << b1;
			s1.beSigned(b1);
			b1.executeForm(s1);
		}
		CATCH
		try
		{
			TITLE("\n<<  Robotomy test 2(executeForm fail)>>")
			b2.setGrade(72);
			std::cout << b2;
			r1.beSigned(b2);
			b2.executeForm(r1);	
		}
		CATCH
		try
		{
			TITLE("\n<<  Presidential test 2(executeForm fail)>>")
			b3.setGrade(25);
			std::cout << b3;
			p1.beSigned(b3);
			b3.executeForm(p1);	
		}
		CATCH
	}
	CATCH
	return (0);
}
