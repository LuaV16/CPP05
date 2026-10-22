#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>
# include <iostream>

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;

private:
    std::string target;
};

#endif