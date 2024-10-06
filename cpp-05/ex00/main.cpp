#include "Bureaucrat.hpp"

#define TITLE(str) std::cout << "\n" << str << std::endl;
#define CATCH catch(const std::exception& e){ std::cerr << e.what() << '\n';}

int	main(void)
{
	try
	{
		TITLE("<< instance test (too low) >>")
		Bureaucrat b1("b1", INT_MAX);
	}
	CATCH
	try
	{
		TITLE("<< instance test (too high) >>")
		Bureaucrat b1("b1", 0);
	}
	CATCH
	try
	{
		TITLE("<< decrement/increment test >>")
		Bureaucrat b1("b1", 1);
		std::cout << b1 ;
		for(int i = 0; i < 10; i++)
		{
			b1.decrementGrade();
			std::cout << b1;
		}
		for (int i = 0; i < 11; i++)
		{
			b1.incrementGrade();
			std::cout << b1;
		}
	}
	CATCH
	try
	{
		TITLE("<< copy test >>")
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 2);
		std::cout << b2 ;
		b2 = b1;
		std::cout << b2 ;
		Bureaucrat b3 = b2;
		std::cout << b3;
	}
	CATCH
	return (0);
}
