#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# define TREE_ASCII_ART \
    "        ^\n" \
    "       / \\\n" \
    "      / _ \\\n" \
    "     / / \\ \\\n" \
    "    / /   \\ \\\n" \
    "   / /_____\\ \\\n" \
    "  /__________ \\\n" \
    "      [___]\n" \
    "      [___]\n"

class ShrubberyCreationForm : public Form
{
  private:
	ShrubberyCreationForm();
	std::string target;

  public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	virtual void execute(Bureaucrat const &executor) const;
	const std::string &getTarget() const;
};
std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj);
#endif
