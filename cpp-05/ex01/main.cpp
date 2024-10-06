#include "Bureaucrat.hpp"
#include "Form.hpp"
#define TITLE(str) std::cout << "\n" << str << std::endl;
#define CATCH catch(const std::exception& e){ std::cerr << e.what() << '\n';}

int	main(void)
{
	try
	{
		TITLE("<< instance test (Bureaucrat, too low) >>")
		Bureaucrat b1("b1", INT_MAX);
	}
	CATCH
	try
	{
		TITLE("<< instance test (Bureucrat too high) >>")
		Bureaucrat b1("b1", INT_MIN);
	}
	CATCH
	try
	{
		TITLE("<< instance test (Form, too high) >>")
		Form f1("f1", INT_MIN,INT_MIN);
	}
	CATCH
	try
	{
		TITLE("<< instance test (Form, too low) >>")
		Form f1("f1", INT_MAX,INT_MAX);	
	}
	CATCH
	try
	{
		TITLE("<< copy test >>")
		Bureaucrat b1("b1",1);
		Bureaucrat b2("b2",2);
		std::cout << b2;
		b2 = b1;
		std::cout << b2;
		Form f1("f1",10,10);
		Form f2("f2",20,20);
		std::cout << f2;
		f2 = f1;
		std::cout << f2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		TITLE("<< member function test (signForm, grade: b < f) >>")
		Bureaucrat b1("b1", 100);
		Form f1("f1", 10, 10);
		std::cout << b1;
		std::cout << f1;
		b1.signForm(f1);
		f1.beSigned(b1);
		std::cout << b1;
		std::cout << f1;
	}
	CATCH
	try
	{
		TITLE("<< member function test (beSigned, grade: b < f) >>")
		Bureaucrat b1("b1", 100);
		Form f1("f1", 10, 10);
		std::cout << b1;
		std::cout << f1;
		f1.beSigned(b1);
		b1.signForm(f1);
		std::cout << b1;
		std::cout << f1;
	}
	CATCH
	return (0);
}
