#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

#define TITLE(str) std::cout << "\n" << str << std::endl;
#define CATCH catch(const std::exception& e){ std::cerr << e.what() << '\n';}

int	main(void)
{
	try
	{
		Intern	someRandomIntern;
		Form	*rrf;
		Bureaucrat b("b",10);

		TITLE("\n<< shurubbery test >>")
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << *rrf;
		rrf->beSigned(b);
		rrf->execute(b);
		delete rrf;	
		TITLE("\n<< robotomy test >>")
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf;
		rrf->beSigned(b);
		rrf->execute(b);
		delete rrf;	
		TITLE("\n<< presidential test >>")
		b.setGrade(1);
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *rrf;
		rrf->beSigned(b);
		rrf->execute(b);
		delete rrf;	
		TITLE("\n<< invalid form's name test >>")
		rrf = someRandomIntern.makeForm("aaa", "Bender");
		std::cout << *rrf;
		rrf->beSigned(b);
		rrf->execute(b);
		delete rrf;		
	}
	CATCH
	return (0);
}
