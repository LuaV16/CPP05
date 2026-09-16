#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form {
    public:
        Form();
        Form(const std::string name, const int req_sign, const int req_exec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        std::string getName() const;
        bool getIs_signed() const;
        int getReq_sign() const;
        int getReq_exec() const;

        void beSigned(const Bureaucrat& bureaucrat);
    private:
        const std::string name;
        bool is_signed;
        const int req_sign;
        const int req_exec;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif