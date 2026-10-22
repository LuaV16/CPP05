#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
    public:
        AForm();
        AForm(const std::string name, const int req_sign, const int req_exec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };

        std::string getName() const;
        bool getIs_signed() const;
        int getReq_sign() const;
        int getReq_exec() const;

        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(const Bureaucrat& bureaucrat) const = 0;
    private:
        const std::string name;
        bool is_signed;
        const int req_sign;
        const int req_exec;
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif