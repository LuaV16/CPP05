#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default_target") 
{
    std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) 
{
    std::cout << "ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
    std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getIs_signed())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getReq_exec())
        throw AForm::GradeTooLowException();

    std::ofstream file((target + "_shrubbery").c_str());

    if (!file)
        throw std::runtime_error("Could not create shrubbery file");

    file << "             ccee88oo\n";
    file << "         C8O8O8Q8PoOb o8oo\n";
    file << "         dOB69QO8PdUOpugoO9bD\n";
    file << "       CgggbU8OU qOp qOdoUOdcb\n";
    file << "         6OuU  /p u gcoUodpP\n";
    file << "           \\\\\\//  /douUP\n";
    file << "               \\\\\\////\n";
    file << "                |||/\\n";
    file << "                |||/\\\n";
    file << "                |||||\n";
    file << "          .....//||||\\....\n";
}