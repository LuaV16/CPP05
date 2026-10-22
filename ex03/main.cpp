#include "Intern.hpp"

static void testForm(Intern& intern, const std::string& name,
                     const std::string& target)
{
    AForm* form = intern.makeForm(name, target);

    if (form != NULL)
    {
        std::cout << "Created form: " << form->getName() << std::endl;
        delete form;
    }
    else
        std::cout << "No form was created." << std::endl;
}

int main()
{
    Intern intern;

    std::cout << "\nValid forms" << std::endl;
    testForm(intern, "shrubbery creation", "garden");
    testForm(intern, "robotomy request", "Bender");
    testForm(intern, "presidential pardon", "Arthur Dent");

    std::cout << "\nInvalid form" << std::endl;
    testForm(intern, "coffee request", "Bender");

    return 0;
}
