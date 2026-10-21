/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 11:43:34 by lvargas-          #+#    #+#             */
/*   Updated: 2026/09/16 12:56:41 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("Unnamed"), is_signed(false), req_sign(100), req_exec(150)
{
    std::cout << "AForm default constructor called." << std::endl;
}

AForm::AForm(const std::string name, const int req_sign, const int req_exec) 
    : name(name), is_signed(false), req_sign(req_sign), req_exec(req_exec)
{
    if (req_sign < 1 || req_exec < 1)
        throw GradeTooHighException();
    if (req_sign > 150 || req_exec > 150)
        throw GradeTooLowException();

    std::cout << "AForm constructor called." << std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), is_signed(other.is_signed), req_sign(other.req_sign), req_exec(other.req_exec)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->is_signed = other.is_signed;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::string AForm::getName() const
{
    return(name);
}

bool AForm::getIs_signed() const
{
    return(is_signed);
}

int AForm::getReq_sign() const
{
    return(req_sign);
}

int AForm::getReq_exec() const
{
    return(req_exec);
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form: " << form.getName() << std::endl << "Is signed: " << form.getIs_signed() << std::endl
       << "Grade required to sign the form: " << form.getReq_sign() << std::endl 
       << "Grade required to execute the form: " << form.getReq_exec() << std::endl;
    return os;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (getIs_signed() == true)
        return ;
    if (bureaucrat.getGrade() <= getReq_sign())
        is_signed = true;
    else
        throw GradeTooLowException();
}
