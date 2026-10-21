#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdio>
#include <cstdlib>

int main()
{
    std::cout << "Test ShrubberyCreationForm" << std::endl;
    ShrubberyCreationForm shrubbery("home");
    Bureaucrat intern("Intern", 150);
    Bureaucrat manager("Manager", 100);
    Bureaucrat gardener("Gardener", 137);

    intern.signAForm(shrubbery);
    intern.executeForm(shrubbery);
    manager.signAForm(shrubbery);
    manager.executeForm(shrubbery);
    gardener.executeForm(shrubbery);
    std::remove("home_shrubbery");
    std::cout << std::endl;

    std::cout << "Test RobotomyRequestForm" << std::endl;
    RobotomyRequestForm robotomy("Bender");
    Bureaucrat technician("Technician", 72);
    Bureaucrat robotomizer("Robotomizer", 45);

    technician.signAForm(robotomy);
    technician.executeForm(robotomy);
    robotomizer.executeForm(robotomy);
    std::cout << std::endl;

    std::cout << "Test PresidentialPardonForm" << std::endl;
    PresidentialPardonForm pardon("Arthur Dent");
    Bureaucrat clerk("Clerk", 25);
    Bureaucrat president("President", 5);

    clerk.signAForm(pardon);
    clerk.executeForm(pardon);
    president.executeForm(pardon);

    return (0);
}
