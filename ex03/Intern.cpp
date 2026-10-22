#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

namespace
{
    AForm* createShrubberyCreationForm(const std::string& target)
    {
        return new ShrubberyCreationForm(target);
    }

    AForm* createRobotomyRequestForm(const std::string& target)
    {
        return new RobotomyRequestForm(target);
    }

    AForm* createPresidentialPardonForm(const std::string& target)
    {
        return new PresidentialPardonForm(target);
    }
}

Intern::Intern()
{
    std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern &other)
{
    (void)other;
    std::cout << "Intern copy constructor called." << std::endl;
}

Intern& Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called." << std::endl;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    typedef AForm* (*FormCreator)(const std::string&);

    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    const FormCreator formCreators[] = {
        createShrubberyCreationForm,
        createRobotomyRequestForm,
        createPresidentialPardonForm
    };

    for (int i = 0; i < 3; ++i)
    {
        if (name == formNames[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Error: form '" << name << "' does not exist." << std::endl;
    return NULL;
}
