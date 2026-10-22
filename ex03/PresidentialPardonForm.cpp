#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default_target") 
{
    std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) 
{
    std::cout << "PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)
{
    std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!getIs_signed())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getReq_exec())
        throw AForm::GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
