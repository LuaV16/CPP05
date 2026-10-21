#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default_target") 
{
    std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) 
{
    std::cout << "RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
    std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getIs_signed())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getReq_exec())
        throw AForm::GradeTooLowException();

    std::cout << "Drilling noises..." << std::endl;

    if (rand() % 2)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "." << std::endl;
}
